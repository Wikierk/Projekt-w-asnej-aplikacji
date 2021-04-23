#include "Health.h"

Health::Health()
{
    health = 5;
    setPlainText("Health: " + QString::number(health));
    setPos(0,25);
    setFont(QFont("times",16));
    setDefaultTextColor(Qt::red);
}

void Health::ChangeHealth()
{

    health--;
    if(health>=0){
    setPlainText("Health: " + QString::number(health));
    }
}
