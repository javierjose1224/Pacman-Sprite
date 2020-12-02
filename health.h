#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Health: public QGraphicsTextItem
{
public:
    Health(QGraphicsItem * parent = 0);
    void decrease();
    int getHealth();
private:
    int health;
};

#endif // HEALTH_H
