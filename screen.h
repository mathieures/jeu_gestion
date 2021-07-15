#ifndef SCREEN_H
#define SCREEN_H
#include <stdio.h>

enum COLOR {
    WHITE = 255,
    BLACK = 0
};

void clear_screen(void);
void move_cursor_to(int x, int y);
void save_cursor_position(void);
void restore_cursor_position(void);

void change_fg_color_to(int c);
void change_bg_color_to(int c);
void reset_colors(void);
void reverse_colors(void);

void move_lines_up(int n);
void move_to_column(int c);

#endif