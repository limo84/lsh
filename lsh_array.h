#ifndef lsh_array_h
#define lsh_array_h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include <lsh/lsh_types.h>

typedef struct _array Array;

Array *array_init(u16 el_size, u32 inc);

//void array_fill(Array *a, u32 length, void *data);

void array_add(Array *a, u32 length, void *data);

void *array_get(Array *a, u32 idx);


// -----------------------------------------------------------

#ifdef LSH

struct _array {
  u32 length;
  u32 inc;
  u32 cap;
  u16 el_size;
  void *data;
};

Array *Array_Init(u16 el_size, u32 inc) {
  Array *a = malloc(sizeof(Array));
  a->el_size = el_size;
  a->inc = inc;
  a->cap = 0;
  a->length = 0;
  return a;
}

// void array_free(Array **a) {
//   free(*a->data);
//   a.data = NULL;
// }

//void array_free(Array a) {
// free(a.data);
//  a.data = NULL;
//}


/*void array_fill(Array *a, u32 length, void *data) {
  a->data = malloc(a->cap * a->el_size); 
  a->length = length;
  // check increase
  if (a->length > a->cap) {
    for (; a->length > a->cap; a->cap += a->inc);
    a->data = realloc(a->data, a->cap * a->el_size);
  }
  memcpy(a->data, data, a->length * a->el_size);
}*/

void Array_Add(Array *a, void *data) { 
  int len_old = a->length;
  a->length += 1;
  // CHECK INCREASE
  if (a->length > a->cap) {
    for (; a->length > a->cap; a->cap += a->inc);
    a->data = realloc(a->data, a->cap * a->el_size);
  }
  memcpy(a->data + len_old * a->el_size, data, a->length * a->el_size);
}

void* array_get(Array *a, u32 idx) {
  return a->data + idx * a->el_size;
}

#endif // LSH
#endif
