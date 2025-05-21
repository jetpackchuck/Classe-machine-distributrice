#include "produit.h"
using namespace std;

Produit::Produit() {
    _nbVentes=0;
}

float Produit::getPrixVente() const
{
    return _prixVente;
}

float Produit::getPrixAchat() const
{
    return _prixAchat;
}

float Produit::getNbVentes() const
{
    return _nbVentes;
}

string Produit::getType() const
{return _type;

}

string Produit::getLien() const
{
    return _lienImage;
}

string Produit::getNom() const
{
    return _nom;
}

void Produit::setPrixVente(float prixV)
{
    _prixVente=prixV;
}

void Produit::setPrixAchat(float prixA)
{
    _prixAchat=prixA;
}

void Produit::setNbVentes(float nb)
{
    _nbVentes=nb;
}

void Produit::setNom(std::string nom)
{
    _nom=nom;
}

void Produit::setLien(std::string lien)
{
    _lienImage=lien;
}

void Produit::setType(std::string type)
{
    _type=type;
}
