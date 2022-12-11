#include"bigboss.h"
#include<QTimer>
#include<stdlib.h>
#include <QList>
#include <QDebug>
#include <QStack>
#include <QTimer>
#include "game.h"

extern game * Game;
int MAX = std::numeric_limits<float>::max();
bigboss::bigboss(int Items[23][45], Player * pt, QGraphicsItem * parent)
{
    QPixmap boss("C:/Users/HP/Desktop/CCS2/bigboss.png");
    boss = boss.scaledToWidth(30);
    boss = boss.scaledToHeight(30);
    setPixmap(boss);
    row = 18;
    colomn = 10;
    this->pd = pt;
    //Game->scene->addItem(this);
    setPos(300, 540);
    for(int i = 0; i < 23; i++)
    {
        for(int j = 0; j < 45; j++)
        {
            maze[i][j] = Items[i][j];
        }
    }
    Pair src = std::make_pair(this->row,this->colomn);
    Pair dst = std::make_pair(pt->row,pt->colomn);
    this->aStar(maze, src, dst);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(1000);
}
bool bigboss::isValid(int r, int c)
{
    if ((r >= 0) &&(r < ROW) && (c >= 0) && (c < COL))
    {
        return true;
    }
    return false;
}

//bool bigboss::isUnblocked(int grid[][COL], int r, int c)
//{
//    if(grid[r][c] == 4)
//    {
//        return true;
//    }
//    return false;
//}

bool bigboss::isDst(int r, int c, Pair dst)
{
    if((r == dst.first) && (c == dst.second))
    {
        return true;
    }
    return false;
}

double bigboss::calculateH(int r, int c, Pair dst)
{
    return ((double)sqrt((r - dst.first) * (r - dst.first) + (c - dst.second) * (c - dst.second)));
}

void bigboss::tracePath(cell cellData[][COL],Pair dst)
{
    int row = dst.first;
    int col = dst.second;

    std::stack<Pair> Path;

     while (!(cellData[row][col].parent_i == row && cellData[row][col].parent_j == col)) {
     Path.push(std::make_pair(row, col));
     Pathfinal.push(Path.top());
     int temp_row = cellData[row][col].parent_i;
     int temp_col = cellData[row][col].parent_j;
     row = temp_row;
     col = temp_col;
        }
        Path.push(std::make_pair(row, col));
        qDebug() << Path.top();
        while (!Path.empty()) {
        std::pair<int, int> p = Path.top();
        Path.pop();
        }

        return;
}

