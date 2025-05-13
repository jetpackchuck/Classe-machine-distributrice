
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QPushButton>
#include "produit.h"
#include "nourriture.h"
#include "boisson.h"
#include "fproduit1.h"

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

        QPixmap pixmap(":/images/boisson1.png");//QString::fromStdString(machine.getProduit(i)->getLien()));
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

    //QString cheminImage = QString::fromStdString(p->getLien());
    f->afficherProduit(nom, prix/*, cheminImage*/, quantite, specialite);
    f->exec();
}
void MainWindow::setMachine(const machineDistributrice& machine) {
    this->machine = machine;
}
