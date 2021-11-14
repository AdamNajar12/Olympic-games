#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_matricule->setValidator( new QIntValidator(0, 9999999, this) );
    ui->le_matricule_modif->setValidator( new QIntValidator(0, 9999999, this) );
    ui->le_nom->setValidator( new QIntValidator(0, 9999999, this) );
    ui->le_nom_modif->setValidator( new QIntValidator(0, 9999999, this) );
    ui->tab_matchs->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_ajouter_clicked()
{


    int nom = ui->le_nom->text().toInt();
    QString prenom = ui->le_prenom->text();
    QString daten_string = ui->la_daten->text();

    QDate daten = QDate::fromString(daten_string, "yyyyMMdd");

    Match E(Match::get_id_match(), nom, prenom, daten);
    E.set_id_match(E.get_id_match()+1);

    bool test = E.ajouter();

    if( test )
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué.\n"
                                             "Click cancel to exit."),
                                 QMessageBox::Cancel);
        ui->tab_matchs->setModel(E.afficher());
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Ajout non effectué.\n"
                                             "Click cancel to exit."),
                                 QMessageBox::Cancel);
    }
}

void MainWindow::on_btn_supprimer_clicked()
{


    int matricule = ui->le_matricule_sup->text().toInt();



    bool test = E.supprimer(matricule);

    if( test )
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("suppression avec succes.\n"
                                             "Click cancel to exit."),
                                 QMessageBox::Cancel);
        ui->tab_matchs->setModel(E.afficher());
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Echec de la suppression.\n"
                                             "Click cancel to exit."),
                                 QMessageBox::Cancel);
    }
}

void MainWindow::on_btn_modifier_clicked()
{
    int ancien_matricule = ui->le_matricule_ancien_modif->text().toInt();
    int matricule = ui->le_matricule_modif->text().toInt();
    int nom = ui->le_nom_modif->text().toInt();
    QString prenom = ui->le_prenom_modif->text();
    QString daten_string = ui->la_daten_modif->text();

    QDate daten = QDate::fromString(daten_string, "yyyy-MM-dd");

    bool test = E.modifier(ancien_matricule, matricule, nom, prenom, daten);

    if( test )
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("modification avec succes.\n"
                                             "Click cancel to exit."),
                                 QMessageBox::Cancel);
        ui->tab_matchs->setModel(E.afficher());
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Echec de la modification\n"
                                             "Click cancel to exit."),
                                  QMessageBox::Cancel);
    }
}
