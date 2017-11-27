#############################################################################
# Makefile for building: CurveMaster
# Generated by qmake (2.01a) (Qt 4.8.7) on: lun. nov. 27 14:05:56 2017
# Project:  main.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -o Makefile main.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -std=c++11 -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-unused-but-set-variable -Wno-misleading-indentation -Wno-deprecated-declarations -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -Ieigen -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainWidget.cpp \
		toolsWidget.cpp \
		drawingWidgetItems.cpp \
		drawingWidget.cpp \
		animationWidgetItems.cpp \
		animationWidget.cpp \
		scene.cpp \
		animatedPoint.cpp moc_mainWidget.cpp \
		moc_toolsWidget.cpp \
		moc_drawingWidget.cpp \
		moc_animationWidget.cpp
OBJECTS       = main.o \
		mainWidget.o \
		toolsWidget.o \
		drawingWidgetItems.o \
		drawingWidget.o \
		animationWidgetItems.o \
		animationWidget.o \
		scene.o \
		animatedPoint.o \
		moc_mainWidget.o \
		moc_toolsWidget.o \
		moc_drawingWidget.o \
		moc_animationWidget.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		main.pro
QMAKE_TARGET  = CurveMaster
DESTDIR       = 
TARGET        = CurveMaster

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: main.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile main.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile main.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/CurveMaster1.0.0 || $(MKDIR) .tmp/CurveMaster1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/CurveMaster1.0.0/ && $(COPY_FILE) --parents mainWidget.h toolsWidget.h drawingWidgetItems.h drawingWidget.h animationWidgetItems.h animationWidget.h scene.h curve1D.h curve2D.h curve1DLinear.h curve2DLinear.h curve2DLinearClosed.h curve2DBezier.h curve2DLagrange.h curve2DCircle.h curve2DCircleRadius.h animatedPoint.h .tmp/CurveMaster1.0.0/ && $(COPY_FILE) --parents main.cpp mainWidget.cpp toolsWidget.cpp drawingWidgetItems.cpp drawingWidget.cpp animationWidgetItems.cpp animationWidget.cpp scene.cpp animatedPoint.cpp .tmp/CurveMaster1.0.0/ && (cd `dirname .tmp/CurveMaster1.0.0` && $(TAR) CurveMaster1.0.0.tar CurveMaster1.0.0 && $(COMPRESS) CurveMaster1.0.0.tar) && $(MOVE) `dirname .tmp/CurveMaster1.0.0`/CurveMaster1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/CurveMaster1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainWidget.cpp moc_toolsWidget.cpp moc_drawingWidget.cpp moc_animationWidget.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainWidget.cpp moc_toolsWidget.cpp moc_drawingWidget.cpp moc_animationWidget.cpp
moc_mainWidget.cpp: toolsWidget.h \
		drawingWidget.h \
		curve2D.h \
		animatedPoint.h \
		curve1D.h \
		animationWidget.h \
		mainWidget.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) mainWidget.h -o moc_mainWidget.cpp

moc_toolsWidget.cpp: toolsWidget.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) toolsWidget.h -o moc_toolsWidget.cpp

moc_drawingWidget.cpp: curve2D.h \
		animatedPoint.h \
		curve1D.h \
		drawingWidget.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) drawingWidget.h -o moc_drawingWidget.cpp

moc_animationWidget.cpp: animatedPoint.h \
		curve1D.h \
		animationWidget.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) animationWidget.h -o moc_animationWidget.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

main.o: main.cpp mainWidget.h \
		toolsWidget.h \
		drawingWidget.h \
		curve2D.h \
		animatedPoint.h \
		curve1D.h \
		animationWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainWidget.o: mainWidget.cpp mainWidget.h \
		toolsWidget.h \
		drawingWidget.h \
		curve2D.h \
		animatedPoint.h \
		curve1D.h \
		animationWidget.h \
		scene.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainWidget.o mainWidget.cpp

toolsWidget.o: toolsWidget.cpp mainWidget.h \
		toolsWidget.h \
		drawingWidget.h \
		curve2D.h \
		animatedPoint.h \
		curve1D.h \
		animationWidget.h \
		scene.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o toolsWidget.o toolsWidget.cpp

drawingWidgetItems.o: drawingWidgetItems.cpp drawingWidgetItems.h \
		drawingWidget.h \
		curve2D.h \
		animatedPoint.h \
		curve1D.h \
		scene.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o drawingWidgetItems.o drawingWidgetItems.cpp

drawingWidget.o: drawingWidget.cpp drawingWidget.h \
		curve2D.h \
		animatedPoint.h \
		curve1D.h \
		mainWidget.h \
		toolsWidget.h \
		animationWidget.h \
		scene.h \
		drawingWidgetItems.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o drawingWidget.o drawingWidget.cpp

animationWidgetItems.o: animationWidgetItems.cpp animationWidgetItems.h \
		animationWidget.h \
		animatedPoint.h \
		curve1D.h \
		scene.h \
		curve2D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o animationWidgetItems.o animationWidgetItems.cpp

animationWidget.o: animationWidget.cpp animationWidget.h \
		animatedPoint.h \
		curve1D.h \
		mainWidget.h \
		toolsWidget.h \
		drawingWidget.h \
		curve2D.h \
		scene.h \
		animationWidgetItems.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o animationWidget.o animationWidget.cpp

scene.o: scene.cpp scene.h \
		curve2D.h \
		animatedPoint.h \
		curve1D.h \
		curve2DLinear.h \
		curve2DLinearClosed.h \
		curve2DBezier.h \
		curve2DCircle.h \
		curve2DCircleRadius.h \
		curve2DLagrange.h \
		curve1DLinear.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o scene.o scene.cpp

animatedPoint.o: animatedPoint.cpp animatedPoint.h \
		curve1D.h \
		scene.h \
		curve2D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o animatedPoint.o animatedPoint.cpp

moc_mainWidget.o: moc_mainWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainWidget.o moc_mainWidget.cpp

moc_toolsWidget.o: moc_toolsWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_toolsWidget.o moc_toolsWidget.cpp

moc_drawingWidget.o: moc_drawingWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_drawingWidget.o moc_drawingWidget.cpp

moc_animationWidget.o: moc_animationWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_animationWidget.o moc_animationWidget.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

