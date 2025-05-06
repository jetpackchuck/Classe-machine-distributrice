#include "nourriture.h"
#include<iostream>

Nourriture::Nourriture() {}

float Nourriture::getPoids()const
{
    return _poids;
}

bool Nourriture::getEstVege()const
{
    return _estVege;
}

void Nourriture::setPoids(float poids)
{
    _poids=poids;
}

void Nourriture::setEstVege(bool vege)
{
    _estVege=vege;
}
void Nourriture::afficher() const {
    std::cout << "Nom : " << getNom() << std::endl;
    std::cout << "Type : Nourriture" << std::endl;
    std::cout << "Prix achat : " << getPrixAchat() << std::endl;
    std::cout << "Prix vente : " << getPrixVente() << std::endl;
    std::cout << "Poids : " << _poids << " g" << std::endl;
    std::cout << "Végétarien : " << (_estVege ? "Oui" : "Non") << std::endl;
    std::cout << "-----------------------------" << std::endl;
}
