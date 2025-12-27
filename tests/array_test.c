#define LSH

#include <lsh/lsh_array.h>
#include <stdio.h>

#define TESTSIZE 5

const int buffer_size = 12;
char test_buffer[TESTSIZE][12] = {"huhu1", "asdfghj", "m12345", "Lukas", "ACHTUNG!"};

int main() {
  printf("_____________________________________________________________________________\n");
  printf("__________________  ARRAY  __________________________________________________\n");
  printf("_____________________________________________________________________________\n");
  
  Array *strings = Array_Init(12, 1);
  
  int looplen = 3;

  // FILL ARRAY
  for (int i = 0; i < looplen; i++) {
    Array_Add(strings, test_buffer[i]);
  }

  // PRINT ARRAY
  for (int i = 0; i < looplen; i++) {
    char *test = (char*) Array_Get(strings, i);
    printf("Element %d: %s\n", i, test);
  }

  return 0;
}
