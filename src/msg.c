#include <stdio.h>
#include <stdlib.h>

#include "msg.h"
#include "colors.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void PrintWarning(char *s)
  {
  fprintf(stderr, "%s[x] Error: %s%s\n", error_color, s, normal_color);
  exit(1);
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
  "SynTegra  v%u.%u                                    \n"
  "                                                                    \n"
  "DESCRIPTION                                                         \n"
  "      Simulation of viral-host synthetic integrations.              \n"
  "                                                                    \n"
  "PARAMETERS                                                          \n"
  "                                                                    \n"
  "      -h,  --help                                                   \n"
  "           usage guide (help menu),                                 \n"
  "                                                                    \n"
  "      -v,  --verbose                                                \n"
  "           verbose mode (more information),                         \n"
  "                                                                    \n"
  "      -hp [INT],  --host-position [INT]                             \n"
  "           host integration position (default: random),             \n"
  "                                                                    \n"
  "      -vs [INT],  --viral-start-position [INT]                      \n"
  "           viral starting position (default: first position),       \n"
  "                                                                    \n"
  "      -ve [INT],  --viral-end-position [INT]                        \n"
  "           viral ending position (default: last position),          \n"
  "                                                                    \n"
  "      -ih [STRING],  --host [STRING]                                \n"
  "           input host genome filename (MANDATORY argument),         \n"
  "                                                                    \n"
  "      -iv [STRING],  --virus [STRING]                               \n"
  "           input virus genome filename (MANDATORY argument).        \n"
  "                                                                    \n"
  "SYNOPSIS                                                            \n"
  "      %s [OPTION]... --virus [FILE] --host [FILE]   \n"
  "                                                                    \n"
  "EXAMPLE                                                             \n"
  "      %s -v --virus virus.fa --host host.fa         \n"
  "                                                                    \n",
  VERSION, RELEASE, PNAME, PNAME);
  return;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
