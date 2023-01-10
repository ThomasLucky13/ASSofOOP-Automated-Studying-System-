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
    Moduls/databasemanager.cpp \
    Moduls/labsstructures.cpp \
    Moduls/labsthemsmanager.cpp \
    Moduls/labstasksmanager.cpp \
    Widgets/fieldmethoddialog.cpp \
    Widgets/labfieldredaction.cpp \
    Widgets/labsRedactionModul.cpp \
    Widgets/labtaskreadctionmodul.cpp \
    Widgets/labtaskveiwmodul.cpp \
    Widgets/labthemeredaction.cpp \
    Widgets/tasksreadctionmodul.cpp \
    Widgets/testmodul.cpp \
    Widgets/themefriendsthemsredaction.cpp \
    Widgets/theorymodul.cpp \
    Widgets/labsmodul.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Moduls/contextHTMLManager.h \
    Moduls/databasemanager.h \
    Moduls/labsstructures.h \
    Moduls/labsthemsmanager.h \
    Moduls/labstasksmanager.h \
    Widgets/fieldmethoddialog.h \
    Widgets/labfieldredaction.h \
    Widgets/labsRedactionModul.h \
    Widgets/labtaskreadctionmodul.h \
    Widgets/labtaskveiwmodul.h \
    Widgets/labthemeredaction.h \
    Widgets/tasksreadctionmodul.h \
    Widgets/testmodul.h \
    Widgets/themefriendsthemsredaction.h \
    Widgets/theorymodul.h \
    Widgets/labsmodul.h \
    mainwindow.h

FORMS += \
    Widgets/fieldmethoddialog.ui \
    Widgets/labfieldredaction.ui \
    Widgets/labsRedactionModul.ui \
    Widgets/labtaskreadctionmodul.ui \
    Widgets/labtaskveiwmodul.ui \
    Widgets/labthemeredaction.ui \
    Widgets/tasksreadctionmodul.ui \
    Widgets/testmodul.ui \
    Widgets/themefriendsthemsredaction.ui \
    Widgets/theorymodul.ui \
    Widgets/labsmodul.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/ASSforOOP.qrc

DISTFILES += \
    resources/images/menuButton.svg
