#ifndef BULLET_H
#define BULLET_H
#include "Asteroid.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "Score.h"
#include <QMessageBox>


class Bullet: public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:
    Bullet();
    QTimer *timer;
    QTimer *timer_r;

public slots:
    void move();
    void move_r();



};

#endif // BULLET_H
