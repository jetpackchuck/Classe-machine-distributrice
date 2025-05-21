#include <QApplication>
#include "mainwindow.h"
#include "nourriture.h"
#include "boisson.h"
#include "produit.h"
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include "admin.h"

QVector<Produit*> chargerProduitsDepuisCSV(const QString& chemin) {
    QVector<Produit*> produits;

    QFile fichier(chemin);
    if (!fichier.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Impossible d'ouvrir le fichier CSV";
        return produits;
    }

    QTextStream stream(&fichier);
    stream.readLine();

    while (!stream.atEnd()) {
        QString ligne = stream.readLine();
        QStringList elements = ligne.split(',');

        if (elements.size() >= 7) {

            QString nom = elements[0];
            QString type = elements[1];
            float prixAchat = elements[2].toFloat();
            float prixVente = elements[3].toFloat();
            float quantite = elements[4].toFloat();
            QString specialite = elements[5];
            QString lien = elements[6];

            Produit* produit = nullptr;

            if (type == "boisson") {
                Boisson* b = new Boisson();
                b->setNom(nom.toStdString());
                b->setPrixAchat(prixAchat);
                b->setPrixVente(prixVente);
                b->setVolume(quantite);
                b->setEstSansLactose(specialite.contains("sans", Qt::CaseInsensitive));
                b->setLien(lien.toStdString());
                produit = b;
            } else {
                Nourriture* n = new Nourriture();
                n->setNom(nom.toStdString());
                n->setPrixAchat(prixAchat);
                n->setPrixVente(prixVente);
                n->setPoids(quantite);
                n->setEstVege(specialite.contains("végé", Qt::CaseInsensitive));
                n->setLien(lien.toStdString());
                produit = n;
            }

            if (produit)
                produits.push_back(produit);
        }
    }

    fichier.close();
    return produits;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QVector<Produit*> produits = chargerProduitsDepuisCSV(":/images/images/Produits_avec_noms.csv");

    machineDistributrice* machine = new machineDistributrice();

    if (produits.size() >= 30) {
        machine->newMachine(
            produits[0], produits[1], produits[2], produits[3], produits[4],
            produits[5], produits[6], produits[7], produits[8], produits[9],
            produits[10], produits[11], produits[12], produits[13], produits[14],
            produits[15], produits[16], produits[17], produits[18], produits[19],
            produits[20], produits[21], produits[22], produits[23], produits[24],
            produits[25], produits[26], produits[27], produits[28], produits[29]
            );

    }

    MainWindow w;
    Admin* admin = new Admin(machine);
    w.setMachine(machine);

    w.show();

    return a.exec();
}
