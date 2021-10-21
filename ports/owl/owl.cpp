#include <stdint.h>
#include "ProgramVector.h"

#include <owlmodule.h>

extern "C" {

  void doSetButton(uint8_t id, uint16_t value, uint16_t samples);
  void doSetPatchParameter(uint8_t id, int16_t value);
  void doSetOutput(uint8_t ch, mp_obj_t iterator);

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

  mp_obj_t getButton(mp_obj_t a_obj) {
    int bid = mp_obj_get_int(a_obj);
    return mp_obj_new_bool(doGetButton(bid));
  }

  mp_obj_t getParameter(mp_obj_t a_obj) {
    int pid = mp_obj_get_int(a_obj);
    return mp_obj_new_float(doGetParameterValue(pid));
  }
  
  mp_obj_t setParameter(mp_obj_t a_obj, mp_obj_t b_obj) {
    int pid = mp_obj_get_int(a_obj);
    float value = mp_obj_get_float(b_obj);
    doSetPatchParameter(pid, (uint16_t)(value*4095));
    return mp_const_none;
  }

  mp_obj_t setButton(mp_obj_t a_obj, mp_obj_t b_obj) {
    int bid = mp_obj_get_int(a_obj);
    if(bid == 0)
      bid = 1; // PUSHBUTTON
    else
      bid += 3; // offset to start at B1
    int value = mp_obj_get_int(b_obj);
    if(bid > 0 && bid < 16)
      doSetButton(bid, value == 0 ? 0 : 4095, 0);
    return mp_const_none;
  }

  mp_obj_t setOutput(mp_obj_t a_obj, mp_obj_t b_obj) {
    int ch = mp_obj_get_int(a_obj);
    doSetOutput(ch, b_obj);
    return mp_const_none;    
  }
}
