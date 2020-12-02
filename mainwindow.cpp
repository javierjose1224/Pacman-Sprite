#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sprite.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRect Desktop = QApplication::desktop()->screenGeometry();
    x=Desktop.x();
    y=Desktop.y();
    ancho=Desktop.width();
    alto=Desktop.height();

    scene = new QGraphicsScene(x,y,ancho,alto);
    scene->setBackgroundBrush(Qt::black);
    //scene->setBackgroundBrush(QPixmap(":/images/cosmos.jpg"));
    ui->graphicsView->setScene(scene);
    personaje = new sprite();
    scene->setSceneRect(0,0,540,600);
    scene->addItem(personaje);
    personaje->setPos(20,20);
    gosht = new fantasma();
    gosht->setPos(250,280);
    scene->addItem(gosht);

{
paredes2.append(new paredes(20,220,20,20));//left up
paredes2.append(new paredes(20,240,20,-360));//left down

paredes2.append(new paredes(100,20,0,-180));  // -
paredes2.append(new paredes(20,60,-80,-200)); // |
paredes2.append(new paredes(100,20,20,-240)); // -

paredes2.append(new paredes(120,20,20,-300)); // -
paredes2.append(new paredes(20,60,-80,-320)); // |
paredes2.append(new paredes(80,20,0,-360));   // -

paredes2.append(new paredes(20,220,-540,20));//right up
paredes2.append(new paredes(20,240,-540,-360));//right down

paredes2.append(new paredes(100,20,-440,-180));  // -
paredes2.append(new paredes(20,60,-440,-200)); // |
paredes2.append(new paredes(100,20,-460,-240)); // -

paredes2.append(new paredes(120,20,-440,-300)); // -
paredes2.append(new paredes(20,60,-440,-320)); // |
paredes2.append(new paredes(80,20,-460,-360));   // -

paredes2.append(new paredes(580,20,20,20));//up
paredes2.append(new paredes(580,20,20,-600));//up

//cajas superiores
    paredes2.append(new paredes(60,40,-40,-40));//left box up
    paredes2.append(new paredes(60,20,-40,-120));//sub left

    paredes2.append(new paredes(80,40,-140,-40));//left box up_2
    paredes2.append(new paredes(80,40,-140,-40));//middle

    paredes2.append(new paredes(60,40,-440,-40));//right box up
    paredes2.append(new paredes(80,40,-320,-40));//right box up_2
    paredes2.append(new paredes(60,20,-440,-120));//sub right

    paredes2.append(new paredes(140,20,-200,-120));//up center
    paredes2.append(new paredes(20,80,-260,-120));//up center

paredes2.append(new paredes(20,100,-260,20));//up

//T laterales up
    paredes2.append(new paredes(20,140,-140,-120));//T left vertical
    paredes2.append(new paredes(80,20,-140,-180));//T left horizontal

    paredes2.append(new paredes(20,140,-380,-120));//T right vertical
    paredes2.append(new paredes(80,20,-320,-180));//T right horizontal
//fin de la t up

//laterales tunel y T
    paredes2.append(new paredes(20,80,-140,-300));// lateral left
    paredes2.append(new paredes(20,80,-380,-300));//lateral right

    paredes2.append(new paredes(140,20,-200,-360));//middle
    paredes2.append(new paredes(20,80,-260,-360));//up center

    paredes2.append(new paredes(140,20,-200,-480));
    paredes2.append(new paredes(20,60,-260,-500));
//fin de t y lateral

//Parte Inferior izquierda
    paredes2.append(new paredes(60,20,-40,-420));
    paredes2.append(new paredes(20,60,-80,-440));

    paredes2.append(new paredes(40,20,0,-480));

    paredes2.append(new paredes(180,20,-40,-540));
    paredes2.append(new paredes(20,60,-140,-480));

    paredes2.append(new paredes(80,20,-140,-420));

//Parte inferior derecha
    paredes2.append(new paredes(60,20,-440,-420));
    paredes2.append(new paredes(20,60,-440,-440));

    paredes2.append(new paredes(40,20,-500,-480));

    paredes2.append(new paredes(180,20,-320,-540));
    paredes2.append(new paredes(20,60,-380,-480));

    paredes2.append(new paredes(80,20,-320,-420));

// Caja fantasmas
    paredes2.append(new paredes(50,20,-200,-240));
    paredes2.append(new paredes(50,20,-290,-240));
    paredes2.append(new paredes(140,20,-200,-300));
    paredes2.append(new paredes(20,80,-200,-240));
    paredes2.append(new paredes(20,80,-320,-240));
}
    for(int i=20;i<540;i=i+20)
    {
        for(int j=20;j<600;j=j+20)
        {
            monedas.append(new moneda(10,10,i,j));
        }
    }

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveEnemy()));
    timer->start(8);


