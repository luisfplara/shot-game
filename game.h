#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "score.h"
#include "health.h"
#include "weapons.h"
#include "playerhealth.h"

class Game: public QGraphicsView
{
public:
 Game(QWidget * parent=0);
 QGraphicsScene * scene;
 Player * player;
 Score * score;
 Health *health;
 Playerhealth *playerhealth;
 Weapons *weapons;


 void mousePressEvent(QMouseEvent    * event);
 void mouseMoveEvent(QMouseEvent    * event);
  void keyPressEvent(QKeyEvent * event);
  void keyReleaseEvent(QKeyEvent * event);
  void spawn();
};
#endif // GAME_H
