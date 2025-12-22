#ifndef lsh_string_h
#define lsh_string_h

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define padding 10
typedef uint16_t u16;

typedef struct {
  u16 len;
  u16 cap;
  char *buf;
} String;

void string_init(String *string, char *initial);
void string_print(String *s);

//-------------------------------------------------

#ifdef LSH

void string_init(String *string, char *initial) {
  string->buf = NULL;
  string->len = 0;
  for (char *c = initial; *c; c++) {
    string->len++;
  }
  string->cap = string->len + padding;
  string->buf = malloc(string->cap * sizeof(char));
  if (!string->buf)
    exit(1);
  for (u16 i = 0; i < string->len; i++) {
    string->buf[i] = initial[i];
  }
}

void string_print(String *s) {
  for (int i = 0; i < s->len; i++) {
    printf("%c", s->buf[i]);
  }
}

#endif // lsh_string_imp
#endif // lsh_string_h
