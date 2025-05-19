#include <cstdlib>
#include <time.h>

#include "../sdlinterf.h"

using namespace std;

class Color
{

public:
    Color(int r = 0, int g = 0, int b = 0)
    {
        mR = r;
        mG = g;
        mB = b;
    }

    int getR() const { return mR; }
    int getG() const { return mG; }
    int getB() const { return mB; }

private:
    int mR, mG, mB;
};

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

int main(void)
{
    sdlInit();

    {

        Rectangle p(Color(255, 255, 255), SDL_X_SIZE / 2, SDL_Y_SIZE / 2, 20, 20, 2, 1);
        srand(time(NULL));
        for (;;)
        {
            sdlMilliSleep(2);
            if(!(p.fly(true)))
            {
                p.scale(0.90, 0.90);
            }

            sdlUpdate();
        }
    }

    sdlExit();

    exit(EXIT_SUCCESS);
}

void Rectangle::setPos(int x, int y)
{
    undraw();
    mX = x;
    mY = y;
    draw();
}

void Rectangle::move(int dx, int dy)
{
    undraw();
    mX += dx;
    mY += dy;
    draw();
}

void Rectangle::setsize(int sizex, int sizey)
{
    
    
    if(sizex <= 0 || sizey <= 0)
    {
        int sizex = rand() % (30 + 1);
        int sizey = rand() % (30 + 1);
        setPos(SDL_X_SIZE / 2, SDL_Y_SIZE / 2);
    }
    undraw();
    sizeX = sizex;
    sizeY = sizey;
    draw();
}

void Rectangle::scale(float prox, float proy)
{
    undraw();
    setsize(getsizeX()*prox, getsizeY()*proy); //sollte abschneiden
    
}

bool Rectangle::fly(bool bounce)
{
    bool ret = true;

    if (((mSX + sizeX > 0) && (mX + sizeX >= SDL_X_SIZE - mSX)) ||
        ((mSX - sizeX< 0) && (mX - sizeX< -mSX)))
    {

        if (bounce)
        {

            mSX = -mSX;
            ret = false;
        }
        else
        {

            return false;
        }
    }

    if (((mSY + sizeY > 0) && (mY + sizeY>= SDL_Y_SIZE - mSY)) ||
        ((mSY - sizeY< 0) && (mY - sizeY< -mSY)))
    {
        if (bounce)
        {
            mSY = -mSY;
            ret = false;
        }
        else
        {
            return false;
        }
    }

    move(mSX, mSY);
    return ret;
}

void Rectangle::draw()
{

    sdlDrawRect(mX, mY, sizeX, sizeY, mRGB.getR(), mRGB.getG(), mRGB.getB());
}

void Rectangle::undraw()
{

    sdlDrawRect(mX, mY, sizeX, sizeY, 0, 0, 0);
}