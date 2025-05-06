/*#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}*/
#include <QCoreApplication>
#include "CSVParser.h"
#include "Boisson.h"
#include "Nourriture.h"
#include <fstream>
#include <vector>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    std::ifstream fichier("C:/Users/marcl/Downloads/tableConvert.com_7di07o.csv");
    if (!fichier) {
        std::cerr << "Erreur d'ouverture du fichier CSV." << std::endl;
        return 1;
    }

    CSVParser parser(',', true); // lecture avec noms de colonnes
    parser.parse(fichier);

    std::vector<Produit*> produits;

    for (size_t i = 0; i < parser.getNumRows(); ++i) {
        std::string type = parser.getString(i, "Type");
        std::string nom = parser.getString(i, "Nom");

        float prixVente = parser.getDouble(i, "PrixVente");
        float prixAchat = parser.getDouble(i, "PrixAchat");
        float quantite = parser.getDouble(i, "Quantité"); // devient volume ou poids
        bool condition = parser.getString(i, "Condition") == "true";

        if (type == "boisson") {
            Boisson* b = new Boisson();
            b->setNom(nom);
            b->setPrixVente(prixVente);
            b->setPrixAchat(prixAchat);
            b->setVolume(quantite);
            b->setEstSansLactose(condition);
            produits.push_back(b);
        }
        else if (type == "nourriture") {
            Nourriture* n = new Nourriture();
            n->setNom(nom);
            n->setPrixVente(prixVente);
            n->setPrixAchat(prixAchat);
            n->setPoids(quantite);
            n->setEstVege(condition);
            produits.push_back(n);
        }
    }

    // ✅ Affichage dynamique des produits
    for (Produit* p : produits) {
        p->afficher();
    }

    // Nettoyage mémoire
    for (Produit* p : produits) {
        delete p;
    }

    return 0;
}
