#include "enemy2.h"
#include <QTimer>
#include<QGraphicsScene>
#include "player.h"
#include"game.h"
extern game * Game;
enemy2::enemy2(int Items[23][45], QGraphicsItem * parent):QGraphicsPixmapItem(parent)
{
    if(Game->currentlevel == 0)
    {
    row = 18;
    colomn = 22;
    QPixmap enemy1("C:/Users/HP/Documents/Practice/enemy2resize.png");
    enemy1 = enemy1.scaledToHeight(40);
    enemy1 = enemy1.scaledToWidth(40);
    setPixmap(enemy1);
    setPos(660, 540);
    }
    else if(Game->currentlevel == 1)
    {
        row = 14;
        colomn = 3;
        QPixmap enemy1("C:/Users/HP/Desktop/ProjectFinal/enemy21.png");
        enemy1 = enemy1.scaledToHeight(30);
        enemy1 = enemy1.scaledToWidth(30);
        setPixmap(enemy1);
        setPos(90, 420);
    }

    for(int i = 0; i < 23; i++)
    {
        for(int j = 0; j < 45; j++)
        {
            maze[i][j] = Items[i][j];
        }
    }


    //QTimer * timer = new QTimer();
   connect(timer,SIGNAL(timeout()), this, SLOT(move()));
    timer->start(1000);
    srand(time(NULL));
   zup = rand() % 4;
}


void enemy2::showhearts()
{
    heart * h1 = new heart();
    heart * h2 = new heart();
    heart * h3= new heart();
    heartp.enqueue(h1);
    heartp.enqueue(h2);
    heartp.enqueue(h3);
    h1->setPos(150,640);
    scene()->addItem(h1);
    h2->setPos(180, 640);
    scene()->addItem(h2);
    h3->setPos(210, 640);
    scene()->addItem(h3);
}

void enemy2::reset()
{
    if(Game->currentlevel == 0)
    {
    row = 18;
    colomn = 22;
    QPixmap enemy1("C:/Users/HP/Documents/Practice/enemy2resize.png");
    enemy1 = enemy1.scaledToHeight(40);
    enemy1 = enemy1.scaledToWidth(40);
    setPixmap(enemy1);
    setPos(660, 540);
    }
    else if(Game->currentlevel== 1 )
    {
        row = 14;
        colomn = 3;
        QPixmap enemy1("C:/Users/HP/Desktop/ProjectFinal/enemy21.png");
        enemy1 = enemy1.scaledToHeight(30);
        enemy1 = enemy1.scaledToWidth(30);
        setPixmap(enemy1);
        setPos(90, 420);

    }
//    QTimer * timer = new QTimer();
//   connect(timer,SIGNAL(timeout()), this, SLOT(move()));
//    timer->start(1000);
    //srand(time(NULL));
}

void enemy2::removeheart()
{
    scene()->removeItem(heartp.front());
    heartp.dequeue();
}
void enemy2::move()
{
    if(Game->cc->hearts.empty())
    {
        Game->stop();
    }
    //srand(time(0));
    int zup = rand() % 4;
    //int previousz;
    if(zup==0)
    {
        if(maze[row][colomn - 1] > 0)
        {
        colomn-= 1;
        setPos(x()-30,y());
    }
    }
    else if(zup==1)
    {
        //previousz = zup;
        if(maze[row][colomn + 1] > 0)
        {
        colomn += 1;
        setPos(x()+30 ,y());
}
    }

    else if(zup==2)
    {
        //previousz = zup;
        if(maze[row + 1][colomn] > 0)
        {
        row += 1;
        setPos(x(), y() + 30);
        }
    }
    else
    {
        //previousz = zup;
        if(maze[row - 1][colomn] > 0)
        {
        row-= 1;
        setPos(x(), y() - 30);
}
    }

    //previousz = zup;

    QList <QGraphicsItem *> colliding_item = collidingItems();
        int n = colliding_item.size();
        for(int i = 0; i < n; ++i)
        {
            if(Game->cc->power_up == false)
            {
            if(typeid(*(colliding_item[i])) == typeid(Player))
            {

                //qDebug() << "Power up " <<  Game->cc->power_up;
                Game->healthplayerr->decrease();
                Game->cc->removeheart();
                Game->cc->reset();
                qDebug() << "In enemy 2 enemy deleted is: " << Game->e1->e1deleted;
                if(Game->delete1 == false)
                {
                qDebug() << "I am here";
                Game->e1->reset();
                }
                qDebug() << "In enemy 2 enemy 2 deleted is: " << Game->e2->e2deleted;
                if(!Game->delete2 == false)
                {
                qDebug() << "Enemy 2";
                Game->e2->reset();
                }
                }

            }

        }

}
