#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void obtenerDatos();
    void mostrarTexto();
    void mostrarTextoOtrasOperaciones();
    void on_Suma_clicked();
    void on_Resta_clicked();
    void on_Multiplicacion_clicked();
    void on_Division_clicked();
    void on_Angulo1_clicked();
    void on_Angulo2_clicked();
    void on_Modulo1_clicked();
    void on_Modulo2_clicked();
    void on_Polar1_clicked();
    void on_Polar2_clicked();
    void on_SegundaVentana_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
