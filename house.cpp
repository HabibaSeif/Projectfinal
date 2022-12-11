#include "house.h"
#include "game.h"

extern game * Game;
house::house(QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
    if(Game->currentlevel == 0)
    {
    QPixmap h("C:/Users/HP/Documents/Practice/tree.png");
    h = h.scaledToHeight(30);
    h = h.scaledToWidth(30);
    setPixmap(h);
    }
    else if(Game->currentlevel == 1)
    {
        QPixmap h("C:/Users/HP/Desktop/ProjectFinal/tree2.png");
        h = h.scaledToHeight(30);
        h = h.scaledToWidth(30);
        setPixmap(h);
    }
    else if(Game->currentlevel == 2)
    {
        QPixmap h("C:/Users/HP/Desktop/ProjectFinal/tree3.png");
        h = h.scaledToHeight(30);
        h = h.scaledToWidth(30);
        setPixmap(h);
    }


}
