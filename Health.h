#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>
#include "QString"
#include "QFont"

class Health:public QGraphicsTextItem
{
public:
    Health();
    int health;

public:
    void ChangeHealth();
};

#endif // HEALTH_H
