// include grass.h
#include "grass.h"
// include ncurses
#include <ncurses.h>
// include stdlib
#include <stdlib.h>

// constructor
grass::grass(int y, int x, int wheight, int wwidth)
{
    ul_x = x;
    ul_y = y;
    height = 10;
    width = 25;
    win_height = wheight;
    win_width = wwidth;
};

// prints a grass
void grass::draw(bool flag)
{
    if (flag == true)
    {
        mvprintw(ul_y, ul_x, "^^^");
    }
    else
    {
        mvprintw(ul_y, ul_x, "   ");
    }
}

void grass::move(int y, int x)
{
    draw(0);
    ul_x += x;
    ul_y += y;
    if (ul_y > win_height-5)
    {
        ul_y = 0;
        ul_x = (rand() % ( win_width - 48 )) + 24;
    }
    draw(1);
    refresh();
}
