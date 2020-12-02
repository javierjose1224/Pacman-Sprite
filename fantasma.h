#ifndef FANTASMA_H
#define FANTASMA_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>

class fantasma:  public QObject, public QGraphicsItem
{

    Q_OBJECT
    int r;
    int posx=250, posy=280;
    int velocidad = 1;

public:
    explicit fantasma(QObject *parent = nullptr);
    //fantasma(int r_, int x, int y);//

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


#endif // FANTASMA_H
