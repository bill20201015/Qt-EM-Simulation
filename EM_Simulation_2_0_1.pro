QT       += core gui
QT       += printsupport
QT       += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialogset.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp \
    qcustomplot.cpp \
    inputline.cpp

HEADERS += \
    dialogset.h \
    mainwindow.h \
    model.h \
    qcustomplot.h \
    inputline.h

FORMS += \
    dialogset.ui \
    inputline.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



RESOURCES += \
    src.qrc

DISTFILES +=


win32: LIBS += -L$$PWD/include/ -lsingleLine
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/include/ -lsingleLined

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

INCLUDEPATH += E:/Matlab/extern/include
INCLUDEPATH += E:/Matlab/extern/include/Win64

# 用到的MATLAB 的.lib库文件 及其搜索路径
INCLUDEPATH += E:/Matlab/extern/lib/win64/microsoft
DEPENDPATH += E:/Matlab/extern/lib/win64/microsoft

win32: LIBS += -LE:/Matlab/extern/lib/win64/microsoft/ -llibmex
win32: LIBS += -LE:/Matlab/extern/lib/win64/microsoft/ -llibmx
win32: LIBS += -LE:/Matlab/extern/lib/win64/microsoft/ -llibmat
win32: LIBS += -LE:/Matlab/extern/lib/win64/microsoft/ -llibeng
win32: LIBS += -LE:/Matlab/extern/lib/win64/microsoft/ -lmclmcr
win32: LIBS += -LE:/Matlab/extern/lib/win64/microsoft/ -lmclmcrrt


