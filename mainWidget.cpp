#include "mainWidget.h"

#include <iostream>
#include <QDebug>
#include <QMenuBar>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QCloseEvent>
#include <QSplitter>

#include "scene.h"

using namespace std;

const QString MainWindow::_DEFAULT_FILE_NAME = "untitled";
const QString MainWindow::_APPLICATION_NAME = "CurveMaster";
const QString MainWindow::_APPLICATION_EXTENSION = ".cm";
QDir MainWindow::_CURRENT_PATH = QDir::currentPath();

MainWindow::MainWindow()
  : QMainWindow(),
    _timer(new QTimer(this)) {

   createActions();
   createMenus();

   _toolsWidget = new ToolsWidget(this);
   _drawingWidget = new DrawingWidget(this);
   _animationWidget = new AnimationWidget(this);

   QSplitter *sp1 = new QSplitter(Qt::Horizontal);
   QSplitter *sp2 = new QSplitter(Qt::Vertical);

   sp2->addWidget(_drawingWidget);
   sp2->addWidget(_animationWidget);
   sp1->addWidget(_toolsWidget);
   sp1->addWidget(sp2);

   sp1->setStretchFactor(0,1);
   sp1->setStretchFactor(1,10);
   sp2->setStretchFactor(0,8);
   sp2->setStretchFactor(1,1);

   connect(_timer,SIGNAL(timeout()),this,SLOT(timerEvent()));

   setCurrentFile(_DEFAULT_FILE_NAME);
   setCentralWidget(sp1);
}

MainWindow::~MainWindow() {
  // delete widgets here
}

void MainWindow::timerEvent() {
  Scene *sce = Scene::get();
  sce->setCurrentFrame((sce->currentFrame()+1)%sce->nbFrames());
  _drawingWidget->frameChanged();
  _toolsWidget->updateFrameNumber();
  refresh();
}


void MainWindow::createActions() {
  _newAct = new QAction(tr("&New"), this);
  _newAct->setShortcuts(QKeySequence::New);
  _newAct->setStatusTip(tr("Create a new file"));
  connect(_newAct,SIGNAL(triggered()),this,SLOT(newFile()));

  _openAct = new QAction(tr("&Open..."), this);
  _openAct->setShortcuts(QKeySequence::Open);
  _openAct->setStatusTip(tr("Open an existing file"));
  connect(_openAct,SIGNAL(triggered()),this,SLOT(open()));

  _saveAct = new QAction(tr("&Save"), this);
  _saveAct->setShortcuts(QKeySequence::Save);
  _saveAct->setStatusTip(tr("Save the document to disk"));
  connect(_saveAct,SIGNAL(triggered()),this,SLOT(save()));

  _saveAsAct = new QAction(tr("&Save As"), this);
  _saveAsAct->setShortcuts(QKeySequence::SaveAs);
  _saveAsAct->setStatusTip(tr("Save the document under another name"));
  connect(_saveAsAct,SIGNAL(triggered()),this,SLOT(saveAs()));

  _exitAct = new QAction(tr("&Exit"), this);
  _exitAct->setShortcuts(QKeySequence::Quit);
  _exitAct->setStatusTip(tr("Exit the application"));
  connect(_exitAct,SIGNAL(triggered()),this,SLOT(closeAppli()));

  _helpAct = new QAction(tr("&Help"), this);
  _helpAct->setStatusTip(tr("Show the application's Help"));
  connect(_helpAct,SIGNAL(triggered()),this,SLOT(help()));

  _aboutAct = new QAction(tr("&About"), this);
  _aboutAct->setStatusTip(tr("Show the application's About box"));
  connect(_aboutAct,SIGNAL(triggered()),this,SLOT(about()));

  Qt::Modifier frameNavModifier;
#ifdef __APPLE__
  // specific shortcut on OS X
  frameNavModifier = Qt::CTRL;
#else
  frameNavModifier = Qt::SHIFT;
#endif

  _nextFrameAct = new QAction(tr("Next Frame"), this);
  _nextFrameAct->setShortcut(QKeySequence(frameNavModifier + Qt::Key_Right));
  _nextFrameAct->setStatusTip(tr("Increment current frame"));
  connect(_nextFrameAct,SIGNAL(triggered()),this,SLOT(nextFrame()));

  _prevFrameAct = new QAction(tr("Prev Frame"), this);
  _prevFrameAct->setShortcut(QKeySequence(frameNavModifier + Qt::Key_Left));
  _prevFrameAct->setStatusTip(tr("Decrement current frame"));
  connect(_prevFrameAct,SIGNAL(triggered()),this,SLOT(prevFrame()));

  _firstFrameAct = new QAction(tr("First Frame"), this);
  _firstFrameAct->setShortcut(QKeySequence(frameNavModifier + Qt::Key_Up));
  _firstFrameAct->setStatusTip(tr("Cursor at the first frame"));
  connect(_firstFrameAct,SIGNAL(triggered()),this,SLOT(firstFrame()));

  _lastFrameAct = new QAction(tr("Last Frame"), this);
  _lastFrameAct->setShortcut(QKeySequence(frameNavModifier + Qt::Key_Down));
  _lastFrameAct->setStatusTip(tr("Cursor at the last frame"));
  connect(_lastFrameAct,SIGNAL(triggered()),this,SLOT(lastFrame()));

  _playAct = new QAction(tr("Play"), this);
  _playAct->setShortcut(QKeySequence(Qt::Key_P));
  _playAct->setStatusTip(tr("Start animation"));
  connect(_playAct,SIGNAL(triggered()),this,SLOT(play()));

  _stopAct = new QAction(tr("Stop"), this);
  _stopAct->setShortcut(QKeySequence(Qt::SHIFT + Qt::Key_P));
  _stopAct->setStatusTip(tr("Stop animation"));
  connect(_stopAct,SIGNAL(triggered()),this,SLOT(stop()));
}

