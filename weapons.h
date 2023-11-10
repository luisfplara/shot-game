#ifndef WEAPONS_H
#define WEAPONS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Weapons :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
   public:
    Weapons(QGraphicsItem * parent=0);
    double getA();
    void setA(double a);
   public slots:
   private:
    QMediaPlayer * bulletsound;
    double a;
};

#endif // WEAPONS_H
