#ifndef OPPONENT_H
#define OPPONENT_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QObject>
#include <QRandomGenerator64>
#include "Bullet.h"
#include <QGraphicsScene>
#include <QDebug>

class Opponent: public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:
    Opponent();
    int t;
    int s;
    int r;
    Bullet *bullet;
public slots:
   void move();

};

#endif // OPPONENT_H
