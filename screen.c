#include "screen.h"

static int reversed_colors = 0;

void clear_screen(void)
{
    printf("\e[2J");
}

void move_cursor_to(int x, int y)
{
    printf("\e[%d;%dH", x+1, y+1);
}

void save_cursor_position(void)
{
    printf("\e[s");
}

void restore_cursor_position(void)
{
    printf("\e[u");
}

// 38: fg, 48 : bg
void change_fg_color_to(int c)
{
    printf("\e[38;5;%dm", c);
}

void change_bg_color_to(int c)
{
    printf("\e[48;5;%dm", c);
}

void reset_colors(void)
{
    printf("\e[0m");
}

void reverse_colors(void)
{
    if (reversed_colors)
        reset_colors();
    else
    {
        change_fg_color_to(BLACK);
        change_bg_color_to(WHITE);
        // printf("\e[38;5;0m\e[48;5;255m");
    }
    reversed_colors = !reversed_colors;
}

void move_lines_up(int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("\e[F"); // Bouge le curseur au début de la ligne du dessus
}

void move_to_column(int c)
{
    printf("\e[%dG", c + 1); // + 1 car ça commence à 1, pas à 0
}