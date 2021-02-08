QT       += core gui

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
    add.cpp \
    change.cpp \
    create.cpp \
    functions.cpp \
    light.cpp \
    main.cpp \
    mainwindow.cpp \
    open.cpp \
    remove.cpp \
    search.cpp \
    start.cpp \
    text.cpp

HEADERS += \
    add.h \
    change.h \
    create.h \
    functions.h \
    light.h \
    mainwindow.h \
    open.h \
    remove.h \
    search.h \
    start.h \
    text.h

FORMS += \
    add.ui \
    change.ui \
    create.ui \
    mainwindow.ui \
    open.ui \
    remove.ui \
    search.ui \
    start.ui \
    text.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../build-Pointer-Desktop_Qt_5_13_1_MSVC2017_32bit-Debug/change.png \
    ../build-Pointer-Desktop_Qt_5_13_1_MSVC2017_32bit-Debug/find.png \
    add.png \
    file.png

RESOURCES += \
    resource.qrc
