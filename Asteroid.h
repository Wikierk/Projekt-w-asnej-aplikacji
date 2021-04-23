#ifndef ASTEROID_H
#define ASTEROID_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QObject>
#include <QRandomGenerator64>
#include <QGraphicsScene>
#include <QDebug>

class Asteroid: public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:
    Asteroid();

public slots:
    void move();

};

#endif // ASTEROID_H
