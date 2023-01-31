#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED

#include <stdint.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <unistd.h>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// RUNNING COMPILATION PROPERTIES :: COMMENT OR UNCOMMENT 

#define PROGRESS // DISPLAY % OF PROGRESS

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef uint64_t U64;
typedef uint32_t U32;
typedef uint16_t U16;
typedef uint8_t  U8; 
typedef int64_t  I64;
typedef int32_t  I32;
typedef int16_t  I16;
typedef int8_t   I8;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define PNAME                  "SynTegra"
#define VERSION                1
#define RELEASE                1

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#ifndef M_LN2
#define M_LN2                  0.69314718
#endif

#ifndef M_PI
#define M_PI                   3.14159265
#endif

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define MAX_STR                2048
#define BUFFER_SIZE            65535    
#define PROGRESS_MIN           200
#define DEF_HELP               0
#define DEF_FORCE              0
#define DEF_VERBOSE            0
#define DEF_THREADS            1
#define BGUARD                 32
#define ALPHABET_SIZE          4
#define DEF_HOST_POS           0
#define DEF_VIRAL_INI          0
#define DEF_VIRAL_END          99999999
#define MIN_NPARAM_FOR_PROGS   2

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#endif

