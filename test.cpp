#include <ncurses.h>
#include <string>
using namespace std;

int main()
{   
    initscr();          /* Start curses mode          */
    string x="hello world zach";
    printw(x.c_str());  /* Print Hello World          */
    refresh();          /* Print it on to the real screen */
    getch();            /* Wait for user input */
    endwin();           /* End curses mode        */

    return 0;
}
