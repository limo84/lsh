#define LSH

#include <lsh/lsh_array.h>
#include <stdio.h>

#define TESTSIZE 5

typedef struct {
  int id;
  char name[10];
} Person;

void printPerson(Person* p) {
  printf("Id: %d, Name: %s\n", p->id, p->name); 
}

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

  Person p1 = {1, "Hans"};
  Person p2 = {5, "Fredo"};

  Array *people = Array_Init(sizeof(Person), 1);
  Array_Add(people, &p1);
  Array_Add(people, &p2);
  printPerson((Person*) Array_Get(people, 0));
  printPerson((Person*) Array_Get(people, 1));
  
  return 0;
}
