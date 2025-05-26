
#ifndef _Rectangle_H
#define _Rectangle_H

#include "color.h"

class Rectangle
{
  public:
    Rectangle(const Color &color, int x, int y, int w, int h,
          int sx = 0, int sy = 0)
    : mRGB(color), mX(x), mY(y), mW(w), mH(h), mSX(sx), mSY(sy)
    {
      draw();
    }
    Rectangle(const Rectangle &orig); 

    ~Rectangle() { undraw(); }

    Color getColor() const { return mRGB; }
    int getX() const { return mX; }
    int getY() const { return mY; }
    int getW() const { return mW; }
    int getH() const { return mH; }
    int getSX() const { return mSX; }
    int getSY() const { return mSY; }

    void setColor(const Color &color)
    {
      mRGB = color;
      draw();
    }

    void setSpeed(int sx, int sy)
    {
      mSX = sx; mSY = sy;
    }
    
    void setPos(int x, int y);

    void move(int dx, int dy);
    
    void setSize(int w, int h);
    
    void scale(int percentX, int percentY);

    bool fly(bool bounce = false);


    void draw();

    void undraw();

    void moveOnTop(const Rectangle &r);

  private:
    Color mRGB;
    int mX, mY;
    int mW, mH;
    int mSX, mSY;
};

#endif