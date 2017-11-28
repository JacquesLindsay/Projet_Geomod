#ifndef ANIMATION_WIDGET_H
#define ANIMATION_WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QWheelEvent>
#include "animatedPoint.h"
#include "curve2D.h"
#include <vector>

using namespace std;

class MainWindow;
class AnimatedPointDrawer;

class AnimationWidget : public QGraphicsView {
  Q_OBJECT

    public:
  AnimationWidget(MainWindow *mainWindow,QWidget *parent=NULL);
  ~AnimationWidget();

  inline void refresh() {
    scene()->update(0,0,width(),height());
  }

  void selectionChanged();
  void resetResol();  

  inline void setResol(int w,int h) {
    setSceneRect(0,0,w,h);
  }

  inline void transform(vector<Curve2D*> curves) {
      clean();
      for(unsigned int i=0; i<curves.size(); i++){
          addAnimatedCurve(i);
          for (unsigned int j=0;j>curves.at(i)->nbPts();j++){
              addAnimatedPoint(i,j);
          }
      }
  }

 protected:
  virtual void drawForeground(QPainter * painter, const QRectF & rect);
  virtual void wheelEvent(QWheelEvent * event);

 private:
  void clean();
  void addAnimatedPoint(int curveInd,int ptInd);
  void addAnimatedCurve(int curveInd);
  void addAnimatedScene();

  MainWindow *_mainWindow;
  QGraphicsScene *_gscene;
  std::vector<AnimatedPointDrawer *> _animPts;
};

#endif // ANIMATION_WIDGET_H
