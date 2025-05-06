#ifndef BOISSON_H
#define BOISSON_H
#include "produit.h"

class Boisson:public Produit
{
protected:
    float _volume;
    bool _estSansLactose;
public:

    Boisson();

    float getVolume()const;
    bool getEstSansLactose()const;

    void setVolume(float volume);
    void setEstSansLactose(bool sansLactose);



};

#endif // BOISSON_H
