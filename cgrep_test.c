/*
 *  Reads an array of strings from stdin
 *  and runs context grep
 *
 *  Uses malloc().
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void context_grep(int argc, char **argv, int context, char *str);

#define MAXLINES 256*1024   // Max # of lines
#define MAXLEN  256         // Max line length

char usage[]="Usage: %s <# of context lines> <string>\n";

int
main(int argc, char **argv)
{
  char **lines;   
  char *s;
  int i;

  if (argc < 3) {
    printf(usage, argv[0]);
    exit(1);
  }

  lines = malloc(MAXLINES * sizeof(char *));
  s = malloc(MAXLEN);

  // Read string array from stdin
  for (i=0; ; ++i) {
    if (fgets(s, MAXLEN-1, stdin) != 0) {
      s[strlen(s)-1] = 0; // Strip \n
      lines[i] = malloc(strlen(s) + 1);
      strcpy(lines[i], s);
    } else
      break;
  }

  lines[2] = 0;
  lines[34] = 0;
  lines[66] = 0;
  lines[124] = 0;

  // Run context grep
  context_grep(i, lines, strtol(argv[1], 0, 0), argv[2]);

  return 0;
}

  
 
