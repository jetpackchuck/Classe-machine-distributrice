#include "admin.h"
#include "ui_admin.h"
#include <QLabel>
#include <QPushButton>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QDialog>


Admin::Admin(machineDistributrice* machine, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Admin)
    ,m_machine(machine)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_changePW_pressed()
{
    m_machine->setMotDePasse(ui->newPW->text().toStdString());
}


void Admin::on_refill_pressed()
{
    if (ui->id->text().size() != 2 or ui->id->text().toInt() % 10 > 5)
    {
        ui->reponse->setText("id invalide");
    }
    else if(ui->Quantite->text().toInt() > 10 - m_machine->getCase(ui->id->text().toInt())._produits.size() or ui->Quantite->text().toInt() <= 0)
    {
        ui->reponse->setText("Quantité invalide");
    }
    else
    {
        m_machine->getCase(ui->id->text().toInt()).refill(ui->Quantite->text().toInt());
    }
}


void Admin::on_voirStats_clicked()
{
    std::map<std::string, int> ventesParProduit;

    for (Produit* p : m_machine->getLogVentes()) {
        if (p) {
            ventesParProduit[p->getNom()]++;
        }
    }

    QBarSet *set = new QBarSet("Ventes");
    QStringList categories;

    for (const auto& [nom, quantite] : ventesParProduit) {
        *set << quantite;
        categories << QString::fromStdString(nom);
    }

    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Quantité vendue par produit");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Statistiques des ventes");
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    dialog->resize(900, 600);
    dialog->exec();
}

