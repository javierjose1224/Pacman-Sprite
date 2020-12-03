#ifndef SPRITE_H
#define SPRITE_H

//#include "mainwindow.h"
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>

class sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT
    int r;//
    int posx=20, posy=20;//
    int velocidad = 10;//

public:
    explicit sprite(QObject *parent = nullptr);
    sprite(int r_, int x, int y);//
    QTimer * timer;
    QPixmap *pixmap;
    int getR() const;
    void setR(int radio);
    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);

    float filas, columnas, ancho, alto;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void up();
    void down();
    void left();
    void right();
    void move();


signals:

public slots:
    void Actualizacion();

};

#endif // SPRITE_H
