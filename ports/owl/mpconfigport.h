#include <stdint.h>

// options to control how MicroPython is built

// Use the minimal starting configuration (disables all optional features).
#define MICROPY_CONFIG_ROM_LEVEL (MICROPY_CONFIG_ROM_LEVEL_MINIMUM)

// You can disable the built-in MicroPython compiler by setting the following
// config option to 0.  If you do this then you won't get a REPL prompt, but you
// will still be able to execute pre-compiled scripts, compiled with mpy-cross.
#define MICROPY_ENABLE_COMPILER     (1)

/* #define MICROPY_QSTR_EXTRA_POOL           mp_qstr_frozen_const_pool */
#ifdef ARM_CORTEX
#define MICROPY_ENABLE_GC                 (1)
#else
#define MICROPY_ENABLE_GC                 (1)
#endif
#define MICROPY_HELPER_REPL               (1)
#define MICROPY_MODULE_FROZEN_MPY         (0)
#define MICROPY_ENABLE_EXTERNAL_IMPORT    (0)
#define MICROPY_PY_MATH                   (1)
#define MICROPY_PY_SYS_EXIT               (0)

#define MICROPY_ERROR_REPORTING           (MICROPY_ERROR_REPORTING_TERSE)
#define MICROPY_FLOAT_IMPL                (MICROPY_FLOAT_IMPL_FLOAT)

#define MICROPY_ALLOC_PATH_MAX            (256)
#define MICROPY_ALLOC_PARSE_CHUNK_INIT    (16)

#define MICROPY_COMP_CONST_FOLDING        (1)
#define MICROPY_COMP_CONST_LITERAL        (1)
#define MICROPY_FULL_CHECKS               (1)
#define MICROPY_MULTIPLE_INHERITANCE      (1)
#define MICROPY_PY_GENERATOR_PEND_THROW   (1)
#define MICROPY_PY_BUILTINS_RANGE_ATTRS   (1)

#define MICROPY_PY_ASYNC_AWAIT                  (0)
#define MICROPY_PY_BUILTINS_SET                 (0)
#define MICROPY_PY_ATTRTUPLE                    (0)
#define MICROPY_PY_COLLECTIONS                  (0)
#define MICROPY_PY_IO                           (0)
#define MICROPY_PY_STRUCT                       (0)

/* #define MICROPY_PY_GC_COLLECT_RETVAL (1) */
/* #if !(defined(MICROPY_GCREGS_SETJMP) || defined(__x86_64__) || defined(__i386__) || defined(__thumb2__) || defined(__thumb__) || defined(__arm__)) */
/* // Fall back to setjmp() implementation for discovery of GC pointers in registers. */
/* #define MICROPY_GCREGS_SETJMP (1) */
/* #endif */

// type definitions for the specific machine

typedef intptr_t mp_int_t; // must be pointer size
typedef uintptr_t mp_uint_t; // must be pointer size
typedef long mp_off_t;

// extra built in names to add to the global namespace
#define MICROPY_PORT_BUILTINS \
    { MP_ROM_QSTR(MP_QSTR_open), MP_ROM_PTR(&mp_builtin_open_obj) },

// We need to provide a declaration/definition of alloca()
#include <alloca.h>

#define MICROPY_HW_BOARD_NAME "owl"
#define MICROPY_HW_MCU_NAME "cortex-m4"

#ifdef __linux__
#define MICROPY_MIN_USE_STDOUT (1)
#endif

#ifdef __thumb__
#define MICROPY_MIN_USE_CORTEX_CPU (1)
#define MICROPY_MIN_USE_STM32_MCU (1)
#endif

#define MP_STATE_PORT MP_STATE_VM

#define MICROPY_PORT_ROOT_POINTERS \
    const char *readline_hist[8];
