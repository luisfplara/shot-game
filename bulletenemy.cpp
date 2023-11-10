#include <QGraphicsRectItem>
#include <QTimer>
#include <QDebug>

#include <math.h>
#include <QList>
#include "bulletenemy.h".h"
#include "game.h"
#include "enemy.h"
// declaração da variavel do tipo extern
// indica que essa variavel já foi declarada em algum outro arquivo do projeto
extern Game * game;
BulletEnemy::BulletEnemy(int x, int y): QObject(), QGraphicsEllipseItem()

{
    // desenhar o tiro
    setPos(x,y);
    mouseX=x;
    mouseY=y;
    qDebug()<<"x: "<<mouseX;
    qDebug()<<"y: "<<mouseY;
    v=5;
    playerY = game->player->y();
    playerX = game->player->x();
     if(playerX-mouseX==0){
        a=(3.1415)/2;
     }else{

         qDebug()<<(fabs(playerY-mouseY)/fabs(playerX-mouseX));
         a = atan((fabs(playerY-mouseY)/fabs(playerX-mouseX)));
     }


qDebug()<<"tiro a:"<<a;


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
    setBrush(QBrush(Qt::blue));

    // conectar o timer com o movimento
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    // inicializar o timer
    timer->start(50);
}
void BulletEnemy::move()
{
    // verificação de colisão:
    // se tiro atingiu o nimigo
    QList<QGraphicsItem *> colliding_item = collidingItems();
    for(int i = 0, n = colliding_item.size(); i < n; i++)
    {
        if(typeid(*(colliding_item[i]))== typeid(Player))
        {
            game->playerhealth->decrease();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    //1quadrante
     if(playerX-mouseX>=0&&playerY-mouseY<=0){
        // qDebug()<<"1quadrante";
        setPos(this->x()+(v*cos(a)),this->y()-(v*sin(a)));

        }else if(playerX-mouseX<0&&playerY-mouseY<0){
        // qDebug()<<"2quadrante";
          setPos(this->x()-(v*cos(a)),this->y()-(v*sin(a)));

         }else if(playerX-mouseX<=0&&playerY-mouseY>=0){
         //qDebug()<<"3quadrante";
             setPos(this->x()-(v*cos(a)),this->y()+(v*sin(a)));

             }else if(playerX-mouseX>0&&playerY-mouseY>0){
         //qDebug()<<"4quadrante";
                setPos(this->x()+(v*cos(a)),this->y()+(v*sin(a)));

               }






    //qDebug()<<" X: "<<mouseX<<" Y: "<<mouseY;

    if(y() < 0||y() >600||x()<0||x()>800)
    {
        scene()->removeItem(this);
        delete this;
        qDebug()<<"Bullet removed";
    }
}
