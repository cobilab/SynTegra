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
  U64       host_init;
  U64       virus_init;
  U64       virus_end;
  char      *virus;
  char      *host;
  }
PARAMETERS;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

uint32_t    ArgsNum            (uint32_t , char *[], uint32_t, char *, char *,
                               uint32_t, uint32_t);
double      ArgsDouble         (double, char *[], uint32_t, char *, char *);
uint8_t     ArgsState          (uint8_t, char *[], uint32_t, char *, char *);
char        *ArgsString        (char *, char *[], uint32_t, char *, char *);
char        *ArgsFiles         (char *[], uint32_t, char *);
void        PrintParameters    (PARAMETERS *);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#endif
