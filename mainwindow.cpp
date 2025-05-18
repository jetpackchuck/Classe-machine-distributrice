#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPushButton>
#include "produit.h"
#include "boisson.h"
#include "fproduit1.h"
#include "nourriture.h"
#include "admin.h"
#include <QInputDialog>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::afficherTousLesProduits()
{
    for (int i = 0; i < 30; ++i) {
        int id = (i / 5 + 1) * 10 + (i % 5 + 1);

        QString nomLabel = QString("Produit%1").arg(i + 1);
        QLabel* label = this->findChild<QLabel*>(nomLabel.toUtf8().constData());

        QString nomLabelTexte = QString("Code%1").arg(i + 1);
        QLabel* labelTexte = this->findChild<QLabel*>(nomLabelTexte.toUtf8().constData());

        QPixmap pixmap(QString::fromStdString(machine->getProduit(id)->getLien()));
        label->setPixmap(pixmap.scaled(label->size(), Qt::KeepAspectRatio));


    }
}


void MainWindow::setMachine(machineDistributrice* machine) {
    this->machine = machine;
    afficherTousLesProduits();



    connect(ui->Bouton_1, &QPushButton::pressed, this, &MainWindow::on_Bouton_1_pressed);
    connect(ui->Bouton_2, &QPushButton::pressed, this, &MainWindow::on_Bouton_2_pressed);
    connect(ui->Bouton_3, &QPushButton::pressed, this, &MainWindow::on_Bouton_3_pressed);
    connect(ui->Bouton_4, &QPushButton::pressed, this, &MainWindow::on_Bouton_4_pressed);
    connect(ui->Bouton_5, &QPushButton::pressed, this, &MainWindow::on_Bouton_5_pressed);
    connect(ui->Bouton_6, &QPushButton::pressed, this, &MainWindow::on_Bouton_6_pressed);
    connect(ui->Bouton_Validation_2, &QPushButton::pressed, this, &MainWindow::on_Bouton_Validation_2_pressed);
    connect(ui->Bouton_Annulation_2, &QPushButton::pressed, this, &MainWindow::on_Bouton_Annulation_2_pressed);

    ui->productName_11->setText(QString::fromStdString(machine->getProduit(11)->getNom())+ QString(" 11"));
    ui->productName_12->setText(QString::fromStdString(machine->getProduit(12)->getNom())+ QString(" 12"));
    ui->productName_13->setText(QString::fromStdString(machine->getProduit(13)->getNom())+ QString(" 13"));
    ui->productName_14->setText(QString::fromStdString(machine->getProduit(14)->getNom())+ QString(" 14"));
    ui->productName_15->setText(QString::fromStdString(machine->getProduit(15)->getNom())+ QString(" 15"));

    ui->productName_21->setText(QString::fromStdString(machine->getProduit(21)->getNom())+ QString(" 21"));
    ui->productName_22->setText(QString::fromStdString(machine->getProduit(22)->getNom())+ QString(" 22"));
    ui->productName_23->setText(QString::fromStdString(machine->getProduit(23)->getNom())+ QString(" 23"));
    ui->productName_24->setText(QString::fromStdString(machine->getProduit(24)->getNom())+ QString(" 24"));
    ui->productName_25->setText(QString::fromStdString(machine->getProduit(25)->getNom())+ QString(" 25"));

    ui->productName_31->setText(QString::fromStdString(machine->getProduit(31)->getNom())+ QString(" 31"));
    ui->productName_32->setText(QString::fromStdString(machine->getProduit(32)->getNom())+ QString(" 32"));
    ui->productName_33->setText(QString::fromStdString(machine->getProduit(33)->getNom())+ QString(" 33"));
    ui->productName_34->setText(QString::fromStdString(machine->getProduit(34)->getNom())+ QString(" 34"));
    ui->productName_35->setText(QString::fromStdString(machine->getProduit(35)->getNom())+ QString(" 35"));

    ui->productName_41->setText(QString::fromStdString(machine->getProduit(41)->getNom())+ QString(" 41"));
    ui->productName_42->setText(QString::fromStdString(machine->getProduit(42)->getNom())+ QString(" 42"));
    ui->productName_43->setText(QString::fromStdString(machine->getProduit(43)->getNom())+ QString(" 43"));
    ui->productName_44->setText(QString::fromStdString(machine->getProduit(44)->getNom())+ QString(" 44"));
    ui->productName_45->setText(QString::fromStdString(machine->getProduit(45)->getNom())+ QString(" 45"));

    ui->productName_51->setText(QString::fromStdString(machine->getProduit(51)->getNom())+ QString(" 51"));
    ui->productName_52->setText(QString::fromStdString(machine->getProduit(52)->getNom())+ QString(" 52"));
    ui->productName_53->setText(QString::fromStdString(machine->getProduit(53)->getNom())+ QString(" 53"));
    ui->productName_54->setText(QString::fromStdString(machine->getProduit(54)->getNom())+ QString(" 54"));
    ui->productName_55->setText(QString::fromStdString(machine->getProduit(55)->getNom())+ QString(" 55"));

    ui->productName_61->setText(QString::fromStdString(machine->getProduit(61)->getNom())+ QString(" 61"));
    ui->productName_62->setText(QString::fromStdString(machine->getProduit(62)->getNom())+ QString(" 62"));
    ui->productName_63->setText(QString::fromStdString(machine->getProduit(63)->getNom())+ QString(" 63"));
    ui->productName_64->setText(QString::fromStdString(machine->getProduit(64)->getNom())+ QString(" 64"));
    ui->productName_65->setText(QString::fromStdString(machine->getProduit(65)->getNom())+ QString(" 65"));

}

