#include <stdio.h>
#include <stdlib.h>

#include "msg.h"
#include "colors.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void PrintError(char *s)
  {
  fprintf(stderr, "%s[x] Error: %s%s\n", error_color, s, normal_color);
  exit(1);
  return;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void PrintWarning(char *s)
  {
  fprintf(stderr, "%s[w] Warning: %s%s\n", warning_color, s, normal_color);
  return;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void PrintMessage(char *s)
  {
  fprintf(stderr, "%s[>] %s%s\n", normal_color, s, normal_color);
  return;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void PrintVersion(void)
  {
  fprintf(stdout, "v%u.%u\n", VERSION, RELEASE);
  return;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void PrintMenu(void)
  {
  fprintf(stderr,
  "                                                                 \n"
  "%s v%u.%u                          \n"
  "                                                                 \n"
  "DESCRIPTION                                                      \n"
  "      Simulation of viral-host synthetic integrations.           \n"
  "                                                                 \n"
  "PARAMETERS                                                       \n"
  "                                                                 \n"
  "      -h,  --help                                                \n"
  "           usage guide (help menu),                              \n"
  "                                                                 \n"
  "      -v,  --verbose                                             \n"
  "           verbose mode (more information),                      \n"
  "                                                                 \n"
  "      -s [INT],  --seed [INT]                                    \n"
  "           seed for random simulation of position,               \n"
  "                                                                 \n"
  "      -p [INT],  --host-position [INT]                           \n"
  "           host integration position (default: random),          \n"
  "                                                                 \n"
  "      -i [INT],  --viral-init-position [INT]                     \n"
  "           viral starting position (default: first position),    \n"
  "                                                                 \n"
  "      -e [INT],  --viral-end-position [INT]                      \n"
  "           viral ending position (default: last position),       \n"
  "                                                                 \n"
  "      -o [STRING],  --output [STRING]                            \n"
  "           integrated output filename (default to stdout),       \n"
  "                                                                 \n"
  "      [FILE]                                                     \n"
  "           input viral genome filename -- MANDATORY,             \n"
  "           FASTA file with the viral sequence (last argument).   \n"
  "                                                                 \n"
  "      [FILE]                                                     \n"
  "           input host genome filename -- MANDATORY,              \n"
  "           FASTA file for the integration (last argument).       \n"
  "                                                                 \n"
  "SYNOPSIS                                                         \n"
  "      %s [OPTION]... [FILE] [FILE]                  \n"
  "                                                                 \n"
  "EXAMPLE                                                          \n"
  "      %s -v virus.fa host.fa                        \n"
  "                                                                 \n",
  PNAME, VERSION, RELEASE, PNAME, PNAME);
  return;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
