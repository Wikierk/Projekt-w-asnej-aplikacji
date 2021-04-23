#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "Asteroid.h"
#include "Opponent.h"
#include "Bullet.h"
#include <QObject>
#include <QGraphicsScene>
#include "Score.h"
#include <QKeyEvent>

class Player: public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:
    Player();
    Asteroid *asteroid;
    Opponent *opponent;




public slots:
    void spawn_a();
    void spawn_o();

};

#endif // PLAYER_H
