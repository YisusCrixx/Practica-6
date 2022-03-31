#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

#include <QVector>
#include <QTimer>
#include"cuerpo.h"

class movimiento:public QObject
{
public:
    movimiento(cuerpo,cuerpo,cuerpo);
private:
    QVector<cuerpo> sistema;
    QTimer *timer;
signals:
public slots:
    void Actualizar(cuerpo);

};

#endif // MOVIMIENTO_H
