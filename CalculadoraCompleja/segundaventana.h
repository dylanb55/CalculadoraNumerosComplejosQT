#ifndef SEGUNDAVENTANA_H
#define SEGUNDAVENTANA_H

#include <QDialog>

namespace Ui {
class SegundaVentana;
}

class SegundaVentana : public QDialog
{
    Q_OBJECT

public:
    explicit SegundaVentana(QWidget *parent = nullptr);
    ~SegundaVentana();

private:
    Ui::SegundaVentana *ui;
};

#endif // SEGUNDAVENTANA_H
