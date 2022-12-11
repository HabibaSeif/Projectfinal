#include "food.h"
#include "game.h"

extern game * Game;
food::food(QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
if(Game->currentlevel == 0)
{
    QPixmap enemy1("C:/Users/HP/Desktop/ProjectFinal/food.png");
    enemy1 = enemy1.scaledToHeight(30);
    enemy1 = enemy1.scaledToWidth(30);
    setPixmap(enemy1);
}
else if(Game->currentlevel == 1)
{
    QPixmap enemy1("C:/Users/HP/Desktop/ProjectFinal/food2.png");
    enemy1 = enemy1.scaledToHeight(30);
    enemy1 = enemy1.scaledToWidth(30);
    setPixmap(enemy1);
}
else{
QPixmap enemy1("C:/Users/HP/Desktop/ProjectFinal/cherry.png");
enemy1 = enemy1.scaledToHeight(30);
enemy1 = enemy1.scaledToWidth(30);
setPixmap(enemy1);
}

}
