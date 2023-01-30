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

uint32_t ArgsNum(uint32_t d, char *a[], uint32_t n, char *s, char *s2,
uint32_t l, uint32_t u)
  {
  uint32_t x;
  for( ; --n ; ) if(!strcmp(s, a[n]) || !strcmp(s2, a[n]))
    {
    if((x = atol(a[n+1])) < l || x > u)
      {
      fprintf(stderr, "[x] Invalid number! Interval: [%u;%u].\n", l, u);
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
  
  return;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
