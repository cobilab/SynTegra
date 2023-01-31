#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <time.h>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#include "defs.h"
#include "msg.h"
#include "mem.h"
#include "dna.h"
#include "rand.h"
#include "param.h"
#include "common.h"
#include "strings.h"

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

  MAP->help       = ArgsState(DEF_HELP, p, c, "-h",  "--help");
  MAP->verbose    = ArgsState(DEF_VERBOSE, p, c, "-v",  "--verbose");
  MAP->seed       = ArgsNum(time(NULL), p, c, "-s", "--seed", 
		    0, 9999999999);
  MAP->host_pos   = ArgsNum(DEF_HOST_POS, p, c, "-p", "--host-position",
                    0, 9999999999);
  MAP->virus_init = ArgsNum(DEF_VIRAL_INI, p, c, "-i", "--viral-init-position", 
		    0, 9999999999);
  MAP->virus_end  = ArgsNum(DEF_VIRAL_END, p, c, "-e", "--viral-end-position",
                    0, 9999999999);

  MAP->virus = p[c-2];
  CheckFileEmpty(MAP->virus);

  MAP->host = p[c-1];
  CheckFileEmpty(MAP->host);

  int n;
  MAP->out = 0;
  for(n = 1 ; n < c ; ++n)
    if(strcmp(p[n], "-o") == 0 || strcmp(p[n], "--output") == 0)
      {
      MAP->output = CloneString(p[n+1]);
      MAP->out = 1;
      break;
      }
  if(MAP->out == 0)
    MAP->output = CloneString(Cat("integrated-", MAP->host));

  if(MAP->verbose) fprintf(stderr, "[>] Starting %s ...\n", PNAME);
  
  FILE *FV = Fopen(MAP->virus, "r");
  FILE *FH = Fopen(MAP->host,  "r");
  MAP->virus_len = NSymInFasta(FV);
  MAP->host_len  = NSymInFasta(FH);
  fclose(FV);
  fclose(FH);

  srand(MAP->seed);
  if(MAP->host_pos == 0)
    MAP->host_pos = rand() % MAP->host_len;
  
  if(MAP->virus_end > MAP->virus_len)
    {
    MAP->virus_end = MAP->virus_len;
    PrintWarning("Virus end position has been adjusted to the length");
    }

  if(MAP->verbose) PrintParameters(MAP);

  if(MAP->verbose) fprintf(stderr, "[>] Starting integration ...\n");

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
