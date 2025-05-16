#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPushButton>
#include "produit.h"
#include "boisson.h"
#include "fproduit1.h"
#include "nourriture.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    afficherTousLesProduits();

    for (int id = 11; id <= 65; ++id) {
        QString nomBouton = QString("pushButton%1").arg(id);
        QPushButton* bouton = this->findChild<QPushButton*>(nomBouton);
        if (bouton) {
            connect(bouton, &QPushButton::clicked, this, [=]() {
                this->ouvrirProduit(id, machine);
            });
        }
    }

    connect(ui->Bouton_1, &QPushButton::pressed, this, &MainWindow::on_Bouton_1_pressed);
    connect(ui->Bouton_2, &QPushButton::pressed, this, &MainWindow::on_Bouton_2_pressed);
    connect(ui->Bouton_3, &QPushButton::pressed, this, &MainWindow::on_Bouton_3_pressed);
    connect(ui->Bouton_4, &QPushButton::pressed, this, &MainWindow::on_Bouton_4_pressed);
    connect(ui->Bouton_5, &QPushButton::pressed, this, &MainWindow::on_Bouton_5_pressed);
    connect(ui->Bouton_6, &QPushButton::pressed, this, &MainWindow::on_Bouton_6_pressed);
    connect(ui->Bouton_Validation_2, &QPushButton::pressed, this, &MainWindow::on_Bouton_Validation_2_pressed);
    connect(ui->Bouton_Annulation_2, &QPushButton::pressed, this, &MainWindow::on_Bouton_Annulation_2_pressed);

    ui->productName_11->setText(QString::fromStdString(machine.getProduit(11)->getNom())); //met les noms de produits dans les lineedit de chaques cases
    ui->productName_12->setText(QString::fromStdString(machine.getProduit(12)->getNom()));
    ui->productName_13->setText(QString::fromStdString(machine.getProduit(13)->getNom()));
    ui->productName_14->setText(QString::fromStdString(machine.getProduit(14)->getNom()));
    ui->productName_15->setText(QString::fromStdString(machine.getProduit(15)->getNom()));

    ui->productName_21->setText(QString::fromStdString(machine.getProduit(21)->getNom()));
    ui->productName_22->setText(QString::fromStdString(machine.getProduit(22)->getNom()));
    ui->productName_23->setText(QString::fromStdString(machine.getProduit(23)->getNom()));
    ui->productName_24->setText(QString::fromStdString(machine.getProduit(24)->getNom()));
    ui->productName_25->setText(QString::fromStdString(machine.getProduit(25)->getNom()));

    ui->productName_31->setText(QString::fromStdString(machine.getProduit(31)->getNom()));
    ui->productName_32->setText(QString::fromStdString(machine.getProduit(32)->getNom()));
    ui->productName_33->setText(QString::fromStdString(machine.getProduit(33)->getNom()));
    ui->productName_34->setText(QString::fromStdString(machine.getProduit(34)->getNom()));
    ui->productName_35->setText(QString::fromStdString(machine.getProduit(35)->getNom()));

    ui->productName_41->setText(QString::fromStdString(machine.getProduit(41)->getNom()));
    ui->productName_42->setText(QString::fromStdString(machine.getProduit(42)->getNom()));
    ui->productName_43->setText(QString::fromStdString(machine.getProduit(43)->getNom()));
    ui->productName_44->setText(QString::fromStdString(machine.getProduit(44)->getNom()));
    ui->productName_45->setText(QString::fromStdString(machine.getProduit(45)->getNom()));

    ui->productName_51->setText(QString::fromStdString(machine.getProduit(51)->getNom()));
    ui->productName_52->setText(QString::fromStdString(machine.getProduit(52)->getNom()));
    ui->productName_53->setText(QString::fromStdString(machine.getProduit(53)->getNom()));
    ui->productName_54->setText(QString::fromStdString(machine.getProduit(54)->getNom()));
    ui->productName_55->setText(QString::fromStdString(machine.getProduit(55)->getNom()));

    ui->productName_61->setText(QString::fromStdString(machine.getProduit(61)->getNom()));
    ui->productName_62->setText(QString::fromStdString(machine.getProduit(62)->getNom()));
    ui->productName_63->setText(QString::fromStdString(machine.getProduit(63)->getNom()));
    ui->productName_64->setText(QString::fromStdString(machine.getProduit(64)->getNom()));
    ui->productName_65->setText(QString::fromStdString(machine.getProduit(65)->getNom()));

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::afficherTousLesProduits()
{
    for (int i = 0; i < 30; ++i) {
        QString nomLabel = QString("Produit%1").arg(i + 1);
        QLabel* label = this->findChild<QLabel*>(nomLabel.toUtf8().constData());

        QString nomLabelTexte = QString("Code%1").arg(i + 1);
        QLabel* labelTexte = this->findChild<QLabel*>(nomLabelTexte.toUtf8().constData());

        QPixmap pixmap(QString::fromStdString(machine.getProduit(i)->getLien()));  //QString::fromStdString(machine.getProduit(i)->getLien()));
        label->setPixmap(pixmap.scaled(label->size(), Qt::KeepAspectRatio));
        int id = i / 5 * 10 + (i % 5 + 1);
        labelTexte->setText(QString("ID: %1\n$%2").arg(id).arg(machine.getProduit(i)->getPrixVente(), 0, 'f', 2));
    }
}

void MainWindow::ouvrirProduit(int index, machineDistributrice& machine)
{
    Produit* p = machine.getProduit(index);
    FProduit1* f = new FProduit1(this);

    QString nom = QString::fromStdString(p->getNom());
    float prix = p->getPrixVente();
    QString quantite;
    QString specialite;

    if (p->getType() == "nourriture") {
        Nourriture* n = static_cast<Nourriture*>(p);
        quantite = QString::number(n->getPoids()) + " kg";
        specialite = n->getEstVege() ? "Le produit est végétarien" : "Le produit est non-végétarien";
    } else {
        Boisson* b = static_cast<Boisson*>(p);
        quantite = QString::number(b->getVolume()) + " ml";
        specialite = b->getEstSansLactose() ? "Le produit est sans lactose" : "Le produit est avec lactose";
    }

    QString cheminImage = QString::fromStdString(p->getLien());
    f->afficherProduit(nom, prix, cheminImage, quantite, specialite);
    f->exec();
}
void MainWindow::setMachine(machineDistributrice& machine) {
    this->machine = machine;
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
            machine.vente(machine, stoi(_choix));
            if(machine.getQuantite(stoi(_choix)) == 0)
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




