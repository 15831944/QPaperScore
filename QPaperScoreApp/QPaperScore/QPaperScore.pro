#-------------------------------------------------
#
# Project created by QtCreator 2020-04-10T10:21:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QPaperScore
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        PublicFunction.cpp \
        QPaperScore.cpp \
        QWaitDialog.cpp \
        main.cpp

HEADERS += \
    PublicFunction.h \
    QPaperScore.h \
    QWaitDialog.h

FORMS += \
        QPaperScore.ui \
        WaitDialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../PaperScoreAlgorithm/release/ -lPaperScoreAlgorithm
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../PaperScoreAlgorithm/debug/ -lPaperScoreAlgorithm
else:unix: LIBS += -L$$OUT_PWD/../PaperScoreAlgorithm/ -lPaperScoreAlgorithm

INCLUDEPATH += $$PWD/../PaperScoreAlgorithm
DEPENDPATH += $$PWD/../PaperScoreAlgorithm

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QtPicture/release/ -lQtPicture
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QtPicture/debug/ -lQtPicture
else:unix: LIBS += -L$$OUT_PWD/../QtPicture/ -lQtPicture

INCLUDEPATH += $$PWD/../QtPicture
DEPENDPATH += $$PWD/../QtPicture

win32:CONFIG(release, debug|release): LIBS += -L$$(OPENCV_HOME)/x64/vc15/lib/ -lopencv_world3410
else:win32:CONFIG(debug, debug|release): LIBS += -L$$(OPENCV_HOME)/x64/vc15/lib/ -lopencv_world3410d
else:unix: LIBS += -L$$(OPENCV_HOME)/x64/vc15/lib/ -lopencv_world3410

INCLUDEPATH += $$(OPENCV_HOME)/include
DEPENDPATH += $$(OPENCV_HOME)/x64/vc15
