#include "fproduit1.h"
#include "ui_fproduit1.h"
#include <QPixmap>

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
void FProduit1::afficherProduit(const QString& nom, float prix/*, const QString& cheminImage*/, const QString& quantite, const QString& specialite)
{
    ui->labelNom->setText("Nom : " + nom);
    ui->labelPrix->setText("Prix : " + QString::number(prix) + " $");
    ui->labelQuantite->setText("Quantité : " + quantite);
    ui->labelSpecialite->setText(specialite);

    QPixmap image(":/images/boisson1.png");

        ui->labelImage->setPixmap(image);
        ui->labelImage->setScaledContents(true);

}
