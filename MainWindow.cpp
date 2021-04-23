#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Bullet.h"
#include "Game.h"
Game *game;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    scene = new QGraphicsScene(0,0,width(),height());
    scene->setBackgroundBrush(QImage(":/Background.png"));
    game = new Game();
    scene->addItem(game->player);
    scene->addItem(game->score);
    scene->addItem(game->health);
    w = false;
    s = false;
    a = false;
    d = false;
    WallL =  new QGraphicsLineItem();
    WallR =  new QGraphicsLineItem();
    WallL->setLine(0,0,0,700);
    WallR->setLine(790,0,790,700);
    ui->graphicsView->setScene(scene);





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if(game->endGame!=1){
    if(event->key() == Qt::Key_D && !game->player->collidesWithItem(WallR)){
    game->player->setPos(game->player->x()+15,game->player->y());
        d = true;
        }

    if(event->key() == Qt::Key_A && !game->player->collidesWithItem(WallL)){
    game->player->setPos(game->player->x()-15,game->player->y());
     a = true;
   }
    if(event->key() == Qt::Key_S ){
     game->player->setPos(game->player->x(),game->player->y()+15);
      s = true;
   }
    if(event->key() == Qt::Key_W ){
    game->player->setPos(game->player->x(),game->player->y()-15);
    w = true;
   }

    if(event->key() == Qt::Key_Space){
    if(!event->isAutoRepeat()){
    bullet = new  Bullet();
    scene->addItem(bullet);
    bullet->setPos(game->player->x()+24,game->player->y());
    game -> Mplayer->setPosition(0);
    game -> Mplayer->setVolume(30);
    game -> Mplayer->play();
    ui->graphicsView->setScene(scene);
    space = true;

    }

    }

    if((event->key() == Qt::Key_D && w == true && !game->player->collidesWithItem(WallR)) || (event->key() == Qt::Key_W && d == true  && !game->player->collidesWithItem(WallR))  )
    {

        game->player->setPos(game->player->x()+5,game->player->y()-5);
    }

    if((event->key() == Qt::Key_A && w == true  && !game->player->collidesWithItem(WallL)) || (event->key() == Qt::Key_W && a == true && !game->player->collidesWithItem(WallL)) )
    {

        game->player->setPos(game->player->x()-5,game->player->y()-5);
    }
    if((event->key() == Qt::Key_A && s == true && !game->player->collidesWithItem(WallL)) || (event->key() == Qt::Key_S && a == true && !game->player->collidesWithItem(WallR)) )
    {

        game->player->setPos(game->player->x()-5,game->player->y()+5);
    }
    if((event->key() == Qt::Key_S && d == true && !game->player->collidesWithItem(WallR)) || (event->key() == Qt::Key_D && s == true  && !game->player->collidesWithItem(WallR)) )
    {

        game->player->setPos(game->player->x()+5,game->player->y()+5);
    }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{

    if(game->endGame!=1){
    switch(event->key()){
    case  Qt::Key_D:
        d=false;
        break;
    case  Qt::Key_W:
        w=false;
        break;
    case  Qt::Key_S:
        s=false;
        break;
    case  Qt::Key_A:
        a=false;
        break;
    case Qt::Key_Space:
        space = false;
        break;
    }
    }
}










