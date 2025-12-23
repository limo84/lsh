#pragma once

void ncurses_init();

#ifdef LSH

char *get_path() {
  #define PATH_MAX 4096
  char buffer[PATH_MAX];
  if (getcwd(buffer, PATH_MAX) == NULL) {
    perror("getcwd");
    return NULL;
  }
  u16 cwd_len = strlen(buffer) + 1;
  char *path = malloc(cwd_len);
  strcpy(path, buffer);
  return path;
}

bool is_directory(char *path) {
  struct stat statbuf;
  if (stat(path, &statbuf) != 0)
    die("stat dieded: %s", path);
  return S_ISDIR(statbuf.st_mode);
}

typedef enum {
  BLINKING_BLOCK = 1,
  STEADY_BLOCK,
  BLINKING_UNDERLINE,
  STEADY_UNDERLINE,
  BLINKING_BAR,
  STEADY_BAR,
} CursorShape;

void set_cursor_shape(int code) {
  printf("\033[%d q", code);
  fflush(stdout); // Ensure it gets sent to terminal
}

void ncurses_init() {
  initscr();
  noecho();
  curs_set(1);
  set_cursor_shape(BLINKING_BAR);
  start_color();
  atexit((void*)endwin);
  if (!has_colors()) {
    die("No Colors\n");
  }
  if (can_change_color()) {
    // change colors
  }
  raw();
  nonl(); // for LK_ENTER|13
  setup_signals();
  
  for (u8 i = 0; i < 8; i++) {
    for (u8 j = 0; j < 8; j++) {
      init_pair(i * 8 + j, j, i);
    }
  }

  // INVERTED AUTOMATICALLY (B, B) -> (W, B) 
  // 0 = BLACK
  // 1 = RED
  // 2 = GREEN
  // 3 = YELLOW
  // 4 = BLUE
  // 5 = PURPLE
  // 6 = TEAL
  // 7 = WHITE
}

#endif
