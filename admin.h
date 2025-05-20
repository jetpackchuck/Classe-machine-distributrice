#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>

#include "MachineDistributrice.h"


namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(machineDistributrice* machine,QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_changePW_pressed();

    void on_refill_pressed();

    void on_voirStats_clicked();

private:
    Ui::Admin *ui;
    machineDistributrice* m_machine;
};

#endif // ADMIN_H
