#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "produit.h"
#include "MachineDistributrice.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void afficherTousLesProduits();
    void setProduits(const QVector<Produit*>& liste) {
        this->produits = liste;
    }
    void ouvrirProduit(int index, machineDistributrice& machine);
    void setMachine(const machineDistributrice& machine);
    std::string _choix;

private slots:

    void on_Bouton_01_pressed();

    void on_Bouton_02_pressed();

    void on_Bouton_03_pressed();

    void on_Bouton_04_pressed();

    void on_Bouton_05_pressed();

    void on_Bouton_06_pressed();

    void on_Bouton_Validation_2_pressed();

    void on_Bouton_Annulation_2_pressed();

private:
    machineDistributrice machine;
    QVector<Produit*> produits;

    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
