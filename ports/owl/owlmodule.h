#ifndef __OWLMODULE_H
#define __OWLMODULE_H

#ifdef __cplusplus
 extern "C" {
#endif

// Include MicroPython API.
#include "py/runtime.h"

   extern mp_obj_t owl_getButton(mp_obj_t a_obj);
   extern mp_obj_t owl_getParameter(mp_obj_t a_obj);
   extern mp_obj_t owl_setButton(mp_obj_t a_obj, mp_obj_t b_obj);
   extern mp_obj_t owl_setParameter(mp_obj_t a_obj, mp_obj_t b_obj);
   extern mp_obj_t owl_setOutput(mp_obj_t a_obj, mp_obj_t b_obj); // value can be bool, int, float or iterator

   extern mp_obj_t owl_print(mp_obj_t a_obj, mp_obj_t b_obj, mp_obj_t c_obj);
   extern mp_obj_t owl_draw(size_t n_args, const mp_obj_t *args);
   extern mp_obj_t owl_clear();

   /* todo: */
   /* extern mp_obj_t getSampleRate(); */
   /* extern mp_obj_t getBlockSize(); */
   /* extern mp_obj_t getNumberOfChannels(); */
   /* extern mp_obj_t getInput(mp_obj_t a_obj); // returns iterator ? better to register a class instance? */

   /* void doSetOutputIterator(uint8_t ch, mp_obj_t iterator); */

#ifdef __cplusplus
}
#endif

#endif /* __OWLMODULE_H */
