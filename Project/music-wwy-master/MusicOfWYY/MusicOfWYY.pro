#-------------------------------------------------
#
# Project created by QtCreator 2021-08-13T21:14:42
#
#-------------------------------------------------

QT       += core gui
QT	+= multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = MusicOfWYY
TEMPLATE = app
DESTDIR = $$PWD/bin
RC_ICONS = $$PWD/bin/images/logoRed.ico

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
        changecolorform.cpp \
        galleryitem.cpp \
        galleryprivate.cpp \
        main.cpp \
        allmain.cpp \
        messageform.cpp \
        messageitem.cpp \
        musicform.cpp \
        newcourier.cpp \
        newcourieritem.cpp \
        newdisc.cpp \
        personform.cpp \
        picturebutton.cpp \
        pictureitem.cpp \
        pictureview.cpp \
        picturewidget.cpp \
        rankingitem.cpp \
        searchform.cpp \
        searchitem.cpp

HEADERS += \
        allmain.h \
        changecolorform.h \
        galleryitem.h \
        galleryprivate.h \
        loadfileqss.h \
        messageform.h \
        messageitem.h \
        musicform.h \
        newcourier.h \
        newcourieritem.h \
        newdisc.h \
        personform.h \
        picturebutton.h \
        pictureitem.h \
        pictureview.h \
        picturewidget.h \
        rankingitem.h \
        searchform.h \
        searchitem.h

FORMS += \
        allmain.ui \
        changecolorform.ui \
        galleryitem.ui \
        messageform.ui \
        messageitem.ui \
        musicform.ui \
        newcourier.ui \
        newcourieritem.ui \
        newdisc.ui \
        personform.ui \
        picturewidget.ui \
        rankingitem.ui \
        searchform.ui \
        searchitem.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
