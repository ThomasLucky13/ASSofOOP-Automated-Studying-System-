QT       += core gui
QT       += webenginewidgets
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Moduls/contextHTMLManager.cpp \
    Moduls/labsstructures.cpp \
    Moduls/labsthemsmanager.cpp \
    Widgets/fieldmethoddialog.cpp \
    Widgets/labfieldredaction.cpp \
    Widgets/labsmodul.cpp \
    Widgets/labthemeredaction.cpp \
    Widgets/testmodul.cpp \
    Widgets/theorymodul.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Moduls/contextHTMLManager.h \
    Moduls/labsstructures.h \
    Moduls/labsthemsmanager.h \
    Widgets/fieldmethoddialog.h \
    Widgets/labfieldredaction.h \
    Widgets/labsmodul.h \
    Widgets/labthemeredaction.h \
    Widgets/testmodul.h \
    Widgets/theorymodul.h \
    mainwindow.h

FORMS += \
    Widgets/fieldmethoddialog.ui \
    Widgets/labfieldredaction.ui \
    Widgets/labsmodul.ui \
    Widgets/labthemeredaction.ui \
    Widgets/testmodul.ui \
    Widgets/theorymodul.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/ASSforOOP.qrc

DISTFILES += \
    resources/images/menuButton.svg
