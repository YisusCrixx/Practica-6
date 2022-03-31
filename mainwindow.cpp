#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QString>
#include <QDebug>
#include <iostream>
#include <fstream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // FALTA ARREGLAR LA ACTUALIZACION
    int h,hlim,vlim,dt;
    int cont=0;
    ui->setupUi(this);
    h=ui->graphicsView->height();

    hlim = ui->graphicsView->width()-2;
    vlim = ui->graphicsView->height()-2;
    dt = 1.0;


    //apagar_todo();

    ui->planetas->setEnabled(true);
    ui->Agregar->setEnabled(true);



    timer = new QTimer(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(-hlim/2,-vlim/2,hlim,vlim); // Añadir la tmño de la escena

    ui->graphicsView->setScene(scene);
    ui->graphicsView->scale(0.5,0.5);
    ui->centralwidget->adjustSize();
    ui->num->display(cont);


    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizar()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete timer;
    for (int i=0;i<sistema.size() ;i++ ) {
        delete sistema[i];
    }

}
void MainWindow::Actualizar()//actualiza el estado y los datos de cada cuerpo
{
    for (int i=0;i<sistema.size() ;i++ ) {
        for (int j=0;j<sistema.size() ;j++ ) {
            if(i!=j){
                sistema.at(i)->Actualizar(sistema[j]);
            }
        }

    }
}
void MainWindow::apagar_todo()
{
    ui->vyo->setEnabled(false);
    ui->vxo->setEnabled(false);
    ui->yo->setEnabled(false);
    ui->xo->setEnabled(false);
    ui->iniciar->setEnabled(false);
    ui->parar->setEnabled(false);
    ui->Agregar->setEnabled(false);
    ui->planetas->setEnabled(false);
    ui->masa->setEnabled(false);
    ui->radio->setEnabled(false);
    ui->pausa->setEnabled(false);
}


void MainWindow::on_Agregar_clicked()
{

    if (ui->planetas->value() >= 2){
        Numplanet = ui->planetas->value();
        apagar_todo();
        ui->vyo->setEnabled(true);
        ui->vxo->setEnabled(true);
        ui->yo->setEnabled(true);
        ui->xo->setEnabled(true);
        ui->masa->setEnabled(true);
        ui->radio->setEnabled(true);
        ui->Agregar->setEnabled(true);
        ui->planetas->setValue(0);
    }

    else  if (Numplanet != 0){
        ui->num->display(cont+1);
        sistema.append(new cuerpo(ui->xo->value(),ui->yo->value(),ui->vxo->value(),ui->vyo->value(),0,0,ui->masa->value(),ui->radio->value(),Qt::black));
        cont ++;
        if (cont == Numplanet){//label en que planeta vas
            apagar_todo();
            ui->iniciar->setEnabled(true);
        }
    }

}


void MainWindow::on_iniciar_clicked() //ejecutar simulacion
{

    for (int i=0;i<sistema.size() ;i++ ) {
        scene->addItem(sistema.at(i));
    }

    ui->parar->setEnabled(true);
    ui->iniciar->setEnabled(false);
    ui->pausa->setEnabled(true);
    timer->start(1.0);
    //zoom();
}


void MainWindow::on_parar_clicked()
{
    ui->parar->setEnabled(false);
    ui->Agregar->setEnabled(true);
    timer->stop();
    //n=0;
    cont =0;
    for (int i=0;i<sistema.size() ;i++ ) {
        scene->removeItem(sistema.at(i));
    }
}

void MainWindow::on_pausa_clicked()
{
    ui->parar->setEnabled(false);
    ui->Agregar->setEnabled(false);
    ui->iniciar->setEnabled(true);

    timer->stop();

}

