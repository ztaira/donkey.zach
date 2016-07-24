#ifndef CAR
#define CAR
// car object
class car
{
public:
    // constructor
    car(int x, int y);
    // width and height
    int height;
    int width;
    // location of the upper-left corner
    int ul_x;
    int ul_y;
    // draw function
    void draw(bool flag);
    void move(int y, int x);
};
#endif
