#include "Game.h"
#include "MainWindow.h"
Game::Game()
{

    timer_a = new QTimer();
    timer_o = new QTimer();
    score = new Score();
    health = new Health();
    health->setPos(0,20);
    player = new Player();
    player->setPos(320,400);
    connect(timer_a,SIGNAL(timeout()),player,SLOT(spawn_a()));
    connect(timer_o,SIGNAL(timeout()),player,SLOT(spawn_o()));
    timer_a->start(2000);
    timer_o->start(3000);
    endGame = 0;
    Mplayer = new QMediaPlayer;
    Eplayer = new QMediaPlayer;
    Mplayer->setMedia(QUrl("qrc:/sf_laser_15.mp3"));
    Eplayer->setMedia(QUrl("qrc:/Explosion.mp3"));
}


