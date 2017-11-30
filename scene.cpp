#include "scene.h"

// add all your types of 2D curves here 
#include "curve2DLinear.h"
#include "curve2DLinearClosed.h"
#include "curve2DBezier.h"
#include "curve2DCircle.h"
#include "curve2DCircleRadius.h"
#include "curve2DLagrange.h"
#include "curve2DSpline.h"
#include "curve2DCasteljau.h"
#include "curve1DLinear.h"
#include "curve1DLeastSquares.h"


Scene *Scene::_instance = NULL;

using namespace std;

// add 2D curve builders here 
void Scene::initCurveBuilders() {
  addCurveBuilder(new Curve2DLinearConstructor());
  addCurveBuilder(new Curve2DLinearClosedConstructor());
  addCurveBuilder(new Curve2DBezierConstructor());
  addCurveBuilder(new Curve2DCircleConstructor());
  addCurveBuilder(new Curve2DCircleRadiusConstructor());
  addCurveBuilder(new Curve2DLagrangeConstructor());
  addCurveBuilder(new Curve2DSplineConstructor());
  addCurveBuilder(new Curve2DCasteljauConstructor());
}


// add 1D curve builders (functions) here
void Scene::initFunctionBuilders() {
  addFunctionBuilder(new Curve1DLinearConstructor());
  addFunctionBuilder(new Curve1DLeastSquaresConstructor());
}


void Scene::cleanCurveBuilders() {
  map<QString,Curve2DConstructor *>::const_iterator mit(_curveBuilders.begin()),mend(_curveBuilders.end());
  
  for(;mit!=mend;++mit) { 
    delete mit->second; 
  }

  _curveBuilders.clear();
}

void Scene::cleanFunctionBuilders() {
  map<QString,Curve1DConstructor *>::const_iterator mit(_functionBuilders.begin()),mend(_functionBuilders.end());
  
  for(;mit!=mend;++mit) { 
    delete mit->second; 
  }

  _functionBuilders.clear();
}


Scene::Scene() {
  initFunctionBuilders();
  initCurveBuilders();
  setDefaultSettings();
}

Scene::~Scene() {
  clean();
  cleanFunctionBuilders();
  cleanCurveBuilders();
}

