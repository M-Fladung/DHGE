#include "../sdlinterf.h"
#include "rectangle.h"




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