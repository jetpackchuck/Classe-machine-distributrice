#pragma once
#include <iostream>
#include <stack>
#include "produit.h"

class Cases {
private:
	std::stack<Produit> _produits;
	int _capacite;
	int _id;
public:
	Cases(int id, Produit produit, int capacite = 10);
	void refill(Produit produit, int quantite);
	void vente();
	bool estVide();
};
