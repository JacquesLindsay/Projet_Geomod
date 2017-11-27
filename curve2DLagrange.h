#ifndef CURVE_2D_Lagrange_H
#define CURVE_2D_Lagrange_H

#include "curve2D.h"
using namespace std;
class Curve2DLagrange : public Curve2D {
 public:
 Curve2DLagrange(const QString &name) : Curve2D(name) {}
 Curve2DLagrange(Curve2D *curve,const QString &name) : Curve2D(curve,name) {}
  
  QPainterPath path(float frame) {
    QPainterPath p;
    if(nbPts()==0) 
      return p;

    Vector2f pt = evalAnimPt(get(0),frame);
    p.moveTo(pt[0],pt[1]);

	
	float s;
	float t;
	// K store the values of the Polynomial
	float k;
	vector<float> K;
	vector<int> x;
	vector<int> y;
	x.push_back(pt[0]);
	y.push_back(pt[1]);
	int N=1000;
	for(unsigned int i=1;i<nbPts();++i) {
		// Compute the Lagrange Polynomial
		pt=evalAnimPt(get(i),frame);
		x.push_back(pt[0]);
		y.push_back(pt[1]);
	}
	vector<float> a = array(x.front(),x.back(),N);
	for (unsigned int l=0;l<a.size();l++){
		k=0;
		for(unsigned int i=0; i<nbPts(); i++){
	    		s=1;
	    		t=1;
			
		    	for(unsigned int j=0; j<nbPts(); j++){
				if(j!=i && x[i]!=x[j]){
			    		s=s*(a[l]-x[j]);
			    		t=t*(x[i]-x[j]);
				}
		    	}
    		k=k+((s/t)*y[i]);
		}
		K.push_back(k);
	}

	//draw the curve:

	for (unsigned int i=0;i<K.size();i++){
		cout<<K[i]<<endl;
		p.lineTo(a[i],K[i]);		
		
	}
	
	return p;
	}
};


class Curve2DLagrangeConstructor : public Curve2DConstructor {
 public:
  virtual ~Curve2DLagrangeConstructor()                     {}
  virtual const QString type() const                      { return "LagrangeCurve";             }
  virtual Curve2D *create(const QString &name)            { return new Curve2DLagrange(name);   }
  virtual Curve2D *create(Curve2D *c,const QString &name) { return new Curve2DLagrange(c,name); }
};


#endif // CURVE_2D_Lagrange_H
