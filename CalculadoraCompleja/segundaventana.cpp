#include "segundaventana.h"
#include "ui_segundaventana.h"

SegundaVentana::SegundaVentana(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SegundaVentana)
{
    ui->setupUi(this);
}

SegundaVentana::~SegundaVentana()
{
    delete ui;
}
