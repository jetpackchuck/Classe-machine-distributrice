#include <iostream>
#include <vector>
#include <fstream>
#include "MachineDistributrice.h"
#include <QDebug>

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
	ligne2.push_back(Cases(22, p7, 10));
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


    this->_cases.resize(7);

    this->_cases[1] = ligne1;
    this->_cases[2] = ligne2;
    this->_cases[3] = ligne3;
    this->_cases[4] = ligne4;
    this->_cases[5] = ligne5;
    this->_cases[6] = ligne6;


	this->_motDePasse = "1234";
}

void machineDistributrice::addVente(Produit* produit)
{
	this->_logVentes.push_back(produit);
}
void machineDistributrice::vente( int id)
{
    int firstNum = id / 10;
    int secondNum = (id % 10)-1;



    if (_cases[firstNum][secondNum]._produits.empty()) {

        return;
    }
    this->addVente(this->getProduit(id));
    _cases[firstNum][secondNum]._produits.pop();



    ofstream profit("Profit.txt",std::ios::app);
    if (profit.is_open())
    {
        profit << ";";
        profit << this->getProduit(id)->getPrixVente()-this->getProduit(id)->getPrixAchat();
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
    int firstNum = id / 10;
    int secondNum = (id % 10)-1;
    return _cases[firstNum][secondNum]._produits.size();
}

string machineDistributrice::getMotDePasse()
{
    return _motDePasse;
}

void machineDistributrice::setMotDePasse(std::string newPW)
{
    this->_motDePasse = newPW;
}

Cases& machineDistributrice::getCase(int id)
{
    for (auto& ligne : _cases) {
        for (auto& c : ligne) {
            if (c._id == id) {
                return c;
            }
        }
    }
}

std::list<Produit *> &machineDistributrice::getLogVentes()
{
    return _logVentes;
}












