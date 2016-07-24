#include <iostream>
#include <string>
#include <vector>
#include <ncurses.h>
#include "grass.h"
#include "donkey.h"
#include "car.h"
using namespace std;

int collision(donkey *obj1, car *obj2);
void lose_screen(int y, int x);
void open_screen(int y, int x);

int main()
{   
    int ch, win_height, win_width;
    // create a screen
    // get the screen's height and width
    initscr();
    getmaxyx(stdscr, win_height, win_width);
    // we don't want to print input characters
    noecho();
    // we want the cursor to be invisible
    curs_set(0);
    // print the opening screen, which won't go away until a key is pressed
    open_screen(win_height/2, win_width/2);
    refresh();
    getch();
    // create a donkey instance, a car instance, and a bunch of grass
    // draw them all
    werase(stdscr);
    donkey mydonkey = donkey(0, 0, win_height, win_width);
    car mycar = car(30, 30, win_height, win_width);
    vector<grass> grassvector;
    for (int i=0; i<win_height; i+=5)
    {
        grassvector.push_back(grass(i, rand()%(win_width), win_height, win_width));
    }
    for (vector<grass>::iterator itr = grassvector.begin();
            itr != grassvector.end(); ++itr)
    {
        itr->draw(1);
    }
    mycar.draw(1);
    mydonkey.draw(1);
    // we now want to auto-refresh the screen every 0.1 secs or so
    timeout(100);

    // game loop
    while ((ch = getch()) != 'q')
    {
        for (vector<grass>::iterator itr = grassvector.begin();
                itr != grassvector.end(); ++itr)
        {
            itr->move(2, 0);
        }
        mydonkey.move(2, 0);

        switch(ch)
        {
            case 'a':
                mycar.move(0, -10);
                break;
            case 'd':
                mycar.move(0, 10);
                break;
            case 'e':
                mycar.move(0, 10);
                break;
            case 'w':
                mycar.move(-1, 0);
                break;
            case ',':
                mycar.move(-1, 0);
                break;
            case 's':
                mycar.move(1, 0);
                break;
            case 'o':
                mycar.move(1, 0);
                break;
        }
        mycar.draw(1);
        if (collision(&mydonkey, &mycar)==1)
        {
            break;
        }
    }
    werase(stdscr);
    lose_screen(win_height/2, win_width/2);
    refresh();
    while((ch = getch())!='q')
    {
        refresh();
    }
    endwin();           /* End curses mode        */

    return 0;
}

// checks whether or now obj2's top 2 corners are within obj1
int collision(donkey *obj1, car *obj2)
{
    // mvprintw(0, 0, to_string(obj1->ul_x).c_str());
    // mvprintw(1, 0, to_string(obj1->ul_y).c_str());
    // mvprintw(2, 0, to_string(obj2->ul_x).c_str());
    // mvprintw(3, 0, to_string(obj2->ul_y).c_str());
    if (obj2->ul_y >= obj1->ul_y and obj2->ul_y < obj1->ul_y + obj1->height
            and obj2->ul_x > obj1->ul_x and obj2->ul_x < obj1->ul_x + obj1->width)
    {
        return 1;
    }
    else if (obj2->ul_y >= obj1->ul_y and obj2->ul_y < obj1->ul_y+obj1->height 
            and obj2->ul_x+obj2->width > obj1->ul_x and obj2->ul_x+obj2->width < obj1->ul_x + obj1->width)
    {
        return 1;
    }
    return 0;
}

void lose_screen(int y, int x)
{
    mvprintw(y-2, x-4, "YOU LOSE");
    mvprintw(y, x-16, "Driving a racecar through a crowd");
    mvprintw(y+1, x-17, "of donkeys was probably a bad idea.");
    mvprintw(y+3, x-7, "Press q to exit");
}

void open_screen(int y, int x)
{
    mvprintw(y, x-17, "You are driving through a field...");
    mvprintw(y+2, x-20, "Suddenly: Donkeys! Dodge them to survive!");
    mvprintw(y+4, x-27, "Use the WASD keys or their dvorak counterparts to steer");
}
