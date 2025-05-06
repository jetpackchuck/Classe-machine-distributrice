#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
class Produit
{
protected:
    float _prixVente;
    float _prixAchat;
    int _nbVentes;
    std::string _nom;
public:

    Produit();

    float getPrixVente()const;
    float getPrixAchat()const;
    float getNbVentes()const;
    std::string getNom()const;

    void setPrixVente(float prixV);
    void setPrixAchat(float prixA);
    void addNbVentes();
    void setNom(std::string nom);

};

#endif // PRODUIT_H
