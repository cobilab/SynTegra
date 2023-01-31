#ifndef PARAM_H_INCLUDED
#define PARAM_H_INCLUDED

#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#include "defs.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef struct
  {
  U32       help;
  U32       force;
  U32       verbose;
  U32       out;
  U64       line_size;
  U64       seed;
  U64       host_pos;
  U64       host_len;
  U64       virus_init;
  U64       virus_end;
  U64       virus_len;
  char      *output;
  char      *virus;
  char      *host;
  }
PARAMETERS;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

uint64_t    ArgsNum            (uint64_t , char *[], uint32_t, char *, char *,
                               uint64_t, uint64_t);
double      ArgsDouble         (double, char *[], uint32_t, char *, char *);
uint8_t     ArgsState          (uint8_t, char *[], uint32_t, char *, char *);
char        *ArgsString        (char *, char *[], uint32_t, char *, char *);
char        *ArgsFiles         (char *[], uint32_t, char *);
void        PrintParameters    (PARAMETERS *);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#endif
