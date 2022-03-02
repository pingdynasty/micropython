#ifndef __OWLMODULE_H
#define __OWLMODULE_H

#ifdef __cplusplus
extern "C" {
#endif

// Include MicroPython API.
#include "py/runtime.h"

extern mp_obj_t owl_button(size_t n_args, const mp_obj_t *args);    // get or set button value
extern mp_obj_t owl_parameter(size_t n_args, const mp_obj_t *args);    // get or set parameter value
extern mp_obj_t owl_output(mp_obj_t a_obj, mp_obj_t b_obj);    // value can be bool, int, float or iterator
extern mp_obj_t owl_input(mp_obj_t a_obj);    // get next audio sample

extern mp_obj_t owl_print(size_t n_args, const mp_obj_t *args);
extern mp_obj_t owl_plot(size_t n_args, const mp_obj_t *args);
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
