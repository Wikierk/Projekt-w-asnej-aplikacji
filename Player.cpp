#include "Player.h"
#include "QDebug"
#include "MainWindow.h"
#include "Game.h"
extern Game *game;
Player::Player()
{
    setPixmap(QPixmap(":/player.png"));
    setScale(0.1);


}




void Player::spawn_o()
{



    opponent = new Opponent;
    scene()->addItem(opponent);

}



void Player::spawn_a()
{
    asteroid = new Asteroid;
    scene()->addItem(asteroid);


}

