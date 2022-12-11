#ifndef BIGBOSS_H
#define BIGBOSS_H

#include <QGraphicsPixmapItem>
#include<QObject>
#include<QQueue>
#include<bits/stdc++.h>
#define ROW 23
#define COL 45
#include "player.h"


typedef std::pair<int, int> Pair;
typedef std::pair<double, std::pair<int, int>> pPair;
struct cell{
    int parent_i, parent_j;
    double f,g,h;
};

class bigboss: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
//    int row;
//    int colomn;
    int maze[23][45];
    Player * pd;
    std::stack<Pair>Pathfinal;
public:
    bigboss(int Items[23][45], Player * pt, QGraphicsItem * parent = 0);
    bool isValid(int r, int col);
    bool isUnblocked(int Items[][COL],int r, int c);
    bool isDst(int r, int, Pair dst);
    double calculateH(int r, int c, Pair dst);
    void tracePath(cell cellData[][COL],Pair dst);
    void aStar(int Items[][COL],Pair src, Pair dst);
    int row;
    int colomn;
public slots:
    void move();
};

#endif // BIGBOSS_H
