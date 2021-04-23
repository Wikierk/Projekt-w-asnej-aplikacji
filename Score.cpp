#include "Score.h"

Score::Score()
{
    score = 0;
    setPlainText("Score:" + QString::number(score));
    setFont(QFont("times",16));
    setDefaultTextColor(Qt::red);
}

void Score::increaseScore(QString name)
{


        if(name == "Asteroid")
         score += 10;
        else if(name =="Opponent")
         score+=15;
          setPlainText("Score: " + QString::number(score));
}

int Score::getScore()
{
    return score;
}
