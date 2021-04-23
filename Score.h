#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include "QString"
#include "QFont"

class Score:public QGraphicsTextItem
{

public:
    Score();

    int getScore();
    int score;

public:
    void increaseScore(QString name);


};

#endif // SCORE_H
