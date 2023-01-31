#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <unistd.h>

#include "mem.h"
#include "common.h"
#include "param.h"
#include "msg.h"
#include "dna.h"
#include "strings.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

uint64_t ArgsNum(uint64_t d, char *a[], uint32_t n, char *s, char *s2,
uint64_t l, uint64_t u)
  {
  uint64_t x;
  for( ; --n ; ) if(!strcmp(s, a[n]) || !strcmp(s2, a[n]))
    {
    if((x = atol(a[n+1])) < l || x > u)
      {
      fprintf(stderr, "[x] Invalid number! Interval: [%"PRIu64";%"PRIu64"].\n", 
      l, u);
      exit(EXIT_FAILURE);
      }
    return x;
    }
  return d;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

double ArgsDouble(double d, char *a[], uint32_t n, char *s, char *s2)
  {
  for( ; --n ; )
    if(!strcmp(s, a[n]) || !strcmp(s2, a[n]))
      return atof(a[n+1]);
  return d;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

uint8_t ArgsState(uint8_t d, char *a[], uint32_t n, char *s, char *s2)
  {
  for( ; --n ; )
    if(!strcmp(s, a[n]) || !strcmp(s2, a[n]))
      return d == 0 ? 1 : 0;
  return d;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char *ArgsString(char *d, char *a[], uint32_t n, char *s, char *s2)
  {
  for( ; --n ; )
    if(!strcmp(s, a[n]) || !strcmp(s2, a[n]))
      {
      if(a[n+1] == NULL || strlen(a[n+1]) < 1)
        {
        PrintWarning("string is empty!");
	exit(1);
        }
      return a[n+1];
      }
  return d;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char *ArgsFiles(char *arg[], uint32_t argc, char *str)
  {
  int32_t n = argc;

  for( ; --n ; )
    if(!strcmp(str, arg[n]))
      return CloneString(arg[n+1]);

  return Cat(Cat(arg[argc-2], arg[argc-1]), ".st");
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void PrintParameters(PARAMETERS *M)
  {
  uint32_t n;

  fprintf(stderr, "[>] Verbose mode ................... %s\n", M->verbose == 0 ? 
  "no" : "yes");
  fprintf(stderr, "[>] Line size for output ........... %"PRIu64"\n", 
  M->line_size);
  fprintf(stderr, "[>] Seed ........................... %"PRIu64"\n", M->seed);
  fprintf(stderr, "[>] Host length .................... %"PRIu64"\n", 
  M->host_len); 
  fprintf(stderr, "[>] Virus length ................... %"PRIu64"\n", 
  M->virus_len); 
  fprintf(stderr, "[>] Host integration position ...... %"PRIu64"\n", 
  M->host_pos);
  fprintf(stderr, "[>] Viral initial position ......... %"PRIu64"\n", 
  M->virus_init); 
  fprintf(stderr, "[>] Viral ending position .......... %"PRIu64"\n", 
  M->virus_end); 
  if(M->out == 1)
    fprintf(stderr, "[>] Integration output ............. %s\n", M->output);
  else
    fprintf(stderr, "[>] Integration output ............. (to stdout)\n");
  fprintf(stderr, "[>] Virus filename ................. %s\n", M->virus);
  fprintf(stderr, "[>] Host filename .................. %s\n", M->host);

  return;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
