QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adddialog.cpp \
    dialog.cpp \
    doubleclick.cpp \
    list.cpp \
    main.cpp \
    mainwindow.cpp \
    workshop.cpp

HEADERS += \
    adddialog.h \
    dialog.h \
    doubleclick.h \
    list.h \
    mainwindow.h \
    workshop.h

FORMS += \
    adddialog.ui \
    dialog.ui \
    doubleclick.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
