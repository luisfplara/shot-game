#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent>

#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "weapons.h"
Player::Player(QGraphicsItem *parent): QGraphicsEllipseItem(parent)
{
setRect(0,0,50,50);
setBrush(QBrush(Qt::green));


}


void Player::spawn()
{
    // cria inimigo
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);

}
