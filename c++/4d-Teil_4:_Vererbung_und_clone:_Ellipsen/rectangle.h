
#ifndef _Rectangle_H
#define _Rectangle_H

#include "color.h"
#include "graobj.h"

class Rectangle : public GraObj
{
  public:
    Rectangle(const Color &color, int x, int y, int w, int h,
          int sx = 0, int sy = 0)
    : GraObj(color, x, y , w, h, sx, sy)
    {
      draw();
    }

    Rectangle(const Rectangle &origin) : GraObj(origin)
    {
      draw();
    }
    virtual ~Rectangle() {undraw();}

    virtual Rectangle *clone() const override
    {
      return new Rectangle(*this);
    }

    virtual void draw() override;
    virtual void undraw() override;
};


#endif