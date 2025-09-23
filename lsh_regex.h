#ifndef lsh_regex_h
#define lsh_regex_h

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

bool regex_match(char *regex, char *string);

#ifdef lsh_regex_imp

// FROM START (FOR NOW)
bool regex_match(char *regex, char *string) {
  u16 rex_len = strlen(regex);
  for (u16 i = 0; i < rex_len; i++) {
    
  }
}


#endif
#endif
