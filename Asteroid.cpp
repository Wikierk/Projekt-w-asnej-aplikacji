#include "Asteroid.h"
#include "Opponent.h"
#include "Player.h"
#include "Game.h"
#include "MainWindow.h"
#include "DialogEnd.h"
extern Game *game;
Asteroid::Asteroid()
{
    setPixmap(QPixmap(":/asteroid.png"));
    setScale(0.4);
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
    setPos(QRandomGenerator::global()->bounded(0, 600+1),0);


}

void Asteroid::move()
{

    QList<QGraphicsItem *> colidingItem = collidingItems();

    for(int i = 0; i < colidingItem.size();i++)
    {


        if(typeid (*colidingItem[i])==typeid(Opponent))
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



    setPos(x(),y()+3);
    if(y()>600){
        scene()->removeItem(this);
        delete this;

    }
}
