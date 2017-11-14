#ifndef CURVE_2D_Bezier_H
#define CURVE_2D_Bezier_H

#include "curve2D.h"
#include <assert.h>
using namespace std;

int factorial(int x);
vector<float> Bernstein(int n, float t);
class Curve2DBezier : public Curve2D {
 public:
 Curve2DBezier(const QString &name) : Curve2D(name) {}
 Curve2DBezier(Curve2D *curve,const QString &name) : Curve2D(curve,name) {}
  
  QPainterPath path(float frame) {
	QPainterPath p;
	if(nbPts()==0) 
	return p;
	// Px and Py are the coordinates of all the points
	vector<int> Px;
	vector<int> Py;
	Vector2f pt = evalAnimPt(get(0),frame);
	Px.push_back(pt[0]);
	Py.push_back(pt[1]);

	// draw the Bezier Polynom
	for(unsigned int i=1;i<nbPts();++i) {
	pt = evalAnimPt(get(i),frame);
	Px.push_back(pt[0]);
	Py.push_back(pt[1]);
	}

	// Draw the Bezier curve
	// create vector t from 0 to 1
	unsigned int N=1000;
	// array is a function that I've defined in the curve2D.h file
	vector<float> t = array(0.0,1.0,N);
	// create the berstein vector with values of t
	vector<float> Bezierx;
	vector<float> Beziery;
	// We will compute for all the values of the parameter t the coordinates of the points
	// Then we will draw the curve
	for(unsigned int i=0;i<t.size();i++){
		vector<float> bernstein;
		bernstein = Bernstein(Px.size()-1,t[i]);
		float xtemp=0.0;
		float ytemp=0.0;

		//compute the formula of bezier curve
		for(unsigned int j =0;j<Px.size();j++){
			xtemp+=Px[j]*bernstein[j];
			ytemp+=Py[j]*bernstein[j];
		}

		Bezierx.push_back(xtemp);
		Beziery.push_back(ytemp);
	}
	p.moveTo(Bezierx[0], Beziery[0]);
	for(unsigned int i = 1; i< N; i++){
		p.lineTo(Bezierx[i], Beziery[i]);
	}
	
    return p;
  }
};


class Curve2DBezierConstructor : public Curve2DConstructor {
 public:
  virtual ~Curve2DBezierConstructor()                     {}
  virtual const QString type() const                      { return "BezierCurve";             }
  virtual Curve2D *create(const QString &name)            { return new Curve2DBezier(name);   }
  virtual Curve2D *create(Curve2D *c,const QString &name) { return new Curve2DBezier(c,name); }
};

int factorial(int x){
	assert(x>=0);
	if(x==0){return 1;}
	int factorial=1;
	for(int i = 1; i <=x; ++i)
    	{
        factorial *= i;
    	}
	return factorial;
};

vector<float> Bernstein(int n, float t){
	vector<float> B;
	for(int i=0; i<n+1; i++){
		B.push_back((factorial(n)/(factorial(i)*factorial(n-i))*pow(t,i)*pow((1-t),(n-i))));

	}
	return B;
};



#endif // CURVE_2D_Bezier_H
