QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clientwindow.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    myclient.cpp \
    myserver.cpp \
    player.cpp \
    rules.cpp \
    serverwindow.cpp

HEADERS += \
    clientwindow.h \
    mainmenu.h \
    mainwindow.h \
    myclient.h \
    myserver.h \
    player.h \
    rules.h \
    serverwindow.h

FORMS += \
    clientwindow.ui \
    mainmenu.ui \
    mainwindow.ui \
    rules.ui \
    serverwindow.ui

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
