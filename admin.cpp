#include "admin.h"
#include "ui_admin.h"
#include <QLabel>
#include <QPushButton>

Admin::Admin(machineDistributrice* machine, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Admin)
    ,m_machine(machine)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_changePW_pressed()
{
    m_machine->setMotDePasse(ui->newPW->text().toStdString());
}


void Admin::on_refill_pressed()
{
    if (ui->id->text().size() != 2 or ui->id->text().toInt() % 10 > 5)
    {
        ui->reponse->setText("id invalide");
    }
    else if(ui->Quantite->text().toInt() > 10 - m_machine->getCase(ui->id->text().toInt())._produits.size() or ui->Quantite->text().toInt() <= 0)
    {
        ui->reponse->setText("Quantité invalide");
    }
    else
    {
        m_machine->getCase(ui->id->text().toInt()).refill(ui->Quantite->text().toInt());
    }
}

