// Geom. Objekte: Copy-Konstruktor, "moveOnTop"
// Implementierung der Klasse "GraObj"
//
// Klaus Kusche, 2020

// für max(a, b)
#include <algorithm>

using namespace std;

#include "../sdlinterf.h"

#include "graobj.h"

void GraObj::setPos(int x, int y)
{
  undraw();
  mX = x;
  mY = y;
  draw();
}

void GraObj::move(int dx, int dy)
{
  undraw();
  mX += dx;
  mY += dy;
  draw();
}

void GraObj::setSize(int w, int h)
{
  undraw();
  mW = w;
  mH = h;
  draw();
}

void GraObj::scale(int percentX, int percentY)
{
  undraw();
  mW = (mW * percentX) / 100;
  mH = (mH * percentY) / 100;
  draw();
}
  
bool GraObj::fly(bool bounce)
{
  bool ret = true;
  if (((mSX > 0) && (mX >= SDL_X_SIZE - mSX - mW)) ||
      ((mSX < 0) && (mX < -mSX + mW))) {
    if (bounce) {
      mSX = -mSX;
      ret = false;
    }
    else {
      return false;
    }
  }
  if (((mSY > 0) && (mY >= SDL_Y_SIZE - mSY - mH)) ||
      ((mSY < 0) && (mY < -mSY + mH))) {
    if (bounce) {
      mSY = -mSY;
      ret = false;
    }
    else {
      return false;
    }
  }

  move(mSX, mSY);
  return ret;
}


