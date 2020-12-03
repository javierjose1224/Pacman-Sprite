#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "cuerpo.h"
#include "paredes.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QObject>
#include <QTimer>
#include <QPixmap>
#include <QRect>
#include <QDesktopWidget>
#include <QDebug>
#include "sprite.h"
#include "moneda.h"
#include "fantasma.h"
#include "score.h"
#include "health.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void moveEnemy();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QList<paredes *> paredes2;
    QList<moneda *> monedas;
    Score *puntaje;
    Health *salud;
    fantasma *gosht;
    //QList<fantasma *> fantasmas;
    sprite *personaje;
    QTimer *timer;
    float x,y,ancho,alto;
    void keyPressEvent(QKeyEvent * evento);
    void mover();
};
#endif // MAINWINDOW_H
