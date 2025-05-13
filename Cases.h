#pragma once
#include <iostream>
#include <stack>
#include "produit.h"


class Cases {
private:

	int _capacite;

public:
    int _id;
    Produit* _produit;
    std::stack<Produit*> _produits;
    Cases(int id, Produit* produit, int capacite=10);
	void refill(Produit produit, int quantite);

	bool estVide();
};
