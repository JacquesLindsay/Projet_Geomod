#ifndef CURVE_2D_CircleRadius_H
#define CURVE_2D_CircleRadius_H

#include "curve2D.h"
using namespace std;

class Curve2DCircleRadius : public Curve2D {
 public:
 Curve2DCircleRadius(const QString &name) : Curve2D(name) {}
 Curve2DCircleRadius(Curve2D *curve,const QString &name) : Curve2D(curve,name) {}
  
  QPainterPath path(float frame) {
	QPainterPath p;
	if(nbPts()==0) 
	return p;

	Vector2f ptbis = evalAnimPt(get(0),frame);
	//pt represents the center
	vector<int> pt;
	pt.push_back(ptbis[0]);
	pt.push_back(ptbis[1]);
	// the 2 points represents the diameter of the CircleRadius
	for(unsigned int i=1;i<nbPts();++i){
		// we compute the center of the CircleRadius
		ptbis = evalAnimPt(get(i),frame);
		vector<int> pt2;
		pt2.push_back(ptbis[0]);
		pt2.push_back(ptbis[1]);
		

		//compute the radius : 
		float R=sqrt(pow(pt[0]-pt2[0],2)+pow(pt[1]-pt2[1],2));
		
		unsigned int N=1000;
		// array is a function that I've defined in the curve2D.h file
		vector<float> t = array(0,2*3.14159,N);
		vector<float> x;
		vector<float> y;
		for(unsigned int i=0;i<t.size();i++){
			x.push_back(R*cos(t[i])+pt[0]);
			y.push_back(R*sin(t[i])+pt[1]);
		}
		
		// draw the CircleRadius
		p.moveTo(x[0],y[0]);
		for (unsigned int i=0;i<t.size();i++){
			p.lineTo(x[i],y[i]);
		}
		pt.pop_back();
		pt.pop_back();
		pt.push_back(pt2[0]);
		pt.push_back(pt2[1]);
	}
	return p;
	}
};


class Curve2DCircleRadiusConstructor : public Curve2DConstructor {
 public:
  virtual ~Curve2DCircleRadiusConstructor()                     {}
  virtual const QString type() const                      { return "CircleRadiusCurve";             }
  virtual Curve2D *create(const QString &name)            { return new Curve2DCircleRadius(name);   }
  virtual Curve2D *create(Curve2D *c,const QString &name) { return new Curve2DCircleRadius(c,name); }
};


#endif // CURVE_2D_CircleRadius_H
