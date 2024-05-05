QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cities.cpp \
    instructions.cpp \
    main.cpp \
    mainwindow.cpp \
    navigate.cpp \
    paths.cpp \
    welcomepage.cpp

HEADERS += \
    cities.h \
    instructions.h \
    mainwindow.h \
    navigate.h \
    paths.h \
    welcomepage.h

FORMS += \
    cities.ui \
    instructions.ui \
    mainwindow.ui \
    navigate.ui \
    paths.ui \
    welcomepage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
