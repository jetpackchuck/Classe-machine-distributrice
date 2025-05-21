#include "nourriture.h"

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

