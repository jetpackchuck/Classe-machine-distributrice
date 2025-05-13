#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
class Produit
{
protected:
    float _prixVente;
    float _prixAchat;
    int _nbVentes;
    std::string _lienImage;
    std::string _nom;
    std::string _type;
public:

    Produit();


    float getPrixVente()const;
    float getPrixAchat()const;
    float getNbVentes()const;
    std::string getNom()const;
    std::string getLien()const;
    std::string getType()const;


    void setPrixVente(float prixV);
    void setPrixAchat(float prixA);
    void setNbVentes(float nb);
    void setNom(std::string nom);
    void setLien(std::string lien);
    void setType(std::string type);


};

#endif // PRODUIT_H
