#include "enemy2image.h"
#include "game.h"

extern game * Game;
enemy2image::enemy2image(QGraphicsItem * parent): QGraphicsPixmapItem(parent)
                         {
    if(Game->currentlevel == 0)
    {
                             QPixmap enemyimage("C:/Users/HP/Documents/Practice/enemy2resize.png");
                             enemyimage = enemyimage.scaledToHeight(45);
                             enemyimage = enemyimage.scaledToWidth(45);
                             setPixmap(enemyimage);
    }
    else if(Game->currentlevel == 1)
    {
        QPixmap enemy1("C:/Users/HP/Desktop/ProjectFinal/enemy21.png");
        enemy1 = enemy1.scaledToHeight(30);
        enemy1 = enemy1.scaledToWidth(30);
        setPixmap(enemy1);
    }
                          }


