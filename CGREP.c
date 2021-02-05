#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Runs context grep with <context> lines of leading and
// trailing context on an array of strings. Output to stdout
//

// Safeguard for puts(0), Some platforms have it built in, some don't
int
puts_null(char *s)
{
  if (s != 0)
    return puts(s);
  return puts("(null)");
}

void context_grep(int argc, char **argv, int context, char *expr)
{
  int   i, j;
  int   match = -context-1;   // Last match
  int   printed = -context-1; // Last printed

  // Sanity
  if (argc < 1 || argv == 0 || context < 0 || expr == 0)
    return; // error

  for (i=0; i<argc; ++i) {
    if (argv[i] == 0  || strstr(argv[i], expr) == 0) {   // No match
      if (i <= (match+context)) {  // Inside trailing context
        // Note that it's safe to puts(0), outputs `(null)'
        puts_null(argv[i]);
        printed = i;
      } else
        continue;
    } else {    // Match
      for (j=i-context; j<=i; ++j) { // Inside leading context
        if (j > printed) {
          puts_null(argv[j]);
          printed = j;
        }
      }
      match = i;
    }
  }
} 