//    for(auto it2=monedas.begin();it2!=monedas.end();it2++){
//        scene->addItem(*it2);
//    }

    for(auto it=paredes2.begin();it!=paredes2.end();it++)
    {
        scene->addItem(*it);
    }

}

//void MainWindow::mover(){
//    for(auto it2=monedas.begin();it2!=monedas.end();it2++){
//        if(personaje->collidesWithItem<monedas[it2]>){

//        }
//    }
//}


void MainWindow::keyPressEvent(QKeyEvent *evento)
{
//    if(evento->key() == Qt::Key_A){
//        personaje->left();
//        for(auto it=paredes2.begin();it!=paredes2.end();it++)
//        {
//            if(personaje->collidesWithItem(*it)){
//                personaje->right();
//            }
//        }
//    }
//    else if(evento->key() == Qt::Key_D){
//        personaje->right();
//        for(auto it=paredes2.begin();it!=paredes2.end();it++)
//        {
//            if(personaje->collidesWithItem(*it)){
//                personaje->left();
//            }
//        }
//    }
    if(evento->key() == Qt::Key_A){
        personaje->left();
        personaje->setRotation(180);
        qDebug()<<"posicion en x "<<personaje->x();
        if(personaje->x()==-30 && personaje->y()==280)
        {
            personaje->setPosx(560);
            personaje->setPosy(280);
        }
        for(auto it=paredes2.begin();it!=paredes2.end();it++)
        {
            if(personaje->collidesWithItem(*it)){
                personaje->right();
            }
        }
        for(int i=0;i<monedas.size();i++)
        {
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                monedas.removeAt(i);
            }
        }
        if(personaje->collidesWithItem(gosht))
        {
            qDebug() <<"PERSONAJE PERDIO ";
        }
    }
    else if(evento->key() == Qt::Key_D){
        personaje->right();
        personaje->setRotation(0);
        qDebug()<<"posicion en x "<<personaje->x();
        if(personaje->x()==570 && personaje->y()==280)
        {
            personaje->setPosx(-20);
            personaje->setPosy(280);
        }
        for(auto it=paredes2.begin();it!=paredes2.end();it++)
        {
            if(personaje->collidesWithItem(*it)){
                personaje->left();
            }
        }
        for(int i=0;i<monedas.size();i++)
        {
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                monedas.removeAt(i);
            }
        }
        if(personaje->collidesWithItem(gosht))
        {
            qDebug() <<"PERSONAJE PERDIO ";
        }
    }
    else if(evento->key() == Qt::Key_W)
    {
        personaje->up();
        personaje->setRotation(270);
        qDebug()<<"posicion en y "<<personaje->y();
        for(auto it=paredes2.begin();it!=paredes2.end();it++)
        {
            if(personaje->collidesWithItem(*it)){
                personaje->down();
            }
        }
        for(int i=0;i<monedas.size();i++)
        {
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                monedas.removeAt(i);
            }
        }
        if(personaje->collidesWithItem(gosht))
        {
            qDebug() <<"PERSONAJE PERDIO ";
        }
    }
    else if(evento->key() == Qt::Key_S)
    {
        personaje->down();
        personaje->setRotation(90);
        qDebug()<<"posicion en y "<<personaje->y();
        for(auto it=paredes2.begin();it!=paredes2.end();it++)
        {
            if(personaje->collidesWithItem(*it)){
                personaje->up();
            }
        }

        for(int i=0;i<monedas.size();i++)
        {
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                monedas.removeAt(i);
            }
        }
        if(personaje->collidesWithItem(gosht))
        {
            qDebug() <<"PERSONAJE PERDIO ";
        }
    }
}

void MainWindow::moveEnemy()
{
    if(gosht->x() < personaje->x())
    {
        gosht->right();
        for(auto it=paredes2.begin();it!=paredes2.end();it++)
        {
            if(gosht->collidesWithItem(*it)){
                gosht->left();
            }
        }
    }
    else if(gosht->x() > personaje->x()){
        gosht->left();
        for(auto it=paredes2.begin();it!=paredes2.end();it++)
        {
            if(gosht->collidesWithItem(*it)){
                gosht->right();
            }
        }
    }

    if(gosht->y() < personaje->y()){
        gosht->down();
        for(auto it=paredes2.begin();it!=paredes2.end();it++)
        {
            if(gosht->collidesWithItem(*it)){
                gosht->up();
            }
        }
    }
    else if(gosht->y() > personaje->y()){
        gosht->up();
        for(auto it=paredes2.begin();it!=paredes2.end();it++)
        {
            if(gosht->collidesWithItem(*it)){
                gosht->down();
            }
        }
    }
    //gosht->setPos(gosht->posx(250),gosht->posy(280));

}

MainWindow::~MainWindow()
{
    delete ui;
}
