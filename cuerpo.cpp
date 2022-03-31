#include "cuerpo.h"

cuerpo::cuerpo()
{
}
cuerpo::cuerpo(double px, double py, double vx, double vy, double ax, double ay, double mas, double r,Qt::GlobalColor _color):escala(0.05)
{
    //inicializamos los atributos
    posX=px;
    posY=py;
    velX=vx;
    velY=vy;
    aceX=ax;
    aceY=ay;
    masa=mas;
    radio=r;
    color=_color;
    setPos(posX*escala,-posY*escala);//asignamos la posicion de los puntos
}
void cuerpo::setRadio(int r)//asigna el radio del cuerpo
{
    radio=r;
}
void cuerpo::setPosx(double px)//asigna la posicion en x del cuerpo
{
    posX=px;
}
double cuerpo::getPosx()//retorna la posicion en x del cuerpo
{
    return posX;
}
void cuerpo::setPosy(double py)//asigna la posicion en y del cuerpo
{
    posY=py;
}
double cuerpo::getPosy()//retorna la posicion en y del cuerpo
{
    return posY;
}
void cuerpo::setVelx(double vx)//asigna la velocidad en x del cuerpo
{
    velX=vx;
}
double cuerpo::getVelx()//retorna la velocidad en x del cuerpo
{
    return velX;
}
void cuerpo::setVely(double vy)//asigna la velocidad en y del cuerpo
{
    velY=vy;
}
double cuerpo::getVely()//retorna la velocidad en y del cuerpo
{
    return velY;
}
void cuerpo::setAcex(double ax)//asigna la aceleracion en x del cuerpo
{
    aceX=ax;
}
double cuerpo::getAcex()//retorna la aceleracion en x del cuerpo
{
    return aceX;
}
void cuerpo::setAcey(double ay)//asigna la aceleracion en y del cuerpo
{
    aceY=ay;
}
double cuerpo::getAcey()//retorna la aceleracion en y del cuerpo
{
    return aceY;
}
void cuerpo::setMasa(double mas)//asigna masa del cuerpo
{
    masa=mas;
}
double cuerpo::getMasa()//retorna masa del cuerpo
{
    return masa;
}
QRectF cuerpo::boundingRect() const
{
    return QRectF(-1*escala*radio,-1*escala*radio,2*escala*radio,2*escala*radio);
}
void cuerpo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //dibujamos cada planeta
    painter->setBrush(Qt::GlobalColor(color));
    painter->drawEllipse(boundingRect());
}
void cuerpo::posicion()//posiciona los cuerpos en la escena
{
    setPos(posX*escala,-posY*escala);
}
void cuerpo::Actualizar(cuerpo *planeta)//aplica las ecuaciones fisicas
{
    aceX=0;
    aceY=0;
    double dist,ang,deltaX,deltaY;
    deltaX=(*planeta).getPosx()-posX;
    deltaY=(*planeta).getPosy()-posY;
    ang=atan2(deltaY,deltaX);//calcula el angulo necesario para la aceleracion
    dist=sqrt((deltaX*deltaX)+(deltaY*deltaY));//calcula el radio
    dist = sqrt(pow((*planeta).getPosx()-posX,2)+pow((*planeta).getPosy()-posY,2)); //r : distancia entre los 2 planetas
    aceX+= G*(*planeta).getMasa()*((*planeta).getPosx()-posX)/pow(dist,3); //aceleracion gravitacional X
    aceY+= G*(*planeta).getMasa()*((*planeta).getPosy()-posY)/pow(dist,3); //aceleracion gravitacional Y
    velX=velX+aceX*dt;//calcula la velocidad en x
    velY=velY+aceY*dt;//calcula la velocidad en y
    posX=posX+(velX*dt);//calcula la posicion en x
    posY=posY+(velY*dt);//calcula la posicion en y
    /*aceX=(G*masa*cos(ang))/pow(dist,2);//calcula la aceleracion en x
    aceY=(G*masa*sin(ang))/pow(dist,2);//calcula la aceleracion en y
    velX=velX+aceX*dt;//calcula la velocidad en x
    velY=velY+aceY*dt;//calcula la velocidad en y
    posX=posX+(velX*dt)+(aceX*(dt*dt)*0.5);//calcula la posicion en x
    posY=posY+(velY*dt)+(aceY*(dt*dt)*0.5);//calcula la posicion en y
    */posicion();//posiciona el cuerpo en la escena
}
