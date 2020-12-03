#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText(QString("Puntos: ")+ QString::number(score));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",16));
}

void Score::increase()
{
    score++;
    setPlainText(QString("Puntos: ")+ QString::number(score));
}

int Score::getScore()
{
    return score;
}
