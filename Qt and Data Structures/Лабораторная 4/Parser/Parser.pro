QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../build-StringDLL-Desktop_x86_windows_msvc2022_pe_64bit-Debug/release/ -lStringDLL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../build-StringDLL-Desktop_x86_windows_msvc2022_pe_64bit-Debug/debug/ -lStringDLL

INCLUDEPATH += $$PWD/../../../../StringDLL
DEPENDPATH += $$PWD/../../../../StringDLL
