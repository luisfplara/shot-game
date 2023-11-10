#ifndef BULLETENEMY_H
#define BULLETENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QMouseEvent>
#include <QMediaPlayer>

class BulletEnemy: public QObject,public QGraphicsEllipseItem
{
 Q_OBJECT
public:
 BulletEnemy(int x, int y);
public slots:
 void move();
private:
 QMediaPlayer * shotsound;
 int mouseX;
 int mouseY;
  int playerX;
   int playerY;
 double a;
 double v;


};
#endif // BULLETENEMY_H
