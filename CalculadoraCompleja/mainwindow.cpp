#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtMath"
#include "segundaventana.h"
#include "ui_segundaventana.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->resultado->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Variables globales
long long parte_real1,parte_real2;
long long parte_imaginaria1,parte_imaginaria2;

//Funcion para obtener los datos de los numeros complejos
void MainWindow::obtenerDatos(){
    parte_real1 = ui->real_1->text().toLongLong();
    parte_real2 = ui->real_2->text().toLongLong();

    parte_imaginaria1 = ui->imaginaria_1->text().toLongLong();
    parte_imaginaria2 = ui->imaginaria_2->text().toLongLong();
}

//Funcion para mostrar el texto en operaciones de suma,resta,multiplicacion y division
void MainWindow::mostrarTexto(){
    ui->texto_real->show();
    ui->texto_imaginaria->show();
    ui->resultado_real->show();
    ui->resultado_imaginaria->show();
    ui->texto_i->show();
    ui->resultado->hide();
}

//Funcion para mostrar el texto en operaciones de angulos, modulos y numeros polares
void MainWindow::mostrarTextoOtrasOperaciones(){
    ui->texto_real->hide();
    ui->texto_imaginaria->hide();
    ui->resultado_real->hide();
    ui->resultado_imaginaria->hide();
    ui->texto_i->hide();
    ui->resultado->show();
}

//Funcion suma
void MainWindow::on_Suma_clicked()
{

    obtenerDatos();
    mostrarTexto();
    ui->resultado_real->setText(QString::number(parte_real1+parte_real2));
    ui->resultado_imaginaria->setText(QString::number(parte_imaginaria1+parte_imaginaria2));

}

//Funcion resta
void MainWindow::on_Resta_clicked()
{
    obtenerDatos();
    mostrarTexto();
    ui->resultado_real->setText(QString::number(parte_real1-parte_real2));
    ui->resultado_imaginaria->setText(QString::number(parte_imaginaria1-parte_imaginaria2));
}


//Funcion multiplicacion
void MainWindow::on_Multiplicacion_clicked()
{
    obtenerDatos();
    mostrarTexto();
    ui->resultado_real->setText(QString::number((((parte_real1*parte_real2))-((parte_imaginaria1*parte_imaginaria2)))));
    ui->resultado_imaginaria->setText(QString::number((((parte_real1*parte_imaginaria2))+((parte_imaginaria1*parte_real2)))));

}


//Funcion division
void MainWindow::on_Division_clicked()
{
    obtenerDatos();
    mostrarTexto();
    ui->resultado_real->setText(QString::number(((parte_real1*parte_real2)+(parte_imaginaria1*parte_imaginaria2))/(pow(parte_real2,2)+(pow(parte_imaginaria2,2))),'p',3));
    ui->resultado_imaginaria->setText(QString::number(-((parte_real1*parte_imaginaria2)-(parte_imaginaria1*parte_real2))/(pow(parte_real2,2)+(pow(parte_imaginaria2,2))),'p',3));

}

//Funcion angulo numero complejo 1
void MainWindow::on_Angulo1_clicked()
{
    obtenerDatos();
    mostrarTextoOtrasOperaciones();

    ui->resultado->setText(QString::number(qFabs(qRadiansToDegrees(qAtan2(parte_imaginaria1,parte_real1))),'f',3) + "°");

}

//Funcion angulo numero complejo 2
void MainWindow::on_Angulo2_clicked()
{
    obtenerDatos();
    mostrarTextoOtrasOperaciones();

    ui->resultado->setText(QString::number(qFabs(qRadiansToDegrees(qAtan2(parte_imaginaria2,parte_real2))),'f',3) + "°");
}




//Funcion modulo numero complejo 1
void MainWindow::on_Modulo1_clicked()
{
    obtenerDatos();
    mostrarTextoOtrasOperaciones();

    ui->resultado->setText(QString::number(qSqrt(pow(parte_imaginaria1,2)+pow(parte_real1,2)),'f',3));

}

//Funcion modulo numero complejo 2
void MainWindow::on_Modulo2_clicked()
{
    obtenerDatos();
    mostrarTextoOtrasOperaciones();

    ui->resultado->setText(QString::number(qSqrt(pow(parte_imaginaria2,2)+pow(parte_real2,2)),'f',3));
}

//Funcion polar numero complejo 1

void MainWindow::on_Polar1_clicked()
{

    obtenerDatos();
    mostrarTextoOtrasOperaciones();

    QString texto;

    if(parte_imaginaria1 < 0){
        texto = "-";
    }
    else{
        texto = "+";
    }

    ui->resultado->setText(QString::number(qSqrt(pow(parte_imaginaria1,2)+pow(parte_real1,2)),'f',3) + "(" + "cos" + "(" + QString::number(qFabs(qRadiansToDegrees(qAtan2(parte_imaginaria1,parte_real1))),'f',3) + "°" + ")" + texto + "i" + "sin" + "(" + QString::number(qFabs(qRadiansToDegrees(qAtan2(parte_imaginaria1,parte_real1))),'f',3) + "°" + ")" + ")");

}

//Funcion polar numero complejo 2

void MainWindow::on_Polar2_clicked()
{
    obtenerDatos();
    mostrarTextoOtrasOperaciones();

    QString texto2;

    if(parte_imaginaria2 < 0){
        texto2 = "-";
    }
    else{
        texto2 = "+";
    }

    ui->resultado->setText(QString::number(qSqrt(pow(parte_imaginaria2,2)+pow(parte_real2,2)),'f',3) + "(" + "cos" + "(" + QString::number(qFabs(qRadiansToDegrees(qAtan2(parte_imaginaria2,parte_real2))),'f',3) + "°" + ")" + texto2 + "i" + "sin" + "(" + QString::number(qFabs(qRadiansToDegrees(qAtan2(parte_imaginaria2,parte_real2))),'f',3) + "°" + ")" + ")");
}

//Segunda ventana de acerca de

void MainWindow::on_SegundaVentana_clicked()
{
    SegundaVentana* ventana2 = new SegundaVentana(this);
    ventana2->show();

}

