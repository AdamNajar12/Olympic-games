#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "discipline.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include<QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    discipline d;
    ui->setupUi(this);
    ui->tableView_Discipline->setModel(tmpDiscipline.afficher());
    ui->tableViewRECH->setModel(d.chercher(ui->lineEdit_Rechercher->text()));
    ui->table_notif->setModel(tmpDiscipline.afficher());


    int ret=A.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
            break;
        }

    //QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); //permet de lancer le slot update_label suite à la récupération du signal readyRead

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_A_clicked()
{
     A.write_to_arduino("welcome ");
}

void MainWindow::on_pushButton_R_clicked()
{
     A.write_to_arduino("refuser ");
}


void MainWindow::on_pushButtonajouter_clicked()
{
    int id=ui->lineEditIddiscipline->text().toInt();
    QString nom=ui->lineEditNomdiscipline->text();
    QString type=ui->lineEditTypediscipline->text();


    discipline d(id, nom, type);
    bool test= d.ajouter();
if(d.select()){A.write_to_arduino("5");}

    if(test)
    {
        ui->tableView_Discipline->setModel(tmpDiscipline.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter discipline"),
                                 QObject::tr("Discipline ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr(" Ajout discipline"),
                    QObject::tr("Ajout echoué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_clicked()
{
    int id = ui->lineEditsupprimer->text().toInt();
    bool test=tmpDiscipline.supprimer(id);
    if(test)
    {
        ui->tableView_Discipline->setModel(tmpDiscipline.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer discipline"),
                                 QObject::tr("Discipline supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr(" Supprimer discipline"),
                    QObject::tr("Supression echouée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_pushButtonmodifier_clicked()
{

discipline k(ui->lineEditmodifer->text().toInt(),ui->linee_nom->text(),ui->linee_type->text());
  bool test=k.modifier(ui->lineEditmodifer->text().toInt());

  if(test)
  {
      ui->tableView_Discipline->setModel(tmpDiscipline.afficher());//refresh
      QMessageBox::information(nullptr, QObject::tr("Modifier discipline"),
                               QObject::tr("Discipline modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr(" Modifier discipline"),
                  QObject::tr("Modification echouée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



}


void MainWindow::on_afficher_c_clicked()
{
    discipline d;
    ui->table_calendrier->setModel(d.afficher_calendrier());
}



void MainWindow::on_pushButton_Rechercher_clicked()
{

    ui->tableViewRECH->setModel(tmpDiscipline.afficher());
    QString str=ui->lineEdit_Rechercher->text();
    ui->tableViewRECH->setModel(tmpDiscipline.chercher(str));
}

void MainWindow::on_pushButton_his_clicked()
{
    QString nom=ui->lineEdit_his->text();
   // histoire h(football,basktball,volleyball)
    QString football,basketball,volleyball;

    if(nom=="football")
    {
        ui->tableView_his->setModel(tmpDiscipline.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Histoire du discipline"),
                                 QObject::tr("Le Football est un sport collectif qui se joue avec un ballon sphérique entre deux équipes de onze joueurs. Le début de ce jeu était en Angleterre en 1873 pour se répandre et conquérir le monde et devenir le sport le plus populaire .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}

      if(nom=="basketball")
        {
            ui->tableView_his->setModel(tmpDiscipline.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Histoire du discipline"),
                                     QObject::tr("Le basketball, aussi appelé basket, a été inventé en décembre 1891 par le Canadien James W. Naismith. Instructeur du YMCA Training School dans le Massachusetts, il cherchait un jeu d'intérieur adapté afin que ses élèves restent en forme et au chaud pendant les hivers rigoureux de la Nouvelle-Angleterre. .\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}

            if(nom=="volleyball")
            {
                ui->tableView_his->setModel(tmpDiscipline.afficher());//refresh
                QMessageBox::information(nullptr, QObject::tr("Histoire du discipline"),
                                         QObject::tr("Le volley-ball est un sport collectif opposant deux équipes de six joueurs séparés par un filet, qui s'affrontent avec un ballon sur un terrain rectangulaire de 18 mètres de long sur 9 mètres de large. Avec 600 millions de pratiquants en 2007, il s'agit d'un des sports les plus pratiqués dans le monde .\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr(" Histoire du discipline"),
                    QObject::tr("Discipline introuvable.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_EnvoyerReclamation_clicked()
{

    QString Reclamation=ui->textEdit_reclamation->toPlainText() ;


          discipline d;

                if( d.reclamer(Reclamation))
               {
                    QMessageBox::information(nullptr, QObject::tr("ok"),
                                                                     QObject::tr("Reclamation Envoyée .  .\n" "Click Cancel to exit."), QMessageBox::Cancel);


                ui->textEdit_reclamation->setText("")  ;

              } else  QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                                  QObject::tr("CHAMP VIDE .\n" "Click Cancel to exit."), QMessageBox::Cancel);


}







/*
void Gestion::on_pushButton_EnvoyerReclamation_clicked()
{

    QSqlQuery query ;
    QString Reclamation=ui->textEdit_reclamation->toPlainText() ;
     QString ID_C=ui->lineEdit_ID_C->text() ;
    query.prepare("Select ID_C from Disciplines WHERE ID_C=:ID_C ");
    query.bindValue(":ID_C",ID_C) ;
    query.exec() ;

        bool alreadyExist = false ;
            alreadyExist = query.next();
            if(alreadyExist)
            {

                if(Reclamation.size()>0)
               {
                QMessageBox msgbox ;
                msgbox.setText("Reclamation Envoyée . \n") ;
                msgbox.exec() ;
                ui->textEdit_reclamation->setText("")  ;
                ui->lineEdit_ID_C->setText("") ;
               }
                else  QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                                  QObject::tr("CHAMP VIDE .\n" "Click Cancel to exit."), QMessageBox::Cancel);


            }
          else
                         {

                           ui->textEdit_reclamation->setText("")  ;
                           ui->lineEdit_ID_C->setText("") ;
                           QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                                  QObject::tr("CENTRE INTROUVABLE .\n" "Click Cancel to exit."), QMessageBox::Cancel);
                         }





}


void MainWindow::on_lineEdit_Rechercher_cursorPositionChanged(int arg1, int arg2)
{
    discipline d;
        ui->tableViewRECH->setModel(d.chercher(ui->lineEdit_Rechercher->text()));
}
*/

