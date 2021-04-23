#include "Bullet.h"
#include "Opponent.h"
#include "Player.h"
#include "Game.h"
#include "MainWindow.h"
#include "DialogEnd.h"
extern Game *game;
Bullet::Bullet()
{
    setPixmap(QPixmap(":/Bullet1.png"));
    setScale(0.2);
    timer = new QTimer();
    timer_r = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(timer_r,SIGNAL(timeout()),this,SLOT(move_r()));
    timer->start(10);



}


void Bullet::move()
{


    QList<QGraphicsItem *> colidingItem = collidingItems();

    for(int i = 0; i < colidingItem.size();i++)
    {


        if(typeid (*colidingItem[i])==typeid(Asteroid))
        {


            game->Eplayer->setVolume(20);
            game->Eplayer->setPosition(0);
            game->Eplayer->play();
            game->score->increaseScore("Asteroid");

            scene()->removeItem(colidingItem[i]);
            scene()->removeItem(this);
            delete colidingItem[i];
            delete this;
            return;

        }

        else if(typeid (*colidingItem[i])==typeid (Opponent))
        {

            game->Eplayer->setVolume(20);
            game->Eplayer->setPosition(0);
            game->Eplayer->play();
            game->score->increaseScore("Opponent");
            scene()->removeItem(colidingItem[i]);
            scene()->removeItem(this);
            delete colidingItem[i];
            delete this;
            return;
        }


    }




    setPos(x(),y()-5);
    if(y()<0){
        scene()->removeItem(this);
        delete this;

    }
}

void Bullet::move_r()
{

    QList<QGraphicsItem *> colidingItem = collidingItems();

    for(int i = 0; i < colidingItem.size();i++)
    {


        if(typeid (*colidingItem[i])==typeid(Asteroid))
        {

            game->Eplayer->setVolume(20);
            game->Eplayer->setPosition(0);
            game->Eplayer->play();
            scene()->removeItem(colidingItem[i]);
            scene()->removeItem(this);
            delete colidingItem[i];
            delete this;
            return;
        }

        else if(typeid (*colidingItem[i])==typeid (Player))
        {
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


    setPos(x(),y()+5);
    if(y()>600){
        scene()->removeItem(this);
        delete this;

    }
}


