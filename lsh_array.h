#ifndef lsh_array_h
#define lsh_array_h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include <lsh/lsh_types.h>

typedef struct _array Array;

Array* Array_Init(u16 el_size, u32 inc);

void Array_Add(Array *a, void *data);

void* Array_Get(Array *a, u32 idx);


// -----------------------------------------------------------

#ifdef LSH

struct _array {
  u32 length;
  u32 inc;
  u32 cap;
  u16 el_size;
  void* data;
};

Array* Array_Init(u16 el_size, u32 inc) {
  Array *a = malloc(sizeof(Array));
  a->el_size = el_size;
  a->inc = inc;
  a->cap = 0;
  a->length = 0;
  a->data = NULL;
  return a;
}

void Array_Add(Array *a, void *data) { 
  int len_old = a->length;
  a->length += 1;
  // CHECK INCREASE
  if (a->length > a->cap) {
    for (; a->length > a->cap; a->cap += a->inc);
    void *temp = realloc(a->data, a->cap * a->el_size);
    if (!temp) return;
    a->data = temp;
  }
  memcpy((char*) a->data + len_old * a->el_size, data, a->el_size);
}

void* Array_Get(Array *a, u32 idx) {
  return a->data + idx * a->el_size;
}

// void array_free(Array **a) {
//   free(*a->data);
//   a.data = NULL;
// }

#endif // LSH
#endif
