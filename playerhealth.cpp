#include <QFont>
#include "Playerhealth.h"
Playerhealth::Playerhealth(QGraphicsItem *parent):QGraphicsTextItem(parent)
{

    playerhealth = 10;
    setPlainText(QString("Player Health:  ") + QString::number(playerhealth));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",20));
}
void Playerhealth::decrease()
{
    playerhealth--;
    setPlainText(QString("Player Health: ") + QString::number(playerhealth));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",20));
}
int Playerhealth::getHealth()
{
    return playerhealth;
}
