#include <ncurses.h>
#include <iostream>
#include <string>
using namespace std;

void print_donkey(int y, int x);
void print_car(int y, int x);

int main()
{   
    initscr();          /* Start curses mode          */
    string x="hello world zach";
    printw(x.c_str());  /* Print Hello World          */
    // print_donkey(0, 0);
    print_car(0,0);
    refresh();          /* Print it on to the real screen */
    getch();            /* Wait for user input */
    endwin();           /* End curses mode        */

    cout << x;
    return 0;
}

// prints a donkey
void print_donkey(int y, int x)
{
    mvprintw(y, x+5, "|\\");
    mvprintw(y+1, x+1, "___=  |");
    mvprintw(y+2, x, "/      \\");
    mvprintw(y+3, x, "\\____   \\===========_");
    mvprintw(y+4, x+5, "\\               )\\");
    mvprintw(y+5, x+5, "\\\\    _______   |\\\\");
    mvprintw(y+6, x+5, "| |  /      |\\  | \\\\");
    mvprintw(y+7, x+5, "| | |       | | |  0");
    mvprintw(y+8, x+5, "==| |       ==| |");
    mvprintw(y+9, x+7, "===         ===  +");
}

void print_car(int y, int x)
{
    mvprintw(y, x+11, "___");
    mvprintw(y+1, x+4, "__    /   \\    __");
    mvprintw(y+2, x+3, "|  |__|     |__|  |");
    mvprintw(y+3, x+3, "|  |==|     |==|  |");
    mvprintw(y+4, x+3, "'--'  |     |  '--'");
    mvprintw(y+5, x+9, "|     |");
    mvprintw(y+6, x+8, "/   _   \\");
    mvprintw(y+7, x+7, "|   | |   |");
    mvprintw(y+8, x+1, "___   |  /___\\  |   ___");
    mvprintw(y+9, x, "|   |__| |  _  | |__|   |");
    mvprintw(y+10, x, "|   |__| | |=| | |__|   |");
    mvprintw(y+11, x, "|   |==| |  -  | |==|   |");
    mvprintw(y+12, x, "'---'  |  \\___/  |  '---'");
    mvprintw(y+13, x+8, "\\       /");
    mvprintw(y+14, x+9, "^=====^        +");
}
