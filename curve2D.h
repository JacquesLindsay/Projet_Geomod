#ifndef CURVE_2D_H
#define CURVE_2D_H

#include <Eigen/Dense>
#include <Eigen/StdVector>
#include <vector>
#include <assert.h>
#include <QString>
#include <QPainterPath>
#include <QColor>
#include<math.h>
#include<iostream>
#include "animatedPoint.h"

using namespace Eigen;
using namespace std;
class Curve2D {
 public:
  typedef Vector2f AnimPt;
  
 Curve2D(const QString &name) : _name(name) {}
 Curve2D(Curve2D *curve,const QString &name)
   : _name(name),
    _penColor(0,0,0,255),
    _brushColor(255,255,255,0),
    _penWidth(1) {
    assert(curve!=NULL);
    for(unsigned int i=0;i<curve->nbPts();++i) {
      add(curve->get(i));
    }
  }
 
//function which compute factorial
	long factorial(int x){
		assert(x>=0);
		if(x==0){return 1;}
		long factorial=1;
		for(int i = 1; i <=x; ++i)
	    	{
		factorial *= i;
	    	}
		return factorial;
};

//function which compute Bernstein polynomials
	vector<double> Bernstein(int n, float t){
		vector<double> B;
		for(int i=0; i<n+1; i++){
			B.push_back((factorial(n)/(factorial(i)*factorial(n-i))*pow(t,i)*pow((1-t),(n-i))));

		}
		return B;
};
// kind of numpy.linspace(begin,end,number)
	vector<float> array(float begin,float end,unsigned int number){
		float step=(end-begin)/number;
		vector<float> t;
		for(float i= 0.0; t.size()<=number; i+=step){
			t.push_back(i);
		}
		return t;
	}

  virtual ~Curve2D() {
    clear();
  }

  inline virtual void add(float x,float y) {
    _points.push_back(new AnimatedPoint(x,y));
  }

  inline virtual void add(AnimatedPoint *pt) {
    _points.push_back(new AnimatedPoint(pt));
  }
  
  inline virtual void set(unsigned int i,float x,float y) {
    assert(i<nbPts());
    _points[i]->setCurrent(Vector2f(x,y));
  }
  
  
  inline virtual void addBefore(unsigned int i,float x,float y) {
    assert(i<nbPts());
    _points.insert(_points.begin()+i,new AnimatedPoint(x,y));
  }

  inline virtual void addAfter(unsigned int i,float x,float y) {
    assert(i<nbPts());
    _points.insert(_points.begin()+i+1,new AnimatedPoint(x,y));
  }

  inline virtual void del(unsigned int i) {
    assert(i<nbPts());
    delete _points[i];
    _points.erase(_points.begin()+i);
  }

  inline virtual AnimatedPoint *get(unsigned int i) const {
    assert(i<nbPts());
    return _points[i];
  }
  
  inline virtual void clear() {
    _points.clear();
  }
  
  inline unsigned int nbPts() const {
    return static_cast<unsigned int>(_points.size());
  }

  inline bool empty() const {
    return nbPts()==0;
  }

  inline Vector2f evalAnimPt(AnimatedPoint *pt,float f) {
    return pt->evalAt(f);
  }

  inline QString name() const {
    return _name;
  }

  inline void setName(const QString &name) {
    _name = name;
  }

  inline QColor penColor() const {
    return _penColor;
  }

  inline QColor brushColor() const {
    return _brushColor;
  }

  inline int penWidth() const {
    return _penWidth;
  }

  inline void setPenColor(const QColor &c) {
    _penColor = c;
  }

  inline void setBrushColor(const QColor &c) {
    _brushColor = c;
  }

  inline void setPenWidth(int w) {
    _penWidth = w;
  }

  virtual QPainterPath path(float frame) = 0;

 protected:
  std::vector<AnimatedPoint *> _points;
  QString             _name;

 private:
  // style settings
  QColor _penColor;
  QColor _brushColor;
  int    _penWidth;
  
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};


class Curve2DConstructor {
 public:
  virtual ~Curve2DConstructor() {}
  virtual const QString type() const = 0;
  virtual Curve2D *create(const QString &) = 0;
  virtual Curve2D *create(Curve2D *,const QString &) = 0;
};


#endif // CURVE_2D_H
