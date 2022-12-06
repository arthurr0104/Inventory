QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gameBoard/gameBoard.cpp \
    gameBoard/inventory.cpp \
    main.cpp \
    mainWindow/mainMenu.cpp \
    mainWindow/mainwindow.cpp \
    gameBoard/object.cpp \
    gameBoard/strings.cpp

HEADERS += \
    gameBoard/gameBoard.h \
    gameBoard/inventory.h \
    mainWindow/mainMenu.h \
    mainWindow/mainwindow.h \
    gameBoard/object.h \
    gameBoard/strings.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    res/images.qrc
