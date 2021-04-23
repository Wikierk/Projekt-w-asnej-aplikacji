QT       += core gui multimedia \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Asteroid.cpp \
    Bullet.cpp \
    DialogEnd.cpp \
    Game.cpp \
    Health.cpp \
    Opponent.cpp \
    Player.cpp \
    Score.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    Asteroid.h \
    Bullet.h \
    DialogEnd.h \
    Game.h \
    Health.h \
    MainWindow.h \
    Opponent.h \
    Player.h \
    Score.h

FORMS += \
    DialogEnd.ui \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
