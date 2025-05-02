#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <map>

class Machine_distributrice
{
private:
	std::vector<std::vector<Case>> _cases;
	std::list<float> _logVentes;
	std::map<Produit, float prix> _prixProduits;

public:
	void newMachine();
};