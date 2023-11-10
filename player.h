#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsItem>
class Player: public QObject, public QGraphicsEllipseItem
{
 Q_OBJECT
public:
 Player(QGraphicsItem * parent=0);
 //void keyPressEvent(QKeyEvent * event);

public slots:
 void spawn();

};
#endif // PLAYER_H
