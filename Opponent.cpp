#include "Opponent.h"
#include "Player.h"
#include "Game.h"
#include "MainWindow.h"
#include "DialogEnd.h"
extern Game *game;

Opponent::Opponent()
{

    setPixmap(QPixmap(":/opponent.png"));
    setScale(0.2);
    setPos(QRandomGenerator::global()->bounded(50, 600),0);
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(15);
    t = 0;
    s = 0;
    r = QRandomGenerator::global()->bounded(0, 2);
}



void Opponent::move()
{

    QList<QGraphicsItem *> colidingItem = collidingItems();

    for(int i = 0; i < colidingItem.size();i++)
   {


        if(typeid (*colidingItem[i])==typeid(Player))
        {
            game->Eplayer->setVolume(20);
            game->Eplayer->setPosition(0);
            game->Eplayer->play();
            game->health->ChangeHealth();
            scene()->removeItem(this);
            if(game->health->health == 0){
            game->endGame = 1;
            game->timer_a->stop();
            game->timer_o->stop();
            DialogEnd e;
            e.exec();

            }
            delete this;
            return;
        }

    }

    if(t <= 200)
    t++;
    else
    t = 0;



    if(r == 0){
    if(t <= 100)
    setPos(x()+1,y()+1);
    else
    if(t >=100)
     setPos(x()-1,y()+1);
    }


    else
        if(r == 1){
            if(t >= 100)
            setPos(x()+1,y()+1);
            else
            if(t <=100)
             setPos(x()-1,y()+1);

        }





    if(y()>600){
        scene()->removeItem(this);
        delete this;
    }


    if(s<50)
        s++;
    else
        s=0;
    if(s==50){
    bullet = new Bullet;
    bullet->timer->stop();
    bullet->timer_r->start(10);
    bullet->setPos(x()+50,y()+40);
    scene()->addItem(bullet);
    game -> Mplayer->setPosition(0);
    game -> Mplayer->setVolume(30);
    game -> Mplayer->play();
    }
}






