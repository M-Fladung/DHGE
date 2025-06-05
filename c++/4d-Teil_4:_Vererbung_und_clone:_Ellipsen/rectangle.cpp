// Geom. Objekte: Copy-Konstruktor, "moveOnTop"
// Implementierung der Klasse "Rectangle"
//
// Klaus Kusche, 2020

// für max(a, b)
#include <algorithm>

using namespace std;

#include "../sdlinterf.h"

#include "rectangle.h"

void Rectangle::draw()
{
  sdlDrawRect(mX, mY, mW, mH, mRGB.getR(), mRGB.getG(), mRGB.getB());
}

void Rectangle::undraw()
{
  sdlDrawRect(mX, mY, mW, mH, 0, 0, 0);
}