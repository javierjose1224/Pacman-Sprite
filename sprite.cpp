#include "sprite.h"
#include "moneda.h"
#include <QDebug>

sprite::sprite(int r_, int x, int y)
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx,posy);
}
sprite::sprite(QObject *parent) : QObject(parent)
{
    timer =new QTimer();
    filas =0;
    columnas =0;
    pixmap = new QPixmap(":/imagen/pac2.png");
    //dimensiones imagen
    ancho = 100;
    alto = 100;
    timer->start(100);
    connect(timer,&QTimer::timeout, this,&sprite::Actualizacion);
    setPos(20,20);

}

void sprite::Actualizacion()
{
    columnas += 100;
    if(columnas >=400){
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

QRectF sprite::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2,*pixmap,columnas,0,ancho,alto);
    setScale(0.3);
}

int sprite::getR() const
{
    return r;
}

void sprite::setR(int value)
{
    r = value;
}

int sprite::getPosx() const
{
    return posx;
}

void sprite::setPosx(int value)
{
    posx = value;
}

int sprite::getPosy() const
{
    return posy;
}

void sprite::setPosy(int value)
{
    posy = value;
}

void sprite::up()
{
    posy -= 1*velocidad;
    setPos(posx, posy);
}

void sprite::down()
{
    posy += 1*velocidad;
    setPos(posx, posy);
}

void sprite::left()
{
    posx -= 1*velocidad;
    setPos(posx, posy);
}

void sprite::right()
{
    posx += 1*velocidad;
    setPos(posx, posy);
}

void sprite::move()
{
    QList<QGraphicsItem *> colliding = collidingItems();
    for(int i=0; i<colliding.size();i++){
        if(typeid (*(colliding[i]))==typeid (this)){
            scene()->removeItem(colliding[i]);
            delete colliding[i];
        }
    }
}




