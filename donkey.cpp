// include donkey.h
#include "donkey.h"
// include ncurses
#include <ncurses.h>
// include stdlib
#include <stdlib.h>

// constructor
donkey::donkey(int y, int x, int wheight, int wwidth)
{
    ul_x = x;
    ul_y = y;
    height = 10;
    width = 25;
    win_height = wheight;
    win_width = wwidth;
};

// prints a donkey
void donkey::draw(bool flag)
{
    if (flag == true)
    {
        mvprintw(ul_y, ul_x+5, "|\\");
        mvprintw(ul_y, ul_x, "+");
        mvprintw(ul_y, ul_x+width, "+");
        mvprintw(ul_y+1, ul_x+1, "___=  |");
        mvprintw(ul_y+2, ul_x, "/      \\");
        mvprintw(ul_y+3, ul_x, "\\____   \\===========_");
        mvprintw(ul_y+4, ul_x+5, "\\               )\\");
        mvprintw(ul_y+5, ul_x+5, "\\\\    _______   |\\\\");
        mvprintw(ul_y+6, ul_x+5, "| |  /      |\\  | \\\\");
        mvprintw(ul_y+7, ul_x+5, "| | |       | | |  0");
        mvprintw(ul_y+8, ul_x+5, "==| |       ==| |");
        mvprintw(ul_y+9, ul_x+7, "===         ===");
        mvprintw(ul_y+height, ul_x, "+");
        mvprintw(ul_y+height, ul_x+width, "+");
    }
    else
    {
        mvprintw(ul_y, ul_x+5, "   ");
        mvprintw(ul_y, ul_x, " ");
        mvprintw(ul_y, ul_x+width, " ");
        mvprintw(ul_y+1, ul_x+1, "       ");
        mvprintw(ul_y+2, ul_x, "         ");
        mvprintw(ul_y+3, ul_x, "                       ");
        mvprintw(ul_y+4, ul_x+5, "                    ");
        mvprintw(ul_y+5, ul_x+5, "                       ");
        mvprintw(ul_y+6, ul_x+5, "                       ");
        mvprintw(ul_y+7, ul_x+5, "                    ");
        mvprintw(ul_y+8, ul_x+5, "                 ");
        mvprintw(ul_y+9, ul_x+7, "               ");
        mvprintw(ul_y+height, ul_x, " ");
        mvprintw(ul_y+height, ul_x+width, " ");
    }
}

void donkey::move(int y, int x)
{
    draw(0);
    ul_x += x;
    ul_y += y;
    if (ul_y > win_height-5)
    {
        ul_y = 0;
        ul_x = ( rand() % ( win_width - 48 )) + 24;
    }
    draw(1);
    refresh();
}
