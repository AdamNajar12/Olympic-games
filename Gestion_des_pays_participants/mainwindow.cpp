#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "pays.h"
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<qmessagebox.h>
#include<iostream>
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->comboBox->addItem(QIcon(":/rec/Nouveau dossier/Algerie.png"),"Algerie");
ui->comboBox->addItem(QIcon(":/rec/Nouveau dossier/australia"),"Australia");
ui->comboBox->addItem(QIcon(":/rec/Nouveau dossier/BelgiQue"),"Belqigue");
ui->comboBox->addItem(QIcon(":/rec/Nouveau dossier/Brazil"),"Brazil");
ui->comboBox->addItem(QIcon(":/rec/Nouveau dossier/Canada"),"Canada");
ui->comboBox->addItem(QIcon(":/rec/Nouveau dossier/chine"),"Chine");
ui->comboBox->addItem(QIcon(":/rec/Nouveau dossier/Croitia"),"Croitia");
ui->comboBox->addItem(QIcon(":/rec/Nouveau dossier/Danemark"),"Danemark");
ui->comboBox->addItem(QIcon(":/rec/Nouveau dossier/egypte"),"Egypte");
ui->comboBox->addItem(QIcon(":/rec/Nouveau dossier/france"),"France");
ui->comboBox->addItem(QIcon(":/rec/Nouveau dossier/germany"),"Allemagne");
ui->comboBox->addItem(QIcon(":/rec/Nouveau dossier/Italie"),"Italie");
ui->comboBox->addItem(QIcon(":/rec/Nouveau dossier/pays-bas"),"Pays bas");
ui->comboBox->addItem(QIcon(":/rec/Nouveau dossier/portugal"),"Portugal");
ui->comboBox->addItem(QIcon(":/rec/Nouveau dossier/Spain"),"Spain");
ui->comboBox->addItem(QIcon(":/rec/Nouveau dossier/suede"),"Suede");
ui->comboBox->addItem(QIcon(":/rec/Nouveau dossier/tunisie"),"Tunis");
ui->comboBox->addItem(QIcon(":/rec/Nouveau dossier/USA"),"USA");
ui->comboBox_5->addItem("service");
ui->comboBox_5->addItem("conflit");
ui->comboBox_5->addItem("pandemie");
ui->comboBox_5->addItem("dopage elevé");

ui->comboBox_7->addItem("service");
ui->comboBox_7->addItem("a propos du jeu");
ui->comboBox_7->addItem("imigration interdite");
ui->comboBox_7->addItem("a propos medailles");






QSqlQuery query;
    QSqlQueryModel* model= new QSqlQueryModel();

    query.prepare("SELECT ID_PAYS FROM PAYS  ");
          query.exec();
          model->setQuery(query);




ui->comboBox_2->setModel(model);
ui->comboBox_3->setModel(model);
ui->comboBox_4->setModel(model);
QSqlQuery q;
QSqlQueryModel* modell= new QSqlQueryModel();
q.prepare("SELECT NOM_PAYS FROM PAYS  ");

q.exec();
      modell->setQuery(q);
      ui->comboBox_6->setModel(modell);






}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
ui->textEdit->setText("ajout d une pays");
    QString nom=ui->comboBox->currentText();
    QSqlQuery query;
        QSqlQueryModel* model= new QSqlQueryModel();

        query.prepare("SELECT ID_PAYS FROM PAYS  ");
              query.exec();
              model->setQuery(query);



    ui->comboBox_2->setModel(model);
    ui->comboBox_3->setModel(model);
    ui->comboBox_4->setModel(model);

////Actualisation

    QSqlQuery q;
    QSqlQueryModel* modell= new QSqlQueryModel();
    q.prepare("SELECT NOM_PAYS FROM PAYS  ");

    q.exec();
          modell->setQuery(q);
          ui->comboBox_6->setModel(modell);



    Pays P(nom);
   bool test=P.ajouter();

 if(test)
{
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout effectue\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}
    else
        { QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("Ajout non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}







}





void MainWindow::on_pb_supprimer_clicked()
{

int id=ui->comboBox_2->currentText().toInt();
 bool test=P.Supprimer(id);

if(test)
{
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Suppression effectue\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


ui->textEdit->setText("suppression  d une pays");

}
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("Suppression non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}




void MainWindow::on_pushButton_clicked()///afficher
{
    QSqlQuery query;
        QSqlQueryModel* model= new QSqlQueryModel();

        query.prepare("SELECT ID_PAYS FROM PAYS  ");
              query.exec();
              model->setQuery(query);



    ui->comboBox_2->setModel(model);
    ui->comboBox_3->setModel(model);
    ui->comboBox_4->setModel(model);

    QSqlQuery q;
    QSqlQueryModel* modell= new QSqlQueryModel();
    q.prepare("SELECT NOM_PAYS FROM PAYS  ");

    q.exec();
          modell->setQuery(q);
          ui->comboBox_6->setModel(modell);

 Pays P;
ui->tab_Pays->setModel(P.afficher());
}






void MainWindow::on_pb_modifier_clicked()
{
    QString nom=ui->n_pays->text();

ui->textEdit->setText("modification  d une pays");
if(nom!="")
         {     Pays p(nom);
            bool  test=p.update(ui->comboBox_3->currentText().toInt());


              if(test)
              {
                      QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("update effectue\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);




              }
                  else
                      QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                  QObject::tr("update non effectue.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                QObject::tr("update non effectue.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_2_clicked()
{
    Pays P;
ui->TAB_Classement->setModel(P.ClassementPays());

}




void MainWindow::on_pushButton_4_clicked()
{
    ui->tab_h->setModel(P.nb_habitans());
}


void MainWindow::on_pushButton_3_clicked()
{
ui->tab_r->setModel(P.classementpop());
}



void MainWindow::on_pb_declarer_clicked()
{

    ui->textEdit->setText(" une pays a declarer un forfait ");
int id=ui->comboBox_4->currentText().toInt();
QString forfait="forfait";
Pays P(forfait);
bool test=P.declarer_forfait(id);

if(test)
{
       QMessageBox::information(nullptr, QObject::tr("OK"),
                   QObject::tr("Declaration effectue\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);




}
   else
       QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                   QObject::tr("Declaration non effectue.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);




}







void MainWindow::on_pushButton_5_clicked()
{
ui->textEdit->setText("une pays a passer une reclamation ");

QString raison=ui->comboBox_7->currentText();
QString nom=ui->comboBox_6->currentText();
Pays P(nom,raison);
 bool test=P.ajouter_rec();

if(test)
{
QMessageBox::information(nullptr, QObject::tr("OK"),
            QObject::tr("Ajout effectue\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);




}
else
{ QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
            QObject::tr("Ajout non effectue.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);

}

}














