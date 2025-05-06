#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include "Cases.h"

class Machine_distributrice
{
private:
	std::vector<std::vector<Cases>> _cases;
	std::list<Produit> _logVentes;
	std::map<Produit, float> _prixProduits;

public:
	void newMachine(Produit p1, Produit p2, Produit p3, Produit p4, Produit p5, Produit p6, Produit p7, Produit p8, Produit p9, Produit p10, Produit p11, Produit p12, Produit p13, Produit p14, Produit p15, Produit p16, Produit p17, Produit p18, Produit p19, Produit p20, Produit p21, Produit p22, Produit p23, Produit p24, Produit p25, Produit p26, Produit p27, Produit p28, Produit p29, Produit p30);
};
