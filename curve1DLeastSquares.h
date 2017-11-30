#ifndef CURVE_1D_LEAST_SQUARES
#define CURVE_1D_LEAST_SQUARES

#include "curve1D.h"
#include <iostream>

class Curve1DLeastSquares : public Curve1D {
 public:
 Curve1DLeastSquares(const QString &name) : Curve1D(name) {}
 Curve1DLeastSquares(Curve1D *curve,const QString &name) : Curve1D(curve,name) {}

  QPainterPath path(float xmin,float xmax) {
    QPainterPath p;

    // empty test
    if(empty())
      return p;

    p.moveTo(xmin,evalAt(xmin));

    p.lineTo(xmax,evalAt(xmax));

    return p;

  }

  float evalAt(float x) {
    if(empty()) return 0.0f;
    if(nbPts()==1) return _points[0][1];
    float a,b;
    float xs = 0, ys=0, xys=0, xxs=0;
    for (unsigned int i=0;i<nbPts();i++){
        xs = xs + _points[i][0];
        ys = ys + _points[i][1];
        xys = xys + _points[i][0]*_points[i][1];
        xxs= xxs + _points[i][0]*_points[i][0];
    }
    a = (nbPts()*xys - xs*ys)/(nbPts()*xxs - xs*xs);
    b = (ys - a*xs)/nbPts();
    return(a*x+b);
  }
};

class Curve1DLeastSquaresConstructor : public Curve1DConstructor {
 public:
  virtual ~Curve1DLeastSquaresConstructor()                     {}
  virtual const QString type() const                      { return "LeastSquares";             }
  virtual Curve1D *create(const QString &name)            { return new Curve1DLeastSquares(name);   }
  virtual Curve1D *create(Curve1D *c,const QString &name) { return new Curve1DLeastSquares(c,name); }
};

#endif // CURVE_1D_LEAST_SQUARES

