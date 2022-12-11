#include "enemyimage.h"
#include "game.h"
extern game * Game;
enemyimage::enemyimage(QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
    if(Game->currentlevel == 0)
    {
    QPixmap enemyimage("C:/Users/HP/Documents/Practice/enemy1.png");
    enemyimage = enemyimage.scaledToHeight(45);
    enemyimage = enemyimage.scaledToWidth(45);
    setPixmap(enemyimage);
    }
    else if(Game->currentlevel == 1)
    {
        QPixmap enemy1("C:/Users/HP/Desktop/CCS2/enemy12.png");
        enemy1 = enemy1.scaledToHeight(30);
        enemy1 = enemy1.scaledToWidth(30);
        setPixmap(enemy1);
    }
    else if(Game ->currentlevel == 2)
    {
        QPixmap enemy1("C:/Users/HP/Desktop/ProjectFinal/bigboss2.png");
        enemy1 = enemy1.scaledToHeight(30);
        enemy1 = enemy1.scaledToWidth(30);
        setPixmap(enemy1);
    }


}
