#ifndef NOURRITURE_H
#define NOURRITURE_H
#include "produit.h"


class Nourriture:public Produit
{
protected:
    float _poids;
    bool _estVege;
public:

    Nourriture();

    float getPoids()const;
    bool getEstVege()const;

    void setPoids(float poids);
    void setEstVege(bool vege);


};

#endif // NOURRITURE_H
