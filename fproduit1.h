#ifndef FPRODUIT1_H
#define FPRODUIT1_H

#include <QDialog>

namespace Ui {
class FProduit1;
}

class FProduit1 : public QDialog
{
    Q_OBJECT

public:
    explicit FProduit1(QWidget *parent = nullptr);
    void afficherProduit(const QString& nom, float prix, const QString& cheminImage, const QString& quantite, const QString& specialite);
    ~FProduit1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FProduit1 *ui;
};

#endif // FPRODUIT1_H
