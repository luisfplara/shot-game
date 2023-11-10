#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include "enemy.h"
#include "game.h"
#include "bulletenemy.h"
#include "weapons.h"
extern Game * game;
Enemy::Enemy()
{
    // posição aleatoria
    int random_number = rand() % 500;
    setPos(800,random_number);
   // setPos(400,300);
    // desenhar o inimigo
    setRect(0,0,50,50);
    setBrush(QBrush(Qt::red));
    //movimentação

   QTimer * timer = new QTimer();
  connect(timer, SIGNAL(timeout()), this, SLOT(move()));
   timer->start(50);

    QTimer * timer2 = new QTimer();
    connect(timer2, SIGNAL(timeout()), this, SLOT(fire()));
    timer2->start(1500);


}
void Enemy::move()
{

    setPos(x()-5,y());

    if(pos().x() < 0)
    {
        scene()->removeItem(this);

        game->health->decrease();
        delete this;

        qDebug()<<"Enemy removed";
    }
}

void Enemy::fire(){

    BulletEnemy * bulletEnemy = new BulletEnemy(x(),y());

    game->scene->addItem(bulletEnemy);

}
