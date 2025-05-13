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


