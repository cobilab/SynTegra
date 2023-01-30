#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#include "defs.h"
#include "msg.h"
#include "mem.h"
//#include "dna.h"
#include "param.h"
#include "common.h"
//#include "strings.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int32_t main(int c, char *argv[])
  {
  char **p = *&argv;

  if(ArgsState(0, p, c, "-V", "--version"))
    {
    PrintVersion();
    return EXIT_SUCCESS;
    }

  if(ArgsState(DEF_HELP, p, c, "-h", "--help") && c == 2 || c < 3)
    {
    PrintMenu();
    return EXIT_SUCCESS;
    }

  PARAMETERS *MAP = (PARAMETERS *) Calloc(1, sizeof(PARAMETERS));

  MAP->help        = ArgsState  (DEF_HELP,    p, c, "-h", "--help");
  MAP->verbose     = ArgsState  (DEF_VERBOSE, p, c, "-v", "--verbose");

  //MAP->filename = p[c-1];
  //CheckFileEmpty(MAP->filename);

  //if(MAP->verbose) PrintParameters(MAP);

  // PRINT HEADER
  // if(MAP->fasta) fprintf(stdout, ">Extracted sequence [%"PRIu64";%"PRIu64"]\n",
  //               MAP->init, MAP->end);

  //Extract(MAP);

  // PRINT TAIL
  fprintf(stdout, "\n");

  if(MAP->verbose) fprintf(stderr, "[>] Done!\n");


  


  return EXIT_SUCCESS;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
