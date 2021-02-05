/*
 *  Reads a string from stdin and reverses word order
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN  256

void reverse_words(char *str);

int main(int argc, char **argv)
{
  static char s[MAXLEN];

  // read a string from stdin
  while(fgets(s, MAXLEN-1, stdin) != 0) {
    s[strlen(s)-1] = 0; // strip \n
    printf("%s <-> ", s);
    // reverse word order
    reverse_words(s);
    printf("%s\n", s);
  }
}

