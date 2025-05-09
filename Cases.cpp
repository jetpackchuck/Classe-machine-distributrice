#include "Cases.h"
#include "fstream"
#include "produit.h"

using namespace std;

Cases::Cases(int id, Produit produit, int capacite = 10)
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
		profit << ";";
		profit << "-" << quantite*(this->_produits.top().getPrixAchat());
	}
	profit.close();

}

void Cases::vente(machineDistributrice machine)
{
	machine.addVente(this->_produits.top());

	this->_produits.pop();
	this->_produits.top().addNbVentes();
	
	ofstream profit("Profit.txt");
	if (profit.is_open())
	{
		profit << ";"; //Avant ou apres ?
		profit << this->_produits.top().getPrixVente();
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