void MainWindow::on_Bouton_1_pressed()
{
    _choix +="1";
    if (_choix.size() <= 2)
    {

        ui->label_2->setText(QString::fromStdString(_choix));
    }
}


void MainWindow::on_Bouton_2_pressed()
{
    _choix +="2";
    if (_choix.size() <= 2)
    {

        ui->label_2->setText(QString::fromStdString(_choix));
    }
}


void MainWindow::on_Bouton_3_pressed()
{
    _choix +="3";
    if (_choix.size() <= 2)
    {
        ui->label_2->setText(QString::fromStdString(_choix));
    }
}


void MainWindow::on_Bouton_4_pressed()
{
    _choix +="4";
    if (_choix.size() <= 2)
    {

        ui->label_2->setText(QString::fromStdString(_choix));
    }
}


void MainWindow::on_Bouton_5_pressed()
{
    _choix +="5";
    if (_choix.size() <= 2)
    {

        ui->label_2->setText(QString::fromStdString(_choix));
    }
}


void MainWindow::on_Bouton_6_pressed()
{
    _choix +="6";
    if (_choix.size() <= 2)
    {

        ui->label_2->setText(QString::fromStdString(_choix));
    }
}




void MainWindow::on_Bouton_Validation_2_pressed()
{
    if(_choix == ""){

    }
    else{
        if(_choix.size()>2){
            _choix.resize(2);
        }
        if(_choix.size()==2 && _choix[1]!='6')
        {
            ui->label_2->setText("Choix validé");
            machine->vente(machine, stoi(_choix));
            if(machine->getQuantite(stoi(_choix)) == 0)
            {
                ui->label_2->setText(QString::fromStdString(_choix));
            }
        }
        else{
            ui->label_2->setText("X");
            _choix = "";
        }
    }
}


void MainWindow::on_Bouton_Annulation_2_pressed()
{
    _choix = "";
    ui->label_2->setText(QString::fromStdString(_choix));
}





void MainWindow::on_Bouton_Infos_2_clicked()
{
    FProduit1* f = new FProduit1(this);
    f->demanderProduit(machine);

}


void MainWindow::on_Bouton_Admin_2_clicked()
{
    bool ok;
    QString mdp = QInputDialog::getText(this, "Accès Admin", "Entrez le mot de passe :", QLineEdit::Password, "", &ok);

    if (ok) {
        if (machine->getMotDePasse() == mdp.toStdString()) {
            Admin* adminWindow = new Admin(machine, this);
            adminWindow->exec();
        } else {
            QMessageBox::warning(this, "Erreur", "Mot de passe incorrect.");
        }
    }
}

