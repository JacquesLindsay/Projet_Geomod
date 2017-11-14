#ifndef CURVE_2D_Circle_H
#define CURVE_2D_Circle_H

#include "curve2D.h"
using namespace std;

class Curve2DCircle : public Curve2D {
 public:
 Curve2DCircle(const QString &name) : Curve2D(name) {}
 Curve2DCircle(Curve2D *curve,const QString &name) : Curve2D(curve,name) {}
  
  QPainterPath path(float frame) {
	QPainterPath p;
	if(nbPts()==0) 
	return p;

	Vector2f ptbis = evalAnimPt(get(0),frame);
	vector<int> pt;
	pt.push_back(ptbis[0]);
	pt.push_back(ptbis[1]);
	// the 2 points represents the diameter of the circle
	if(nbPts()==2){
		// we compute the center of the circle
		ptbis = evalAnimPt(get(1),frame);
		vector<int> pt2;
		pt2.push_back(ptbis[0]);
		pt2.push_back(ptbis[1]);
		vector<int> center;
		center.push_back((pt[0]+pt2[0])/2);
		center.push_back((pt[1]+pt2[1])/2);

		//compute the radius : 
		float R=sqrt(pow(pt[0]-pt2[0],2)+pow(pt[1]-pt2[1],2))/2;
		
		unsigned int N=1000
		// array is a function that I've defined in the curve2D.h file
		vector<float> t = array(0,2*3.14159,N);
		vector<float> x;
		vector<float> y;
		for(unsigned int i=0;i<t.size();i++){
			x.push_back(R*cos(t[i])+center[0]);
			y.push_back(R*sin(t[i])+center[1]);
		}
		
		// draw the circle
		p.moveTo(pt[0],pt[1]);
		for (unsigned int i=0;i<t.size();i++){
			p.lineTo(x[i],y[i]);
		}
	}
	return p;
	}
};


class Curve2DCircleConstructor : public Curve2DConstructor {
 public:
  virtual ~Curve2DCircleConstructor()                     {}
  virtual const QString type() const                      { return "CircleCurve";             }
  virtual Curve2D *create(const QString &name)            { return new Curve2DCircle(name);   }
  virtual Curve2D *create(Curve2D *c,const QString &name) { return new Curve2DCircle(c,name); }
};


#endif // CURVE_2D_Circle_H
