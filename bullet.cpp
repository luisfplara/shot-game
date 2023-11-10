#include <QGraphicsRectItem>
#include <QTimer>
#include <QDebug>

#include <math.h>
#include <QList>
#include "bullet.h"
#include "game.h"
#include "enemy.h"
// declaração da variavel do tipo extern
// indica que essa variavel já foi declarada em algum outro arquivo do projeto
extern Game * game;
Bullet::Bullet(int xmouse, int ymouse): QObject(), QGraphicsEllipseItem()

{
    // desenhar o tiro
    mouseX=xmouse;
    mouseY=ymouse;
    if((mouseX-(game->player->x()))==0){
       a=(3.1415)/2;
    }else{

     a = atan((mouseY-(game->player->y()))/(mouseX-(game->player->x())));
    }

    v=30;
    playerX=game->player->x();
    playerY=game->player->y();

    shotsound = new QMediaPlayer();
    shotsound->setMedia(QUrl("qrc:/sound/sfx/weapons/ak47.wav"));
    if(shotsound->state() == QMediaPlayer::PlayingState)
    {
    // caso o som ainda esta tocando resetar o Player para posição

    shotsound->setPosition(0);
    }
    else if(shotsound->state() == QMediaPlayer::StoppedState)
    {
    shotsound->play();
    }
    setRect(0,0,8,8);
    setBrush(QBrush(Qt::yellow));

    // conectar o timer com o movimento
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    // inicializar o timer


    timer->start(50);
}
void Bullet::move()
{
    // verificação de colisão:
    // se tiro atingiu o nimigo
    QList<QGraphicsItem *> colliding_item = collidingItems();
    for(int i = 0, n = colliding_item.size(); i < n; i++)
    {
        if(typeid(*(colliding_item[i]))== typeid(Enemy))
        {
            game->score->increase();
            scene()->removeItem(colliding_item[i]);
            scene()->removeItem(this);
            delete colliding_item[i];
            delete this;
            return;
        }
    }

    // movimentação do tiro
    if(mouseX-playerX<0){
        setPos(x()+(-v*cos(a)),y()+(-v*sin(a)));
    }else{
        setPos(x()+(v*cos(a)),y()+(v*sin(a)));
    }






    //qDebug()<<" X: "<<mouseX<<" Y: "<<mouseY;
    //setPos(x(),y()-10);
    if(y() < 0||y() >600||x()<0||x()>800)
    {
        scene()->removeItem(this);
        delete this;
        qDebug()<<"Bullet removed";
    }
}
