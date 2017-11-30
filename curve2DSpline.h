#ifndef CURVE_2D_SPLINE_H
#define CURVE_2D_SPLINE_H

#include "curve2D.h"
#include <Eigen/IterativeLinearSolvers>
#include <math.h>

unsigned int N = 2000;

Vector2f baryzentric (Vector2f ptold,Vector2f pt, unsigned int j, unsigned int N){
	Vector2f temp;
	temp [0] = ptold[0]+(pt[0]-ptold[0])*j/N;
	temp [1] = ptold[1]+(pt[1]-ptold[1])*j/N;
	return temp;
};

class Curve2DSpline : public Curve2D {
	public:
	Curve2DSpline(const QString &name) : Curve2D(name) {}
 	Curve2DSpline(Curve2D *curve,const QString &name) : Curve2D(curve,name) {}
  	QPainterPath path(float frame) {
    	QPainterPath p;
    	if(nbPts()==0) 
      	    return p;
	vector<int> x;
	vector<int> y;
    	Vector2f pt = evalAnimPt(get(0),frame);
	x.push_back(pt[0]);
	y.push_back(pt[1]);
	vector<int> h;
    	p.moveTo(pt[0],pt[1]);
	h.push_back(0);
	for(unsigned int i=1;i<nbPts();i++) {
	    pt=evalAnimPt(get(i),frame);
	    x.push_back(pt[0]);
	    y.push_back(pt[1]);
        	if (i<nbPts())
		    h.push_back(x[i]-x[i-1]);
	    };
	if(nbPts()==1)
	    return p;
	else {
	    VectorXf A (nbPts()-1);
	    VectorXf B (nbPts()-1);
	    VectorXf M (nbPts());
	    M[0] = 0;
	    M[nbPts()-1] = 0;
	    vector<float> a = array(0.0,1.0,N); // stepsize for evaluation of the function used later 
	    if (nbPts()>2){
    	        VectorXf Mtemp (nbPts()-2);
   	        VectorXf tempvec (nbPts()-2);
                MatrixXf temp (nbPts()-2,nbPts()-2);
	        if (nbPts()>3){
		    for (unsigned int i=0;i<nbPts()-3;i++){
	                temp (i,i) = (float)(h[i+2]+h[i+1])/3.0;
		        temp (i,i+1) = (float)h[i+2]/6.0;
		        temp (i+1,i) = (float)h[i+2]/6.0;
		    };
	        };
		temp (nbPts()-3,nbPts()-3) = (float)(h[nbPts()-1]+h[nbPts()-2])/3.0;
		for (unsigned int i=0;i<nbPts()-2;i++){
	    	    tempvec[i] = (float)(y[i+2]-y[i+1])/(float)h[i+2]-(float)(y[i+1]-y[i])/(float)h[i+1];
	        };
	        Mtemp = temp.colPivHouseholderQr().solve(tempvec);
	        for (unsigned int i=0;i<nbPts()-2;i++){
		    M[i+1] = Mtemp[i];
	        };
	    };
	    for(unsigned int i=0;i<nbPts()-1;i++) {
		A[i] = (float)(y[i+1]-y[i])/(float)h[i+1]-(float)h[i+1]*(float)(M[i+1]-M[i])/6.0;
		B[i] = (float)y[i]-(float)M[i]*(float)h[i+1]*(float)h[i+1]/6.0;
	    };
	p.moveTo(x[0],y[0]);
	Vector2f pdraw;
	    for(unsigned int j=0;j<nbPts()-1;j++) {		
	        for(unsigned int i=1;i<=a.size();i++){
		    pdraw[0] = x[j]+(x[j+1]-x[j])*a[i];
		    pdraw[1] = M[j]*pow(x[j+1]-(x[j]+(x[j+1]-x[j])*a[i]),3.0)/6.0/h[j+1]+M[j+1]*pow((x[j+1]-x[j])*a[i],3.0)/6.0/h[j+1]+A[j]*(x[j+1]-x[j])*a[i]+B[j];
		    p.lineTo (pdraw[0], pdraw[1]);
	        };
	    };
        return p;
        };
    };
};
class Curve2DSplineConstructor : public Curve2DConstructor {
 public:
  virtual ~Curve2DSplineConstructor()                     {}
  virtual const QString type() const                      { return "SplineCurve";             }
  virtual Curve2D *create(const QString &name)            { return new Curve2DSpline(name);   }
  virtual Curve2D *create(Curve2D *c,const QString &name) { return new Curve2DSpline(c,name); }
};




#endif // CURVE_2D_SPLINE_H