void bigboss::aStar(int Items[][COL], Pair src, Pair dst)
{
    if (isValid(src.first, src.second) == false) {
            printf("Source is invalid\n");
            return;
        }

        // If the destination is out of range
        if (isValid(dst.first, dst.second) == false) {
            printf("Destination is invalid\n");
            return;
        }

        if (isDst(src.first, src.second, dst) == true) {
            printf("We are already at the destination\n");
            return;
        }

       //initialization
       bool closedList[ROW][COL];
       cell cellDetails[ROW][COL];

           int i, j;

           for (i = 0; i < ROW; i++) {
               for (j = 0; j < COL; j++) {
                   cellDetails[i][j].f = FLT_MAX;
                   cellDetails[i][j].g = FLT_MAX;
                   cellDetails[i][j].h = FLT_MAX;
                   cellDetails[i][j].parent_i = -1;
                   cellDetails[i][j].parent_j = -1;
               }
           }

           i = src.first, j = src.second;
               cellDetails[i][j].f = 0.0;
               cellDetails[i][j].g = 0.0;
               cellDetails[i][j].h = 0.0;
               cellDetails[i][j].parent_i = i;
               cellDetails[i][j].parent_j = j;

            std::set<pPair> openList;
            openList.insert(make_pair(0.0, std::make_pair(i, j)));
            //bool foundDest = false;

                while (!openList.empty())
                {
                    pPair p = *openList.begin();

                    // Remove this vertex from the open list
                    openList.erase(openList.begin());

                    // Add this vertex to the closed list
                    i = p.second.first;
                    j = p.second.second;
                    closedList[i][j] = true;
                }
                double gNew, hNew, fNew;
                bool foundDst = false;
                //North

                if (isValid(i - 1, j) == true) {
                            // If the destination cell is the same as the
                            // current successor
                            if (isDst(i - 1, j, dst) == true) {
                                // Set the Parent of the destination cell
                                cellDetails[i - 1][j].parent_i = i;
                                cellDetails[i - 1][j].parent_j = j;
                                qDebug() << "The destination cell is found\n";
                                tracePath(cellDetails, dst);
                                foundDst = true;
                                return;
                            }
                }

                if (closedList[i - 1][j] == false/*&& isUnblocked(Items, i - 1, j)== true*/) {
                                gNew = cellDetails[i][j].g + 1.0;
                                hNew = calculateH(i - 1, j, dst);
                                fNew = gNew + hNew;
                }
                if (cellDetails[i - 1][j].f == FLT_MAX
                                    || cellDetails[i - 1][j].f > fNew) {
                                    openList.insert(make_pair(
                                        fNew, std::make_pair(i - 1, j)));

                                    // Update the details of this cell
                                    cellDetails[i - 1][j].f = fNew;
                                    cellDetails[i - 1][j].g = gNew;
                                    cellDetails[i - 1][j].h = hNew;
                                    cellDetails[i - 1][j].parent_i = i;
                                    cellDetails[i - 1][j].parent_j = j;
                                }

                if (isValid(i + 1, j) == true) {
                            // If the destination cell is the same as the
                            // current successor
                            if (isDst(i + 1, j, dst) == true) {
                                // Set the Parent of the destination cell
                                cellDetails[i + 1][j].parent_i = i;
                                cellDetails[i + 1][j].parent_j = j;
                                printf("The destination cell is found\n");
                                tracePath(cellDetails, dst);
                                foundDst = true;
                                return;
                            }
                }
                if (closedList[i + 1][j] == false
                                     /*&& isUnblocked(Items, i + 1, j)
                                            == true*/) {
                                gNew = cellDetails[i][j].g + 1.0;
                                hNew = calculateH(i + 1, j, dst);
                                fNew = gNew + hNew;

                                // If it isn’t on the open list, add it to
                                // the open list. Make the current square
                                // the parent of this square. Record the
                                // f, g, and h costs of the square cell
                                //                OR
                                // If it is on the open list already, check
                                // to see if this path to that square is
                                // better, using 'f' cost as the measure.
                                if (cellDetails[i + 1][j].f == FLT_MAX
                                    || cellDetails[i + 1][j].f > fNew) {
                                    openList.insert(make_pair(
                                        fNew, std::make_pair(i + 1, j)));
                                    // Update the details of this cell
                                    cellDetails[i + 1][j].f = fNew;
                                    cellDetails[i + 1][j].g = gNew;
                                    cellDetails[i + 1][j].h = hNew;
                                    cellDetails[i + 1][j].parent_i = i;
                                    cellDetails[i + 1][j].parent_j = j;
                                }
                }


                if (isValid(i, j + 1) == true) {
                            // If the destination cell is the same as the
                            // current successor
                            if (isDst(i, j + 1, dst) == true) {
                                // Set the Parent of the destination cell
                                cellDetails[i][j + 1].parent_i = i;
                                cellDetails[i][j + 1].parent_j = j;
                                printf("The destination cell is found\n");
                                tracePath(cellDetails, dst);
                                foundDst = true;
                                return;
                            }

                            // If the successor is already on the closed
                            // list or if it is blocked, then ignore it.
                            // Else do the following
                            else if (closedList[i][j + 1] == false
                                    /* && isUnblocked(Items, i, j + 1)
                                            == true*/) {
                                gNew = cellDetails[i][j].g + 1.0;
                                hNew = calculateH(i, j + 1, dst);
                                fNew = gNew + hNew;
                                if (cellDetails[i][j + 1].f == FLT_MAX
                                    || cellDetails[i][j + 1].f > fNew) {
                                    openList.insert(make_pair(
                                        fNew, std::make_pair(i, j + 1)));

                                    // Update the details of this cell
                                    cellDetails[i][j + 1].f = fNew;
                                    cellDetails[i][j + 1].g = gNew;
                                    cellDetails[i][j + 1].h = hNew;
                                    cellDetails[i][j + 1].parent_i = i;
                                    cellDetails[i][j + 1].parent_j = j;
                                }
                            }
                        }

                        //----------- 4th Successor (West) ------------

                        // Only process this cell if this is a valid one
                        if (isValid(i, j - 1) == true) {
                            // If the destination cell is the same as the
                            // current successor
                            if (isDst(i, j - 1, dst) == true) {
                                // Set the Parent of the destination cell
                                cellDetails[i][j - 1].parent_i = i;
                                cellDetails[i][j - 1].parent_j = j;
                                printf("The destination cell is found\n");
                                tracePath(cellDetails, dst);
                                foundDst = true;
                                return;
                            }

                            // If the successor is already on the closed
                            // list or if it is blocked, then ignore it.
                            // Else do the following
                            if (closedList[i][j - 1] == false
                                     /*&& isUnblocked(Items, i, j - 1)
                                            == true*/) {
                                gNew = cellDetails[i][j].g + 1.0;
                                hNew = calculateH(i, j - 1, dst);
                                fNew = gNew + hNew;

                                // If it isn’t on the open list, add it to
                                // the open list. Make the current square
                                // the parent of this square. Record the
                                // f, g, and h costs of the square cell
                                //                OR
                                // If it is on the open list already, check
                                // to see if this path to that square is
                                // better, using 'f' cost as the measure.
                                if (cellDetails[i][j - 1].f == FLT_MAX
                                    || cellDetails[i][j - 1].f > fNew) {
                                    openList.insert(make_pair(
                                        fNew, std::make_pair(i, j - 1)));

                                    // Update the details of this cell
                                    cellDetails[i][j - 1].f = fNew;
                                    cellDetails[i][j - 1].g = gNew;
                                    cellDetails[i][j - 1].h = hNew;
                                    cellDetails[i][j - 1].parent_i = i;
                                    cellDetails[i][j - 1].parent_j = j;
                                }
                            }
                        }


}

void bigboss::move()
{
    qDebug() << Pathfinal.empty();
    if(Pathfinal.empty() == false)
    {
        Pair temp = Pathfinal.top();
        Pathfinal.pop();
        int c = temp.second;
        int r = temp.first;
        setPos(r*30 + 30, c*30 + 30);
    }
}



