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
#include "param.h"
#include "common.h"
#include "strings.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void OutputSymbol(int sym, FILE *OUT, int out)
  {
  if(out == 0) fprintf(stdout, "%c", sym);
  else         fprintf(OUT, "%c", sym);

  return;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void OutputBase(int sym, FILE *OUT, int out, uint64_t idx, uint64_t ls)
  {

  if(out == 0)
    {
    fprintf(stdout, "%c", sym);
    if(idx % ls == 0) fprintf(stdout, "\n");
    }
  else
    {
    fprintf(OUT, "%c", sym);
    if(idx % ls == 0) fprintf(OUT, "\n");
    }

  return;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

uint64_t OutputViralSeq(FILE *OUT, int out, FILE *FV, uint64_t init, 
uint64_t end, uint64_t pos, uint64_t ls)
  {
  int sym;
  uint64_t position = 1;
  
  while((sym = getc(FV)) != EOF)
    {
    if(sym == '>') // HEADER FOUND!
      while((sym = fgetc(FV)) != EOF && sym != '\n')
        ;
    if(sym == EOF ) { break;    }
    if(sym == '\n') { continue; }

    if(position >= init && position <= end)
      OutputBase(sym, OUT, out, pos, ls);

    ++pos;
    ++position;
    }

  return pos;
  }

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
  MAP->line_size  = ArgsNum(DEF_LINE_SIZE, p, c, "-l", "--line-size", 
		    10, 1000000);
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

  FH = Fopen(MAP->host,  "r");
  FV = Fopen(MAP->virus, "r");
 
  FILE *OUT = NULL;
  if(MAP->out == 1)
    OUT = Fopen(MAP->output, "w");

  int sym;
  uint64_t position = 1;
  while((sym = getc(FH)) != EOF)
    {
    if(sym == '>') // HEADER FOUND!
      {
      OutputSymbol(sym, OUT, MAP->out);
      while((sym = fgetc(FH)) != EOF && sym != '\n')
        OutputSymbol(sym, OUT, MAP->out);
      OutputSymbol(sym, OUT, MAP->out);
      continue;
      }
    if(sym == EOF ) { OutputSymbol(sym, OUT, MAP->out); break;    }
    if(sym == '\n') { continue; }

    if(position == MAP->host_pos)
      {
      position = OutputViralSeq(OUT, MAP->out, FV, MAP->virus_init, 
		 MAP->virus_end, position, MAP->line_size);
      }

    OutputBase(sym, OUT, MAP->out, position, MAP->line_size);
    ++position;
    }
  
  fclose(FH);
  if(MAP->out == 1) fclose(OUT);

  if(MAP->verbose) fprintf(stderr, "[>] Done!\n");

  return EXIT_SUCCESS;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
