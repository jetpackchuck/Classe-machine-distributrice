#include <iostream>
#include <vector>
#include <fstream>
#include "MachineDistributrice.h"

using namespace std;

void machineDistributrice::newMachine(Produit* p1, Produit* p2, Produit* p3, Produit* p4, Produit* p5, Produit* p6, Produit* p7, Produit* p8, Produit* p9, Produit* p10, Produit* p11, Produit* p12, Produit* p13, Produit* p14, Produit* p15, Produit* p16, Produit* p17, Produit* p18, Produit* p19, Produit* p20, Produit* p21, Produit* p22, Produit* p23, Produit* p24, Produit* p25, Produit* p26, Produit* p27, Produit* p28, Produit* p29, Produit* p30) {
	
	vector<Cases> ligne1;
    ligne1.push_back(Cases(11, p1, 10));
	ligne1.push_back(Cases(12, p2, 10));
	ligne1.push_back(Cases(13, p3, 10));
	ligne1.push_back(Cases(14, p4, 10));
	ligne1.push_back(Cases(15, p5, 10));

	vector<Cases> ligne2;
	ligne2.push_back(Cases(21, p6, 10));
	ligne2.push_back(Cases(22, p6, 10));
	ligne2.push_back(Cases(23, p8, 10));
	ligne2.push_back(Cases(24, p9, 10));
	ligne2.push_back(Cases(25, p10, 10));

	vector<Cases> ligne3;
	ligne3.push_back(Cases(31, p11, 10));
	ligne3.push_back(Cases(32, p12, 10));
	ligne3.push_back(Cases(33, p13, 10));
	ligne3.push_back(Cases(34, p14, 10));
	ligne3.push_back(Cases(35, p15, 10));

	vector<Cases> ligne4;
	ligne4.push_back(Cases(41, p16, 10));
	ligne4.push_back(Cases(42, p17, 10));
	ligne4.push_back(Cases(43, p18, 10));
	ligne4.push_back(Cases(44, p19, 10));
	ligne4.push_back(Cases(45, p20, 10));

	vector<Cases> ligne5;
	ligne5.push_back(Cases(51, p21, 10));
	ligne5.push_back(Cases(52, p22, 10));
	ligne5.push_back(Cases(53, p23, 10));
	ligne5.push_back(Cases(54, p24, 10));
	ligne5.push_back(Cases(55, p25, 10));

	vector<Cases> ligne6;
	ligne6.push_back(Cases(61, p26, 10));
	ligne6.push_back(Cases(62, p27, 10));
	ligne6.push_back(Cases(63, p28, 10));
	ligne6.push_back(Cases(64, p29, 10));
	ligne6.push_back(Cases(65, p30, 10));

	this->_cases.push_back(ligne1);
	this->_cases.push_back(ligne2);
	this->_cases.push_back(ligne3);
	this->_cases.push_back(ligne4);
	this->_cases.push_back(ligne5);
	this->_cases.push_back(ligne6);

	map<Produit, float> prixProduits;

	this->_motDePasse = "1234";
}

void machineDistributrice::addVente(Produit* produit)
{
	this->_logVentes.push_back(produit);
}
void machineDistributrice::vente(/*Cases& cases,*/ machineDistributrice& machine, int id)
{
    int firstNum = id / 10;
    int secondNum = id % 10;
    machine.addVente(machine.getProduit(id));

    machine._cases[firstNum][secondNum]._produits.pop();


    ofstream profit("Profit.txt");
    if (profit.is_open())
    {
        profit << ";"; //Avant ou apres ?
        profit << machine.getProduit(id)->getPrixVente()-machine.getProduit(id)->getPrixAchat();
    }
    profit.close();

}

Produit* machineDistributrice::getProduit(int id)
{
    for (auto& ligne : _cases) {
        for (auto& c : ligne) {
            if (c._id == id) {
                return c._produit;
            }

        }
    }
    return nullptr;
}
int machineDistributrice::getQuantite(int id)
{
    for (auto& ligne : _cases) {
        for (auto& c : ligne) {
            if (c._id == id) {
                return c._produits.size();
            }
        }
    }
    return 0;
}
