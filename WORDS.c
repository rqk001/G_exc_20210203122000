#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//
//  void reverse_words(char *str);
//
//  Reverses word order in the string. In place.
//

#define SPACES " \t"  // All characters treated as word delimiters

// Reversing string between s and e, inclusive
static void
reverse_substr(char *s, char *e)
{
  char    tmp;

  while(s < e) {
    // swap(s++, e--);
    tmp = *s; *s++ = *e; *e-- = tmp;
  }
}

// Reversing word order in a string
void
reverse_words(char *str)
{
  char *s=str, *del;
  int d;

  // null and empty strings
  if (s == 0  || s[0] == 0)
    return;

  // find a word delimiter
  while((d = strcspn(s, SPACES)) != 0) {
    // reverse found word
    reverse_substr(s, s+d-1);
    while (s[d] != 0  &&  strchr(SPACES, s[d]) != 0) // find nonspace
      ++d;
    s += d;;
  }

  // reverse the whole string
  reverse_substr(str, str+strlen(str)-1);
}

