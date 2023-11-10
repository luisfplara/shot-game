#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent>

#include "weapons.h"

Weapons::Weapons(QGraphicsItem * parent)
{


}
double Weapons::getA(){
    return a;
}
void Weapons::setA(double a){
    this->a=a;
}
