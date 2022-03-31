#include "movimiento.h"
#include <QTimer>
#include <cmath>

movimiento::movimiento(cuerpo sol,cuerpo tierra,cuerpo marte )
{
    sistema.push_back(tierra);
    sistema.push_back(marte);
    timer=new QTimer();
    connect(timer,&QTimer::timeout,this,&movimiento::Actualizar);
    timer->start(150);//velocidad con la que cambia la imagen
}

void movimiento::Actualizar(cuerpo sol)
{
    QVector<cuerpo>::iterator iter;
    for(iter=sistema.begin();iter!=sistema.end();iter++){
        /*
        double dist, deltaX,deltaY;
        deltaX=sol.getPosx()-iter->getPosx();
        deltaY=sol.getPosy()-iter->getPosy();
        dist=sqrt(pow(deltaX,2)+pow(deltaY,2));
        double ang;
        ang=atan2(iter->getPosy()-sol.getPosy(),iter->getPosy()-sol.getPosx());
        double ax=0,Vx=0,X=0;
        ax=((*iter).getMasa()*cos(ang))/pow(dist,2);
        Vx=(ax*deltaT);
        X=X+Vx*deltaT+(ax*deltaT*0.5);
        double ay=0,Vy=0;
        ay=((*iter).getMasa()*sin(ang))/pow(dist,2);
        Vy=iter->g+(ay*deltaT);
        Y=Y+Vy*deltaT+(ay*deltaT*deltaT*0.5);
        */
    }



}
