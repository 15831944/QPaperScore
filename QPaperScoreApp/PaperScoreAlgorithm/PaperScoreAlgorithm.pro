#-------------------------------------------------
#
# Project created by QtCreator 2020-04-10T09:56:45
#
#-------------------------------------------------

QT       += core gui

TARGET = PaperScoreAlgorithm
TEMPLATE = lib

DEFINES += PAPERSCOREALGORITHM_EXPORTS

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ScoreDll.cpp \
        cvAlgorithm.cpp

HEADERS += \
        ScoreDll.h \
        cvAlgorithm.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$(OPENCV_HOME)/x64/vc15/lib/ -lopencv_world3410
else:win32:CONFIG(debug, debug|release): LIBS += -L$$(OPENCV_HOME)/x64/vc15/lib/ -lopencv_world3410d
else:unix: LIBS += -L$$(OPENCV_HOME)/x64/vc15/lib/ -lopencv_world3410

INCLUDEPATH += $$(OPENCV_HOME)/include
DEPENDPATH += $$(OPENCV_HOME)/x64/vc15
