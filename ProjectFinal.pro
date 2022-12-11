QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bigboss.cpp \
    bricks.cpp \
    bullet.cpp \
    bulletage.cpp \
    bulletbox.cpp \
    bulletshot.cpp \
    button.cpp \
    enemy1.cpp \
    enemy2.cpp \
    enemy2image.cpp \
    enemyimage.cpp \
    food.cpp \
    game.cpp \
    gateway.cpp \
    health.cpp \
    heart.cpp \
    house.cpp \
    housee.cpp \
    housemario.cpp \
    ice.cpp \
    infinity.cpp \
    main.cpp \
    monster.cpp \
    player.cpp \
    playerimage.cpp \
    power.cpp \
    powersqr.cpp \
    powersymbol.cpp \
    score.cpp

HEADERS += \
    bigboss.h \
    bricks.h \
    bullet.h \
    bulletage.h \
    bulletbox.h \
    bulletshot.h \
    button.h \
    enemy1.h \
    enemy2.h \
    enemy2image.h \
    enemyimage.h \
    food.h \
    game.h \
    gateway.h \
    health.h \
    heart.h \
    house.h \
    housee.h \
    housemario.h \
    ice.h \
    infinity.h \
    monster.h \
    player.h \
    playerimage.h \
    power.h \
    powersqr.h \
    powersymbol.h \
    score.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    BulletAge.png \
    OneDrive - Personal - Shortcut.lnk \
    Practice.pro.user \
    ProjectFinal.pro.user \
    Purple Bricks.jpeg \
    background.jpg \
    bigboss.png \
    bigboss2.png \
    brick22.png \
    bricks.png \
    bricks2.jpeg \
    bricks2.png \
    bricks4.png \
    bricks5.png \
    bullet.png \
    bulletbox.png \
    bulletshot.png \
    cherry.png \
    enemy1.png \
    enemy2.png \
    enemy21.png \
    enemy2resize.png \
    food.png \
    food2.png \
    gamename.png \
    gameover.png \
    gamephoto.jpg \
    gate4.png \
    heartp.png \
    house.png \
    house2.png \
    house33.png \
    housemario.png \
    ice.png \
    ice2.png \
    ice4.png \
    infinity.png \
    kirbyleft1.png \
    kirbyleft2.png \
    kirbyleft3.png \
    kirbyleftd1.png \
    kirbyleftd2.png \
    kirbyleftd3.png \
    kirbyright1.png \
    kirbyright2.png \
    kirbyright3.png \
    kirbyrightd1.png \
    kirbyrightd2.png \
    kirbyrightd3.png \
    kirbyupleft1.png \
    kirbyupleft2.png \
    kirbyupleft3.png \
    kirbyupright1.png \
    kirbyupright2.png \
    kirbyupright3.png \
    map.txt \
    map2.txt.txt \
    maze22.txt \
    maze222.txt \
    maze3.txt \
    power.png \
    powersqr.png \
    powersymbol.png \
    tree.png \
    tree2.png \
    tree3.png \
    youwin.png
