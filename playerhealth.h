#ifndef PLAYERHEALTH_H
#define PLAYERHEALTH_H

#include <QGraphicsTextItem>
class Playerhealth: public QGraphicsTextItem
{
public:
 Playerhealth(QGraphicsItem *parent = 0);
 void decrease();
 int getHealth();
private:
 int playerhealth;
};

#endif // PLAYERHEALTH_H


