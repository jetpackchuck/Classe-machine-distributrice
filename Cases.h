#pragma once
#include <iostream>
#include <stack>

class Cases {
private:
	std::stack<Produit> _produits;
	int _capacite;
	std::string _id;
public:
	Cases(std::string id, Produit produit, int capacite = 10);
	void refill(Produit produit, int quantite);
	void vente();
	bool estVide();};
