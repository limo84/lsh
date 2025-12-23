#ifndef lsh_ncurses_h
#define lsh_ncurses_h

#include "lsh_types.h"

#include <ncurses.h>
#include <stdlib.h>

#define CTRL(c) ((c) & 037)
#define LK_NEWLINE 10
#define LK_ENTER 13
#define LK_UP 65
#define LK_DOWN 258
#define LK_RIGHT 67
#define LK_LEFT 68
#define LK_ESCAPE 27
#define LK_SPACE 32

void ncurses_init();

#ifdef LSH

void die(const char *format, ...) {
  endwin();
  va_list args;
  va_start(args, format);
    vprintf(format, args);
  va_end(args);
  printf("\n");
  exit(0);
}

void ncurses_init() {
  initscr();
  noecho();
  start_color();
  atexit((void*)endwin);
  if (!has_colors()) {
    exit(1);
  }
  raw();
  nonl();
  // 0 = BLACK
  // 1 = RED
  // 2 = GREEN
  // 3 = YELLOW
  // 4 = BLUE
  // 5 = PURPLE
  // 6 = TEAL
  // 7 = WHITE
  for (u8 i = 0; i < 8; i++) {
    for (u8 j = 0; j < 8; j++) {
      init_pair(i * 8 + j, j, i);
    }
  }
}

#endif
#endif
