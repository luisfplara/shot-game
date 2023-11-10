#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QObject>
#include "weapons.h"

class Enemy: public QObject, public QGraphicsEllipseItem
{
 Q_OBJECT
public:
 Enemy();
public slots:
 void move();
 void fire();
private:
 Weapons *weapons;
};
#endif // ENEMY_H
