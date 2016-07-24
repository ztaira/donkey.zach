// include car.h
#include "car.h"
// include ncurses
#include <ncurses.h>

//constructor
car::car(int y, int x)
{
    ul_x = x;
    ul_y = y;
    height = 15;
    width = 25;
};

// prints a car
void car::draw(bool flag)
{
    if (flag == true)
    {
        mvprintw(ul_y, ul_x+11, "___");
        mvprintw(ul_y, ul_x, "+");
        mvprintw(ul_y, ul_x+width, "+");
        mvprintw(ul_y+1, ul_x+4, "__    /   \\    __");
        mvprintw(ul_y+2, ul_x+3, "|  |__|     |__|  |");
        mvprintw(ul_y+3, ul_x+3, "|  |==|     |==|  |");
        mvprintw(ul_y+4, ul_x+3, "'--'  |     |  '--'");
        mvprintw(ul_y+5, ul_x+9, "|     |");
        mvprintw(ul_y+6, ul_x+8, "/   _   \\");
        mvprintw(ul_y+7, ul_x+7, "|   | |   |");
        mvprintw(ul_y+8, ul_x+1, "___   |  /___\\  |   ___");
        mvprintw(ul_y+9, ul_x, "|   |__| |  _  | |__|   |");
        mvprintw(ul_y+10, ul_x, "|   |__| | |=| | |__|   |");
        mvprintw(ul_y+11, ul_x, "|   |==| |  -  | |==|   |");
        mvprintw(ul_y+12, ul_x, "'---'  |  \\___/  |  '---'");
        mvprintw(ul_y+13, ul_x+8, "\\       /");
        mvprintw(ul_y+14, ul_x+9, "^=====^");
        mvprintw(ul_y+height, ul_x, "+");
        mvprintw(ul_y+height, ul_x+width, "+");
    }
    else
    {
        mvprintw(ul_y, ul_x+11, "   ");
        mvprintw(ul_y, ul_x, " ");
        mvprintw(ul_y, ul_x+width, " ");
        mvprintw(ul_y+1, ul_x+4, "                  ");
        mvprintw(ul_y+2, ul_x+3, "                   ");
        mvprintw(ul_y+3, ul_x+3, "                   ");
        mvprintw(ul_y+4, ul_x+3, "                   ");
        mvprintw(ul_y+5, ul_x+9, "       ");
        mvprintw(ul_y+6, ul_x+8, "          ");
        mvprintw(ul_y+7, ul_x+7, "           ");
        mvprintw(ul_y+8, ul_x+1, "                        ");
        mvprintw(ul_y+9, ul_x, "                         ");
        mvprintw(ul_y+10, ul_x, "                         ");
        mvprintw(ul_y+11, ul_x, "                         ");
        mvprintw(ul_y+12, ul_x, "                          ");
        mvprintw(ul_y+13, ul_x+8, "          ");
        mvprintw(ul_y+14, ul_x+9, "       ");
        mvprintw(ul_y+height, ul_x, " ");
        mvprintw(ul_y+height, ul_x+width, " ");
    }
}

void car::move(int y, int x)
{
    draw(0);
    ul_x += x;
    ul_y += y;
    draw(1);
    refresh();
}
