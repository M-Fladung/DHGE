#include "color.h"

class Rectangle
{
public:
    Rectangle(const Color &color, int x, int y, int sizex, int sizey, int sx = 0, int sy = 0)
    {
        mRGB = color;

        mX = x;
        mY = y;
        mSX = sx;
        mSY = sy;
        sizeX = sizex;
        sizeY = sizey;
        draw();
    }

    ~Rectangle() { undraw(); }

    Color getColor() const { return mRGB; }
    int getX() const { return mX; }
    int getY() const { return mY; }
    int getSX() const { return mSX; }
    int getSY() const { return mSY; }
    int getsizeX() const { return sizeX; }
    int getsizeY() const { return sizeY; }

    void setColor(const Color &color)
    {
        mRGB = color;
        draw();
    }

    void setSpeed(int sx, int sy)
    {
        mSX = sx;
        mSY = sy;
    }

    void setPos(int x, int y);

    void move(int dx, int dy);

    void setsize(int sizex, int sizey);

    void scale(float prox, float proy);

    bool fly(bool bounce = false);

    void draw();

    void undraw();

private:
    Color mRGB;

    int mX, mY;
    int sizeX, sizeY;
    int mSX, mSY;
};