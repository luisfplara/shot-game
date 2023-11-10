#include "score.h"
#include <QFont>
Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
 score = 0;
 setPlainText(QString("Score: ") + QString::number(score));
 setDefaultTextColor(Qt::yellow);
 setFont(QFont("times",16));
}
void Score::increase()
{
 score++;
 setPlainText(QString("Score: ") + QString::number(score));
 setDefaultTextColor(Qt::yellow);
 setFont(QFont("times",16));
}
int Score::getScore()
{
 return score;
}