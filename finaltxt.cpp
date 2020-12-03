#include "finaltxt.h"
#include <QFont>

finaltxt::finaltxt(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    setPlainText(QString("FIN DEL JUEGO"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",40));
}
