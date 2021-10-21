#ifndef __OWLMODULE_H
#define __OWLMODULE_H

#ifdef __cplusplus
 extern "C" {
#endif

// Include MicroPython API.
#include "py/runtime.h"

   extern mp_obj_t getButton(mp_obj_t a_obj);
   extern mp_obj_t getParameter(mp_obj_t a_obj);
   extern mp_obj_t setButton(mp_obj_t a_obj, mp_obj_t b_obj);
   extern mp_obj_t setParameter(mp_obj_t a_obj, mp_obj_t b_obj);
   extern mp_obj_t setOutput(mp_obj_t a_obj, mp_obj_t b_obj);

#ifdef __cplusplus
}
#endif

#endif /* __OWLMODULE_H */