void MainWindow::createMenus() {
  _fileMenu = menuBar()->addMenu(tr("&File"));
  _fileMenu->addAction(_newAct);
  _fileMenu->addAction(_openAct);
  _fileMenu->addAction(_saveAct);
  _fileMenu->addAction(_saveAsAct);
  _fileMenu->addSeparator();
  _fileMenu->addAction(_exitAct);



  _animMenu = menuBar()->addMenu(tr("&Animate"));
  _animMenu->addAction(_playAct);
  _animMenu->addAction(_stopAct);
  _animMenu->addSeparator();
  _animMenu->addAction(_nextFrameAct);
  _animMenu->addAction(_prevFrameAct);
  _animMenu->addAction(_firstFrameAct);
  _animMenu->addAction(_lastFrameAct);

  _helpMenu = menuBar()->addMenu(tr("&Info"));
  _helpMenu->addAction(_helpAct);
  _helpMenu->addAction(_aboutAct);
 }

void MainWindow::newFile() {
    if(Scene::get()->nbCurves()>0){
        if(maybeSave()) {
            clearAll();
            setCurrentFile(_DEFAULT_FILE_NAME);
        }
    }
    else{
        setCurrentFile(_DEFAULT_FILE_NAME);
    }
}

void MainWindow::open() {
    QString selectedfilter = "CurveMaster files (*"+_APPLICATION_EXTENSION+")";
    QString filter = selectedfilter+";; All files (*)";
    QString name = QFileDialog::getOpenFileName(this, "Open file", "", filter, &selectedfilter);
    QFile file(name);
    if (file.open(QIODevice::ReadOnly) && !name.isEmpty() && !name.isNull())
    {
        setCurrentFile(name.section(".",0,0).split('/').last());
        QTextStream stream(&file);
        QString data = stream.readAll();
        Scene *sce = Scene::get();
        vector<Curve2D*> curves = sce->stringToData(data);
        _drawingWidget->transform(curves);
        _animationWidget->transform(curves);
    }

}

bool MainWindow::save() {
  if(_currentFile.isEmpty() or _currentFile==_DEFAULT_FILE_NAME) {
    return saveAs();
  }
  else{
      Scene *sce = Scene::get();
      QString data = sce->dataToString();
      QString name=_CURRENT_PATH.canonicalPath()+_currentFile;
      if(!name.contains(_APPLICATION_EXTENSION)){
          name.append(_APPLICATION_EXTENSION);
      }
      QFile file(name);
      if (file.open(QIODevice::WriteOnly))
      {
          QTextStream stream(&file);
          stream << data << endl;
          file.close();
          return true;
      }
      return false;
  }
}

