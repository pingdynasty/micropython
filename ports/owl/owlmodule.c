#include <owlmodule.h>
#include <OpenWareMidiControl.h>

// Define a Python reference to the function we'll make available.
// See example.cpp for the definition.
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(button_obj, 1, 2, owl_button);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(parameter_obj, 1, 2, owl_parameter);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(input_obj, owl_input);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(output_obj, owl_output);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(plot_obj, 2, 3, owl_plot);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(print_obj, 1, 3, owl_print);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(draw_obj, 2, 5, owl_draw);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(clear_obj, owl_clear);

#define OWL_SAMPLE_RATE 48000
#define OWL_BLOCK_RATE 750
#define OWL_BLOCK_SIZE 64
#define OWL_CHANNELS 2
/* import owl */
/* setattr(owl, 'SR', 48000) */
/* setattr(owl, 'BS', 64) */
/* setattr(owl, 'BR', 48000/64) */
   
// Define all properties of the module.
// Table entries are key/value pairs of the attribute name (a string)
// and the MicroPython object reference.
// All identifiers and strings are written as MP_QSTR_xxx and will be
// optimized to word-sized integers by the build system (interned strings).
STATIC const mp_rom_map_elem_t owl_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_owl) },
    { MP_ROM_QSTR(MP_QSTR_B1), MP_ROM_INT(BUTTON_1) },
    { MP_ROM_QSTR(MP_QSTR_B2), MP_ROM_INT(BUTTON_2) },
    { MP_ROM_QSTR(MP_QSTR_B3), MP_ROM_INT(BUTTON_3) },
    { MP_ROM_QSTR(MP_QSTR_B4), MP_ROM_INT(BUTTON_4) },
    { MP_ROM_QSTR(MP_QSTR_B5), MP_ROM_INT(BUTTON_5) },
    { MP_ROM_QSTR(MP_QSTR_B6), MP_ROM_INT(BUTTON_6) },
    { MP_ROM_QSTR(MP_QSTR_B7), MP_ROM_INT(BUTTON_7) },
    { MP_ROM_QSTR(MP_QSTR_B8), MP_ROM_INT(BUTTON_8) },
    { MP_ROM_QSTR(MP_QSTR_A), MP_ROM_INT(PARAMETER_A) },
    { MP_ROM_QSTR(MP_QSTR_B), MP_ROM_INT(PARAMETER_B) },
    { MP_ROM_QSTR(MP_QSTR_C), MP_ROM_INT(PARAMETER_C) },
    { MP_ROM_QSTR(MP_QSTR_D), MP_ROM_INT(PARAMETER_D) },
    { MP_ROM_QSTR(MP_QSTR_E), MP_ROM_INT(PARAMETER_E) },
    { MP_ROM_QSTR(MP_QSTR_F), MP_ROM_INT(PARAMETER_F) },
    { MP_ROM_QSTR(MP_QSTR_G), MP_ROM_INT(PARAMETER_G) },
    { MP_ROM_QSTR(MP_QSTR_H), MP_ROM_INT(PARAMETER_H) },
    { MP_ROM_QSTR(MP_QSTR_AA), MP_ROM_INT(PARAMETER_AA) },
    { MP_ROM_QSTR(MP_QSTR_AB), MP_ROM_INT(PARAMETER_AB) },
    { MP_ROM_QSTR(MP_QSTR_AC), MP_ROM_INT(PARAMETER_AC) },
    { MP_ROM_QSTR(MP_QSTR_AD), MP_ROM_INT(PARAMETER_AD) },
    { MP_ROM_QSTR(MP_QSTR_AE), MP_ROM_INT(PARAMETER_AE) },
    { MP_ROM_QSTR(MP_QSTR_AF), MP_ROM_INT(PARAMETER_AF) },
    { MP_ROM_QSTR(MP_QSTR_AG), MP_ROM_INT(PARAMETER_AG) },
    { MP_ROM_QSTR(MP_QSTR_AH), MP_ROM_INT(PARAMETER_AH) },
    { MP_ROM_QSTR(MP_QSTR_BA), MP_ROM_INT(PARAMETER_BA) },
    { MP_ROM_QSTR(MP_QSTR_BB), MP_ROM_INT(PARAMETER_BB) },
    { MP_ROM_QSTR(MP_QSTR_BC), MP_ROM_INT(PARAMETER_BC) },
    { MP_ROM_QSTR(MP_QSTR_BD), MP_ROM_INT(PARAMETER_BD) },
    { MP_ROM_QSTR(MP_QSTR_BE), MP_ROM_INT(PARAMETER_BE) },
    { MP_ROM_QSTR(MP_QSTR_BF), MP_ROM_INT(PARAMETER_BF) },
    { MP_ROM_QSTR(MP_QSTR_BG), MP_ROM_INT(PARAMETER_BG) },
    { MP_ROM_QSTR(MP_QSTR_BH), MP_ROM_INT(PARAMETER_BH) },
    { MP_ROM_QSTR(MP_QSTR_CA), MP_ROM_INT(PARAMETER_CA) },
    { MP_ROM_QSTR(MP_QSTR_CB), MP_ROM_INT(PARAMETER_CB) },
    { MP_ROM_QSTR(MP_QSTR_CC), MP_ROM_INT(PARAMETER_CC) },
    { MP_ROM_QSTR(MP_QSTR_CD), MP_ROM_INT(PARAMETER_CD) },
    { MP_ROM_QSTR(MP_QSTR_CE), MP_ROM_INT(PARAMETER_CE) },
    { MP_ROM_QSTR(MP_QSTR_CF), MP_ROM_INT(PARAMETER_CF) },
    { MP_ROM_QSTR(MP_QSTR_CG), MP_ROM_INT(PARAMETER_CG) },
    { MP_ROM_QSTR(MP_QSTR_CH), MP_ROM_INT(PARAMETER_CH) },
    { MP_ROM_QSTR(MP_QSTR_DA), MP_ROM_INT(PARAMETER_DA) },
    { MP_ROM_QSTR(MP_QSTR_DB), MP_ROM_INT(PARAMETER_DB) },
    { MP_ROM_QSTR(MP_QSTR_DC), MP_ROM_INT(PARAMETER_DC) },
    { MP_ROM_QSTR(MP_QSTR_DD), MP_ROM_INT(PARAMETER_DD) },
    { MP_ROM_QSTR(MP_QSTR_DE), MP_ROM_INT(PARAMETER_DE) },
    { MP_ROM_QSTR(MP_QSTR_DF), MP_ROM_INT(PARAMETER_DF) },
    { MP_ROM_QSTR(MP_QSTR_DG), MP_ROM_INT(PARAMETER_DG) },
    { MP_ROM_QSTR(MP_QSTR_DH), MP_ROM_INT(PARAMETER_DH) },
    { MP_ROM_QSTR(MP_QSTR_SR), MP_ROM_INT(OWL_SAMPLE_RATE) },
    { MP_ROM_QSTR(MP_QSTR_BR), MP_ROM_INT(OWL_BLOCK_RATE) },
    { MP_ROM_QSTR(MP_QSTR_BS), MP_ROM_INT(OWL_BLOCK_SIZE) },
    { MP_ROM_QSTR(MP_QSTR_ch), MP_ROM_INT(OWL_CHANNELS) },
    { MP_ROM_QSTR(MP_QSTR_button), MP_ROM_PTR(&button_obj) },
    { MP_ROM_QSTR(MP_QSTR_parameter), MP_ROM_PTR(&parameter_obj) },
    { MP_ROM_QSTR(MP_QSTR_input), MP_ROM_PTR(&input_obj) },
    { MP_ROM_QSTR(MP_QSTR_output), MP_ROM_PTR(&output_obj) },
    { MP_ROM_QSTR(MP_QSTR_plot), MP_ROM_PTR(&plot_obj) },
    { MP_ROM_QSTR(MP_QSTR_print), MP_ROM_PTR(&print_obj) },
    { MP_ROM_QSTR(MP_QSTR_draw), MP_ROM_PTR(&draw_obj) },
    { MP_ROM_QSTR(MP_QSTR_clear), MP_ROM_PTR(&clear_obj) },
};
STATIC MP_DEFINE_CONST_DICT(owl_module_globals, owl_module_globals_table);

// Define module object.
const mp_obj_module_t owl_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&owl_module_globals,
};

// Register the module to make it available in Python.
// Note: the "1" in the third argument means this module is always enabled.
// This "1" can be optionally replaced with a macro like MODULE_CPPEXAMPLE_ENABLED
// which can then be used to conditionally enable this module.
MP_REGISTER_MODULE(MP_QSTR_owl, owl_user_cmodule, 1);
