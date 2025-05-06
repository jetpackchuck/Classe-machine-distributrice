#ifndef NOURRITURE_H
#define NOURRITURE_H
#include "produit.h"
#include "CSVParser.h"


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

    void afficher() const override;
};

#endif // NOURRITURE_H
