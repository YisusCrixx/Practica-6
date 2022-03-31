#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "cuerpo.h"
#include <QTimer>
#include <QList>
#include <iostream>
#include <fstream>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    int planetacollision(cuerpo *);//verifica si el planeta colisiona con el cuerpo fijo
    void write(double, double);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;//creamos escena
    cuerpo *sol,*tierra,*marte;//creamos los objetos a interactuar
    QTimer *timer;
    QList<cuerpo*>sistema;//lista que contendra los cuerpos
    int Numplanet=0;
    int cont=0;
signals:
private slots:
    void on_Agregar_clicked();
    void on_iniciar_clicked();
    void on_parar_clicked();
    void on_pausa_clicked();
    void apagar_todo();
    void Actualizar();//actualiza los datos y los objetos de la escena

};
#endif // MAINWINDOW_H
