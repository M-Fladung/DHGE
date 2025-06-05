// Geom. Objekte: Copy-Konstruktor, "moveOnTop"
// Implementierung der Klasse "Circle"
//
// Klaus Kusche, 2020

// für max(a, b)
#include <algorithm>

using namespace std;

#include "../sdlinterf.h"

#include "circ.h"

void Circ::draw()
{
  sdlDrawCirc(mX, mY, mW, mH, mRGB.getR(), mRGB.getG(), mRGB.getB());
}

void Circ::undraw()
{
  sdlDrawCirc(mX, mY, mW, mH, 0, 0, 0);
}