#ifndef CURVE_2D_Casteljau_H
#define CURVE_2D_Casteljau_H

#include "curve2D.h"
#include <assert.h>
using namespace std;


class Curve2DCasteljau : public Curve2D {
 public:
 Curve2DCasteljau(const QString &name) : Curve2D(name) {}
 Curve2DCasteljau(Curve2D *curve,const QString &name) : Curve2D(curve,name) {}
  
  QPainterPath path(float frame) {
	QPainterPath p;
	if(nbPts()==0) 
		return p;
	// Px and Py are the coordinates of all the points
	VectorXd Px (nbPts());
	VectorXd Py (nbPts());
	Vector2f pt = evalAnimPt(get(0),frame);
	Px(0) = pt[0];
	Py(0) = pt[1];
	// fill Px and Py with the points
	for(unsigned int i=1;i<nbPts();++i) {
		pt = evalAnimPt(get(i),frame);
		Px(i) = pt[0];
		Py(i) = pt[1];
	}
	// create vector t from 0 to 1
	unsigned int N=1000;
	// array is a function that is defined in the curve2D.h file
	vector<float> t = array(0.0,1.0,N);
	// create vectors, where I will save the points later on:
	vector<float> Castelx;
	vector<float> Castely;
	// We will compute for all the values of the parameter t the coordinates of the points
	// Then we will draw the curve
	for(unsigned int i=0;i<t.size();i++){
		// Application of DeCasteljau for x- and y-coordinate
		for (unsigned int k=0;k<Px.size()-1;k++){
			Px(k) = (1-t[i])*Px(k)+t[i]*Px(k+1);
		};
		for (unsigned int k=0;k<Py.size()-1;k++){
			Py(k) = (1-t[i])*Py(k)+t[i]*Py(k+1);
		};
		double xtemp = Px(0);
		double ytemp = Py(0);
		//points are added to the vectors Castel 
		Castelx.push_back(xtemp);
		Castely.push_back(ytemp);
	}
	p.moveTo(Castelx[0], Castely[0]);
	for(unsigned int i = 1; i< N; i++){
		p.lineTo(Castelx[i], Castely[i]);
	}
	
    return p;
  }
};


class Curve2DCasteljauConstructor : public Curve2DConstructor {
 public:
  virtual ~Curve2DCasteljauConstructor()                     {}
  virtual const QString type() const                      { return "CasteljauCurve";             }
  virtual Curve2D *create(const QString &name)            { return new Curve2DCasteljau(name);   }
  virtual Curve2D *create(Curve2D *c,const QString &name) { return new Curve2DCasteljau(c,name); }
};


#endif
