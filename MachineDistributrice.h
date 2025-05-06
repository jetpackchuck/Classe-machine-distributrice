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
	void newMachine();
};
