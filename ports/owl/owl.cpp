#include <stdint.h>
#include "basicmaths.h"
#include "ProgramVector.h"

#include <owlmodule.h>

extern "C" {

  void doSetButton(uint8_t id, uint16_t value, uint16_t samples);
  void doSetPatchParameter(uint8_t id, int16_t value);
  void doSetOutputIterator(uint8_t ch, mp_obj_t iterator);
  void doSetParameterIterator(uint8_t id, mp_obj_t iterator);
  void doScreenPrint(int x, int y, const char* text);
  void doScreenDraw(int x0, int y0, int x1, int y1, int c);	      
  void doScreenClear();

  // implicit conversion of float to int
  int getInt(mp_obj_t arg){
    if(mp_obj_is_float(arg))
      return (int)mp_obj_float_get(arg);
    else
      return mp_obj_get_int(arg);
  }
  
  float doGetParameterValue(uint8_t pid){
    if(pid < getProgramVector()->parameters_size){
      if(getProgramVector()->hardware_version == OWL_MODULAR_HARDWARE && pid < 4){
	return (4095 - getProgramVector()->parameters[pid])/4096.0f;
      }else{
	return getProgramVector()->parameters[pid]/4096.0f;
      }
    }
    return 0.0f;
  }

  bool doGetButton(uint8_t bid){
    return getProgramVector()->buttons & (1<<bid);
  }
  
  mp_obj_t owl_parameter(size_t n_args, const mp_obj_t *args) {
    int pid = mp_obj_get_int(args[0]);
    if(n_args == 2){ // set value
      mp_obj_t b_obj = args[1];
      if(mp_obj_is_float(b_obj)){
	float value = mp_obj_get_float(b_obj);
	doSetPatchParameter(pid, (uint16_t)(value*4095));
      }else if(mp_obj_is_integer(b_obj)){
	int value = mp_obj_get_int(b_obj);
	doSetPatchParameter(pid, value);
      }else{
	doSetParameterIterator(pid, b_obj);
      }
      return mp_const_none;
    }else{ // get value
      return mp_obj_new_float(doGetParameterValue(pid));
    }
  }

  mp_obj_t owl_button(size_t n_args, const mp_obj_t *args) {
    int bid = mp_obj_get_int(args[0]);
    if(bid == 0)
      bid = 1; // PUSHBUTTON
    else
      bid += 3; // offset to start at B1
    if(n_args == 2){ // set value
      int value = getInt(args[1]);
      // if(bid > 0 && bid < 16)
      doSetButton(bid, value == 0 ? 0 : 4095, 0);
      return mp_const_none;
    }else{ // get value
      return mp_obj_new_bool(doGetButton(bid));
    }
  }

  mp_obj_t owl_output(mp_obj_t a_obj, mp_obj_t b_obj) {
    int ch = mp_obj_get_int(a_obj);
    doSetOutputIterator(ch, b_obj);
    return mp_const_none;    
  }

  /**
   * invoked as one of:
   * print(str, x, y)
   * print(str, y)
   * print(str)
   */  
  mp_obj_t owl_print(size_t n_args, const mp_obj_t *args){
    int x = 0;
    int y = 0;
    const char* text = mp_obj_str_get_str(args[0]);
    if(n_args > 2){
      x = mp_obj_get_int(args[1]);
      y = mp_obj_get_int(args[2]);
    }else if(n_args > 1){
      y = mp_obj_get_int(args[1]);
    }
    doScreenPrint(x, y, text);
    return mp_const_none;    
  }

  mp_obj_t owl_draw(size_t n_args, const mp_obj_t *args) {
    size_t idx = 0;
    int x0 = getInt(args[idx++]);
    int y0 = getInt(args[idx++]);
    int c = 1;
    int x1 = x0;
    int y1 = y0;
    if(n_args > 3){
      x1 = getInt(args[idx++]);
      y1 = getInt(args[idx++]);
    }
    if(n_args > idx)
      c = getInt(args[idx]);
    doScreenDraw(x0, y0, x1, y1, c);
    return mp_const_none;
  }

  mp_obj_t owl_clear(){
    doScreenClear();
    return mp_const_none;
  }
}
