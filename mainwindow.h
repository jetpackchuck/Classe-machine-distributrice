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

private slots:


private:
    machineDistributrice machine;
    QVector<Produit*> produits;

    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
