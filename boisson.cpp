#include "boisson.h"
#include <iostream>

Boisson::Boisson() {}

float Boisson::getVolume()const
{
    return _volume;
}

bool Boisson::getEstSansLactose()const
{
    return _estSansLactose;
}

void Boisson::setVolume(float volume)
{
    _volume=volume;
}

void Boisson::setEstSansLactose(bool sansLactose)
{
    _estSansLactose=sansLactose;
}

void Boisson::afficher() const {
    std::cout << "Nom : " << getNom() << std::endl;
    std::cout << "Type : Boisson" << std::endl;
    std::cout << "Prix achat : " << getPrixAchat() << std::endl;
    std::cout << "Prix vente : " << getPrixVente() << std::endl;
    std::cout << "Volume : " << _volume << " L" << std::endl;
    std::cout << "Sans lactose : " << (_estSansLactose ? "Oui" : "Non") << std::endl;
    std::cout << "-----------------------------" << std::endl;
}
