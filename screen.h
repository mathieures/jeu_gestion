#ifndef SCREEN_H
#define SCREEN_H
#include <stdio.h>

enum BG_COLOR {
    WHITE_BG = 255,
    BLACK_BG = 0
};

enum FG_COLOR {
    WHITE_FG = 255,
    BLACK_FG = 0
};

void clear_screen(void);
void move_cursor_to(int x, int y);
void save_cursor_position(void);
void restore_cursor_position(void);
void reset_colors(void);
void reverse_colors(void);

void move_lines_up(int n);
void move_to_column(int c);

#endif