#ifndef CUERPO_H
#define CUERPO_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <cmath>
#include <iostream>
#include <fstream>
class cuerpo: public QObject,public QGraphicsItem
{
//atributos
private:
    double posX;//posicion en X de cada cuerpo
    double posY;//posicion en Y de cada cuerpo
    double masa;//masa de cada cuerpo
    double velX;//velocidad en X de cada cuerpo
    double velY;//velocidad en Y de cada cuerpo
    double aceX;//aceleración en X de cada cuerpo
    double aceY;//aceleración en Y de cada cuerpo
    double radio;//radio de cada cuerpo
    double angulo;//angulo para calcular aceleracion
    double G=1;//constante gravitacional
    double dt=1;//diferencial de tiempo
    Qt::GlobalColor color;//color de cada cuerpo
    float escala = 1000.0;
//metodos
public:
    cuerpo();
    cuerpo(double px,double py,double vx,double vy,double ax,double ay,double mas,double r,Qt::GlobalColor _color);//constructor
    //pinta los planetas
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void posicion();//asigna la posicon de los planetas
    //metodos set
    void setRadio(int r);
    void setPosx(double px);
    void setPosy(double py);
    void setVelx(double vx);
    void setVely(double vy);
    void setAcex(double ax);
    void setAcey(double ay);
    void setMasa(double mas);
    //metodos get
    double getPosx();
    double getPosy();
    double getVelx();
    double getVely();
    double getAcex();
    double getAcey();
    double getMasa();
    void Actualizar(cuerpo*planeta);//aplica las ecuaciones fisicas de movimiento

};

#endif // CUERPO_H
