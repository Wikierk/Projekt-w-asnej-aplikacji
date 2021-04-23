#include "DialogEnd.h"
#include "ui_DialogEnd.h"
extern Game *game;
DialogEnd::DialogEnd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEnd)
{
    ui->setupUi(this);

}

DialogEnd::~DialogEnd()
{
    delete ui;
}

void DialogEnd::on_newGame_clicked()
{

    game->health->health=5;
    game->score->score=0;
    game->timer_a->start(2000);
    game->timer_o->start(3000);
    game->player->setPos(320,400);
    game->score->setPlainText("Score: " + QString::number(game->score->score));
    game->health->setPlainText("Health: " + QString::number(game->health->health));
    game->endGame = 0;
    close();
}

void DialogEnd::on_Exit_clicked()
{
    QApplication::exit(0);
}
