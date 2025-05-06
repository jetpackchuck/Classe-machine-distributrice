#include "produit.h"
#include <iostream>
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

void Produit::addNbVentes()
{
    _nbVentes++;
}

void Produit::setNom(std::string nom)
{
    _nom=nom;
}