bool MainWindow::saveAs() {
    Scene *sce = Scene::get();
    QString data = sce->dataToString();
    QString selectedfilter = "CurveMaster files (*"+_APPLICATION_EXTENSION+")";
    QString filter = selectedfilter+";; All files (*)";
    QString name = QFileDialog::getSaveFileName(this, "Save file", "", filter, &selectedfilter);
    if(name!=""){
        if(!name.contains(_APPLICATION_EXTENSION)){
            name.append(_APPLICATION_EXTENSION);
        }
        QFile file(name);
        if (file.open(QIODevice::WriteOnly) && !name.isEmpty() && !name.isNull())
        {
            setCurrentFile(name.section(".",0,0).split('/').last());
            QTextStream stream(&file);
            stream << data << endl;
            file.close();
            return true;
        }
    }
  return false;
}

void MainWindow::help() {
  QFile readme("HEL.txt");
  if(readme.open(QIODevice::ReadOnly | QIODevice::Text)){
      QString content = readme.readAll();
      QMessageBox::information(this, "Help", content);
  }
  else{
      QMessageBox::critical(this, "Help", "ERROR: HELP NOT FOUND");
  }
  readme.close();
}

void MainWindow::about() {
  QString h = tr("<center><font size='12'>CurveMaster v. 1.74</font></center><br>"
         "Copyright (C) 2017 <br>"
         "Jacques Lindsay"
         " <a href='jacques.lindsay@orange.fr'>jacques.lindsay@orange.fr</a> <br>"
         );

  QMessageBox::about(this,"About",h);
}

bool MainWindow::closeAppli() {
     return close();
}

void MainWindow::nextFrame() {
    _toolsWidget->nextClicked();
}

void MainWindow::prevFrame() {
  _toolsWidget->prevClicked();
}

void MainWindow::firstFrame() {
    Scene *sce = Scene::get();

    sce->setCurrentFrame(0);
    _toolsWidget->updateFrameNumber();
    frameChanged();
    refresh();
}

void MainWindow::lastFrame() {
    Scene *sce = Scene::get();

    sce->setCurrentFrame(sce->nbFrames()-1);
    _toolsWidget->updateFrameNumber();
    frameChanged();
    refresh();
}

void MainWindow::play() {
    playAnimation();
}

void MainWindow::stop() {
    stopAnimation();
}

void MainWindow::settings() {
  int a=0;
  /*AnimationSettings *w = new AnimationSettings(_graphWidget);
  w->show();*/
}

bool MainWindow::maybeSave() {
   QMessageBox::StandardButton ret;
   ret = QMessageBox::warning(this,tr("Question"),tr("Do you want to save your scene?"),
                 QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
   if(ret==QMessageBox::Save)
     return save();
   else if(ret==QMessageBox::Cancel)
     return false;
  return true;
}

void MainWindow::clearAll() {
  _drawingWidget->deleteAllCurves();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if(Scene::get()->nbCurves()==0){
        event->accept();
    }
    else{
        if(maybeSave()) {
            clearAll();
        event->accept();
        } else {
            event->ignore();
        }
    }
}

void MainWindow::setCurrentFile(const QString &fileName) {
  _currentFile = fileName;
  QString shownName = _currentFile;
  if(_currentFile.isEmpty())
    shownName = _DEFAULT_FILE_NAME+_APPLICATION_EXTENSION;
  setWindowFilePath(shownName);
  setWindowTitle(_currentFile + " | " + _APPLICATION_NAME);
}

void MainWindow::playAnimation() {
  if(!Scene::get()->isAnimated()) {
    _timer->setInterval((int)(1000.0f/(float)Scene::get()->fps()));
    _timer->start();
    Scene::get()->setAnimated(true);
  }
}

void MainWindow::stopAnimation() {
  if(Scene::get()->isAnimated()) {
    _timer->stop();
    Scene::get()->setAnimated(false);
  }
}

void MainWindow::sceneSizeChanged() {
  Scene *sce = Scene::get();
  _drawingWidget->setResol(sce->width(),sce->height());
}

void MainWindow::nbFramesChanged() {
  _animationWidget->resetResol();
  _animationWidget->refresh();
}

void MainWindow::fpsChanged() {
  _timer->setInterval((int)(1000.0f/(float)Scene::get()->fps()));
}
