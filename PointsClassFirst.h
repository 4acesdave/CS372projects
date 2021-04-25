#ifndef POINTSCLASSFIRST_H_INCLUDED
#define POINTSCLASSFIRST_H_INCLUDED
#include <iostream>
#include <fstream>
class point {
  public:
    double x;// store x
    double y;// store y

    // constructor with two arguments
    point(double altX,double altY) {
        x=altX;
        y=altY;
    }

    // translate
    void translation(double altX,double altY) {
        x+=altX;
        y+=altY;
    }

    // scaling
    void scaling(double altX,double altY) {
        x=(x*altX);
        y=(y*altY);
    }

    // rotation
    void rotation(double d) {
      double tx=x,ty=y;
      // store new x and y
      // if we calculate y directly,
      // y will take new value of x
      tx=(x*cos(d)-y*sin(d));
      ty=(x*sin(d)+y*cos(d));
      // store in x and y
      x=tx;
      y=ty;
    }

    // shearing X direction
    void shearingX(double altX) {
      x+=altX;
    }

    // shearing Y direction
    void shearingY(double altY) {
      y+=altY;
    }
};
#endif // POINTSCLASSFIRST_H_INCLUDED
