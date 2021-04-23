#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include "Player.h"
#include "Bullet.h"
#include "Opponent.h"
#include "Asteroid.h"
#include "Score.h"
#include "Health.h"
#include <QTimer>
#include <QObject>
#include <QRandomGenerator64>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QString>
#include <QFont>
#include <QKeyEvent>
#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QFileDialog>

class Game: public QObject, public QGraphicsPixmapItem
{
Q_OBJECT

public:
    Game();

    Asteroid *asteroid;
    Opponent *opponent;
    QTimer *timer_a;
    QTimer *timer_o;
    Score *score;
    Health *health;
    Player *player;
    bool endGame;
    QMediaPlayer *Mplayer;
    QMediaPlayer *Eplayer;

};

#endif // GAME_H
