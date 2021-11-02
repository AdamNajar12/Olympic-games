#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "joueurs.h"
#include <QMessageBox>
#include <QApplication>
#include <iostream>
#include <equipes.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   //ui->comboBox->addItem("bilel");
    ui->tabjoueurs->setModel(j.afficher());
ui->tabviewequipes->setModel(e.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_PB_ajouter_clicked()
{

    QString prenom=ui->LE_prenom->text();
    QString nom=ui->LE_nom->text();
    QString ids=ui->LE_id->text();

    int id =ui->LE_id->text().toInt();//toint permet de convertir lid entier;
    if (prenom!="" & nom!="" & ids!="")
    {
    joueurs j(prenom,nom,id);
    bool test=j.ajouter();
        if(test)
    {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("Ajout effectue\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);




    }
        else
            QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                        QObject::tr("Ajout non effectue.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }

else {
QMessageBox::critical(nullptr, QObject::tr("Chaine non vide"),
                QObject::tr("Nom ou Prenom ou id est vide.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);

}

}

void MainWindow::on_SUPPRIMERPB_clicked()
{
    int id=ui->idsuppresionle->text().toInt();
    bool test=j.supprimer(id);
    if(test)
{
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("suppression effectue\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("suppression non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_clicked()
{
    joueurs j;
      ui->tabjoueurs->setModel(j.afficher());
}




void MainWindow::on_ajouterequipes_clicked()
{
    QString categorie=ui->lecategorie->text();
    QString nom=ui->lenom->text();
    QString nb=ui->lenombrejoueurs->text();
     QString id=ui->leidequipes->text();

    int nbs =ui->lenombrejoueurs->text().toInt();//toint permet de convertir lid entier;
     int ids =ui->leidequipes->text().toInt();
    if (categorie!="" & nom!="" & nb!=""& id!="")
    {
   equipes e(categorie,nom,nbs,ids);
    bool test=e.ajouter();
        if(test)
    {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("Ajout effectue\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);




    }
        else
            QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                        QObject::tr("Ajout non effectue.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }

else {
QMessageBox::critical(nullptr, QObject::tr("Chaine non vide"),
                QObject::tr("Nom ou Prenom ou id est vide.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);

}

}


void MainWindow::on_pbsupprimerequipes_clicked()
{
    int id=ui->lineeditsupp->text().toInt();
    bool test=e.supprimer(id);
    if(test)
{
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("suppression effectue\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("suppression non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pbafficherequipes_clicked()
{
    equipes e;
    ui->tabviewequipes->setModel(e.afficher());

}
