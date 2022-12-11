#ifndef FOOD_H
#define FOOD_H
#include<QGraphicsPixmapItem>
#include<QGraphicsItem>

class food:public QObject,public QGraphicsPixmapItem
{
   Q_OBJECT;
public:
    food(QGraphicsItem * parent = 0);

};

#endif // FOOD_H
