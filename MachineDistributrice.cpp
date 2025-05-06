#include <iostream>
#include <vector>
#include "MachineDistributrice.h"

using namespace std;

void Machine_distributrice::newMachine() {
	
	vector<Cases> ligne1;
	ligne1.push_back(Cases(11, produit, 10));
	ligne1.push_back(Cases(12, produit, 10));
	ligne1.push_back(Cases(13, produit, 10));
	ligne1.push_back(Cases(14, produit, 10));
	ligne1.push_back(Cases(15, produit, 10));

	vector<Cases> ligne2;
	ligne2.push_back(Cases(21, produit, 10));
	ligne2.push_back(Cases(22, produit, 10));
	ligne2.push_back(Cases(23, produit, 10));
	ligne2.push_back(Cases(24, produit, 10));
	ligne2.push_back(Cases(25, produit, 10));

	vector<Cases> ligne3;
	ligne3.push_back(Cases(31, produit, 10));
	ligne3.push_back(Cases(32, produit, 10));
	ligne3.push_back(Cases(33, produit, 10));
	ligne3.push_back(Cases(34, produit, 10));
	ligne3.push_back(Cases(35, produit, 10));

	vector<Cases> ligne4;
	ligne4.push_back(Cases(41, produit, 10));
	ligne4.push_back(Cases(42, produit, 10));
	ligne4.push_back(Cases(43, produit, 10));
	ligne4.push_back(Cases(44, produit, 10));
	ligne4.push_back(Cases(45, produit, 10));

	vector<Cases> ligne5;
	ligne5.push_back(Cases(51, produit, 10));
	ligne5.push_back(Cases(52, produit, 10));
	ligne5.push_back(Cases(53, produit, 10));
	ligne5.push_back(Cases(54, produit, 10));
	ligne5.push_back(Cases(55, produit, 10));

	vector<Cases> ligne6;
	ligne6.push_back(Cases(61, produit, 10));
	ligne6.push_back(Cases(62, produit, 10));
	ligne6.push_back(Cases(63, produit, 10));
	ligne6.push_back(Cases(64, produit, 10));
	ligne6.push_back(Cases(65, produit, 10));

	this->_cases.push_back(ligne1);
	this->_cases.push_back(ligne2);
	this->_cases.push_back(ligne3);
	this->_cases.push_back(ligne4);
	this->_cases.push_back(ligne5);
	this->_cases.push_back(ligne6);

	map<Produit, float> prixProduits;
}