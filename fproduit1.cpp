#include "fproduit1.h"
#include "ui_fproduit1.h"
#include <QPixmap>
#include "nourriture.h"
#include "boisson.h"
#include <QInputDialog>
#include <QMessageBox>

FProduit1::FProduit1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FProduit1)
{
    ui->setupUi(this);
}

FProduit1::~FProduit1()
{
    delete ui;
}

void FProduit1::on_pushButton_clicked()
{
    this->close();
}
void FProduit1::afficherProduit(const QString& nom, float prix, const QString& cheminImage, const QString& quantite, const QString& specialite)
{
    ui->labelNom->setText("Nom : " + nom);
    ui->labelPrix->setText("Prix : " + QString::number(prix) + " $");
    ui->labelQuantite->setText("Quantité : " + quantite);
    ui->labelSpecialite->setText(specialite);

    QPixmap image(cheminImage);

    ui->labelImage->setPixmap(image);
    ui->labelImage->setScaledContents(true);

}

void FProduit1::ouvrirProduit(int index, machineDistributrice *machine)
{
    Produit* p = machine->getProduit(index);
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

void FProduit1::demanderProduit(machineDistributrice *machine)
{
    bool ok;
    int id = QInputDialog::getInt(this, "Demande d'information", "Entrez l'ID du produit (entre 11 et 65) :", 11,11, 65, 1,  &ok);

    if (ok) {
        Produit* p = machine->getProduit(id);
        if (p != nullptr) {
            this->ouvrirProduit(id, machine);
        } else {
            QMessageBox::warning(this, "Erreur", "Aucun produit trouvé à cet ID.");
        }
    }
}
