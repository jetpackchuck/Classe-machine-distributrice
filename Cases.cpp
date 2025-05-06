#include "Cases.h"
#include "fstream"

using namespace std;

Cases::Cases(string id, Produit produit, int capacite = 10)
{
	this->_id = id;
	
	for (size_t i = 0; i < _capacite; i++)
	{
		this->_produits.push(produit);
	}
}

void Cases::refill(Produit produit, int quantite)
{
	for (size_t i = 0; i < quantite; i++)
	{
		this->_produits.push(produit);
	}
	ofstream profit("Profit.txt");
	if (profit.is_open())
	{
		profit << "-" << quantite*(this->_produits.top()->_prixAchat);
		profit << ";";
	}
	profit.close();
}

void Cases::vente()
{
	this->_produits.pop();
	this->_produits.top()->_nbVentes++;
	
	ofstream profit("Profit.txt");
	if (profit.is_open())
	{
		profit << this->_produits.top()->_prixVente;
		profit << ";";
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

