#include <owlmodule.h>

// Define a Python reference to the function we'll make available.
// See example.cpp for the definition.
STATIC MP_DEFINE_CONST_FUN_OBJ_1(getButton_obj, owl_getButton);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(getParameter_obj, owl_getParameter);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(setButton_obj, owl_setButton);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(setParameter_obj, owl_setParameter);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(setOutput_obj, owl_setOutput);
STATIC MP_DEFINE_CONST_FUN_OBJ_3(print_obj, owl_print);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(draw_obj, 2, 5, owl_draw);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(clear_obj, owl_clear);

// Define all properties of the module.
// Table entries are key/value pairs of the attribute name (a string)
// and the MicroPython object reference.
// All identifiers and strings are written as MP_QSTR_xxx and will be
// optimized to word-sized integers by the build system (interned strings).
STATIC const mp_rom_map_elem_t owl_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_owl) },
    { MP_ROM_QSTR(MP_QSTR_getButton), MP_ROM_PTR(&getButton_obj) },
    { MP_ROM_QSTR(MP_QSTR_getParameter), MP_ROM_PTR(&getParameter_obj) },
    { MP_ROM_QSTR(MP_QSTR_setButton), MP_ROM_PTR(&setButton_obj) },
    { MP_ROM_QSTR(MP_QSTR_setParameter), MP_ROM_PTR(&setParameter_obj) },
    { MP_ROM_QSTR(MP_QSTR_setOutput), MP_ROM_PTR(&setOutput_obj) },
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
