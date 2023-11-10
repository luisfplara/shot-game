#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QMouseEvent>
#include <QMediaPlayer>

class Bullet: public QObject,public QGraphicsEllipseItem
{
 Q_OBJECT
public:
 Bullet(int x, int y);
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
#endif // BULLET_H
