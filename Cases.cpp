#include "Cases.h"
#include "fstream"
#include "produit.h"
#include <QDebug>

using namespace std;

Cases::Cases(int id, Produit* produit, int capacite)
{
	this->_id = id;
    this->_produit=produit;

    for (size_t i = 0; i < capacite; i++)
    {
        this->_produits.push(this->_produit);

    }
}

void Cases::refill(int quantite)
{
	for (size_t i = 0; i < quantite; i++)
	{
        this->_produits.push(this->_produit);

	}
    ofstream profit("Profit.txt",ios::app);
	if (profit.is_open())
	{
		profit << ";";
        profit << "-" << quantite*(this->_produits.top()->getPrixAchat());
	}
	profit.close();

}



bool Cases::estVide()
{
	if (this->_produits.size() == 0)
	{
		return true;
	}
	return false;
}

