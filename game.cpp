#include <QGraphicsTextItem>
#include <QDebug>
#include <QMouseEvent>
#include <QTimer>
#include "game.h"
#include "bullet.h"
#include <QKeyEvent>
#include "enemy.h"
#include "weapons.h"

Game::Game(QWidget *parent)
{
    // criar scene

     setMouseTracking(true);
    scene = new QGraphicsScene();

    // fixar o tamanho em 800x600, que é infinito por definição
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QImage(":/bg/background/bg.jpg").scaled(800,600,Qt::KeepAspectRatio)));
    // visualizar o objeto scene (cenario)
    setScene(scene);
    //desabilitar as barras de rolagem
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // fixar o tamanho
    setFixedSize(800,600);
    // criar o jogador
    player = new Player();
    // definir o tamanho do jogador 100 x 100
    // definir a posição padrão do jogador para ser em baixo da tela
    // por definição a visualização é centralizada para pegar todos os objetos
    player->setPos(60,270);
    // colocar o foco no jogador
    // adicionar o jogador no cenario
    scene->addItem(player);
    // criar inimigos

  QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(1000);
    //player->spawn();

    // adicionar contagem de pontos e vida do jogador
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    playerhealth = new Playerhealth();
    playerhealth->setPos(playerhealth->x(), playerhealth->y()+560);
    scene->addItem(playerhealth);

    weapons = new Weapons();
    weapons->setPixmap(QPixmap(":/weapons/weapons/ak47_m.png"));
    scene->addItem(weapons);
    show();


}

void Game::mousePressEvent(QMouseEvent * event){
   double   a = atan((event->pos().y()-(weapons->y()))/(event->pos().x()-(weapons->x())));
    if(event->button() == Qt::LeftButton){
        if(event->pos().x()>player->x()+27){
        Bullet * bullet = new Bullet(event->pos().x(),event->pos().y());
        bullet->setPos(weapons->x()+(46*cos(a)),weapons->y()+(46*sin(a))),
        scene->addItem(bullet);
         }
    }

}

 void Game::mouseMoveEvent(QMouseEvent *ev) {
     // vvv That's where the magic happens
           double   a = atan((ev->pos().y()-(weapons->y()))/(ev->pos().x()-(weapons->x())));

           if(ev->pos().x()>player->x()+27){

              weapons->setPos(player->x()+25,player->y()+16);
                weapons->setA(a);
                 weapons->setRotation(qreal(a*50));
           }

 }

void Game::keyPressEvent(QKeyEvent *event)
{
    // mensagem informando que ocorreu uso do teclado
    //qDebug()<<"Key press detected";a
    switch (event->key()) {
    case Qt::Key_A:
       
        if(player->pos().x() > 0)
            weapons->setPos(weapons->x()-10,weapons->y());
            player->setPos(player->x()-10,player->y());

    
        break;

    case Qt::Key_D:
        if(player->pos().x() + 100 < 800 )
            weapons->setPos(weapons->x()+10,weapons->y());
            player->setPos(player->x()+10,player->y());
        break;
    case Qt::Key_W:
        if(player->pos().x() + 100 < 800 )
            weapons->setPos(weapons->x(),weapons->y()-10);
            player->setPos(player->x(),player->y()-10);
        break;
    case Qt::Key_S:
        if(player->pos().x() + 100 < 800 )
            weapons->setPos(weapons->x(),weapons->y()+10);
            player->setPos(player->x(),player->y()+10);
        break;
    case Qt::Key_Space:

        for(int i =0; i <10; i++){
              qDebug()<<"Pulo";
            weapons->setPos(weapons->x(),weapons->y()-10);
            player->setPos(player->x(),player->y()-10);

        }




        break;
    default:
        break;
    }

    // criar tiro (bullet)

}

void Game::keyReleaseEvent(QKeyEvent * event){

    switch (event->key()) {

    case Qt::Key_Space:

        for(int i =0; i <10; i++){
              qDebug()<<"Pulo";
            weapons->setPos(weapons->x(),weapons->y()+10);
            player->setPos(player->x(),player->y()+10);

        }




        break;
    default:
        break;
    }

}
