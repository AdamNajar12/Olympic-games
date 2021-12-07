#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "discipline.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include<QSqlError>
#include <QSqlQueryModel>
#include <QComboBox>
#include "joueurs.h"
#include"pays.h"
#include"lieux.h"
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include<QFileInfo>
#include<QFileDialog>
#include <QTextEdit>
#include <QTextStream>

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




///////////////////////////Image_PAYS//////////////////////////////////
        ui->comboBox_10->addItem(QIcon(":/rec/Nouveau dossier/Algerie.png"),"Algerie");
        ui->comboBox_10->addItem(QIcon(":/rec/Nouveau dossier/australia"),"Australia");
        ui->comboBox_10->addItem(QIcon(":/rec/Nouveau dossier/BelgiQue"),"Belqigue");
        ui->comboBox_10->addItem(QIcon(":/rec/Nouveau dossier/Brazil"),"Brazil");
        ui->comboBox_10->addItem(QIcon(":/rec/Nouveau dossier/Canada"),"Canada");
        ui->comboBox_10->addItem(QIcon(":/rec/Nouveau dossier/chine"),"Chine");
        ui->comboBox_10->addItem(QIcon(":/rec/Nouveau dossier/Croitia"),"Croitia");
        ui->comboBox_10->addItem(QIcon(":/rec/Nouveau dossier/Danemark"),"Danemark");
        ui->comboBox_10->addItem(QIcon(":/rec/Nouveau dossier/egypte"),"Egypte");
        ui->comboBox_10->addItem(QIcon(":/rec/Nouveau dossier/france"),"France");
        ui->comboBox_10->addItem(QIcon(":/rec/Nouveau dossier/germany"),"Allemagne");
        ui->comboBox_10->addItem(QIcon(":/rec/Nouveau dossier/Italie"),"Italie");
        ui->comboBox_10->addItem(QIcon(":/rec/Nouveau dossier/pays-bas"),"Pays bas");
        ui->comboBox_10->addItem(QIcon(":/rec/Nouveau dossier/portugal"),"Portugal");
        ui->comboBox_10->addItem(QIcon(":/rec/Nouveau dossier/Spain"),"Spain");
        ui->comboBox_10->addItem(QIcon(":/rec/Nouveau dossier/suede"),"Suede");
        ui->comboBox_10->addItem(QIcon(":/rec/Nouveau dossier/tunisie"),"Tunis");
        ui->comboBox_10->addItem(QIcon(":/rec/Nouveau dossier/USA"),"USA");


//QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); //permet de lancer le slot update_label suite à la récupération du signal readyRead
        QSqlQueryModel *model=new QSqlQueryModel();
            QSqlQueryModel *modell=new QSqlQueryModel();
            QSqlQueryModel *modelll=new QSqlQueryModel();
            QSqlQueryModel *modellll=new QSqlQueryModel();
             QSqlQueryModel *mode=new QSqlQueryModel();
              QSqlQueryModel *mo=new QSqlQueryModel();

            QSqlQuery query,q,i,v,r,f;
            query.prepare("SELECT NOM_DISCIPLINE FROM DISCIPLINES");
            r.prepare("SELECT NOM_DISCIPLINE FROM DISCIPLINES");
        f.prepare("SELECT nom FROM equipe");
            q.prepare("SELECT id_joueur FROM joueur");
           i.prepare("SELECT id_equipe FROM equipe");

           v.prepare("SELECT id_equipe FROM equipe");


            query.exec();
             q.exec();
             i.exec();
             v.exec();
             r.exec();
             f.exec();
        mo->setQuery(f);
            model->setQuery(query);
             modell->setQuery(q);
              modelll->setQuery(i);
              modellll->setQuery(v);
               mode->setQuery(r);


            ui->comboBox->setModel(model);
            ui->comboBox_4->setModel(modell);
             ui->comboBox_5->setModel(modelll);
              ui->comboBox_6->setModel(modellll);
                  ui->comboBox_7->setModel(modellll);
                  ui->comboBox_8->setModel(mode);
                  ui->listedenom->setModel(mo);



            ui->comboBox_2->addItems(e.sup_id());
            ui->comboBox_3->addItems(j.sup_id());

            ui->comboBox_16->addItem("service");
            ui->comboBox_16->addItem("conflit");
            ui->comboBox_16->addItem("pandemie");
            ui->comboBox_16->addItem("dopage elevé");

            ui->comboBox_14->addItem("service");
            ui->comboBox_14->addItem("a propos du jeu");
            ui->comboBox_14->addItem("imigration interdite");
            ui->comboBox_14->addItem("a propos medailles");

            QSqlQuery query7;
                QSqlQueryModel* model2= new QSqlQueryModel();

               query7.prepare("SELECT ID_PAYS FROM PAYS  ");
                     query7.exec();
                      model2->setQuery(query7);

          ui->comboBox_11->setModel(model2);
            ui->comboBox_12->setModel(model2);
            ui->comboBox_13->setModel(model2);

            QSqlQuery qe;
            QSqlQueryModel* model4= new QSqlQueryModel();
            qe.prepare("SELECT NOM_PAYS FROM PAYS  ");

            qe.exec();
                  model4->setQuery(qe);
                  ui->comboBox_15->setModel(model4);


 ui->tabWidget_lieux->setCurrentIndex(0);









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
bool test2=d.select();
if(test2)
{A.write_to_arduino("5");}
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

//////////////////EQUIPE ET JOUEURS////////////////////////////////////////////////////
void MainWindow::on_pushButton_2_clicked()
{
QString dis=ui->comboBox->currentText();
QString nom=ui->lenom->text();
int nb=ui->lenb->text().toInt();
int score=ui->lescore->text().toInt();
      equipe e(dis,nom,nb,score);
 bool test=e.ajouter_equipe();


if(test)
{
      QMessageBox::information(nullptr, QObject::tr("OK"),
                  QObject::tr("Ajout effectue\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


    ui->comboBox_2->addItems(e.sup_id());

}
else
{QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                          QObject::tr("Ajout non effectue\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

}
 }

void MainWindow::on_pushButton_3_clicked()
{

   ui->tabafficher->setModel(e.afficher());
}

void MainWindow::on_supprimer_clicked()
{
    int id=ui->comboBox_2->currentText().toInt();


     bool test=e.supprimer(id);

    if(test)
    {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("Suppression effectue\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    ui->comboBox_2->addItems(e.sup_id());


    }
        else
            QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                        QObject::tr("Suppression non effectue.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
ui->lenomdisp->setText(arg1);
}

void MainWindow::on_pushButton_4_clicked()
{
    QString nom=ui->lenomjoueur->text();
    QString prenom=ui->leprenomjoueur->text();
    int id=ui->comboBox_6->currentText().toInt();
int b=ui->comboBox_9->currentText().toInt();


       JOUEURS j(nom,prenom,id,b);
    if(b!=1)
       {bool test=j.ajoute_joueur();


    if(test)
    {
          QMessageBox::information(nullptr, QObject::tr("OK"),
                      QObject::tr("Ajout effectue\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);



    }
    else
    {QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectue\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }
    }
    else
{


A.write_to_arduino("1");
A.write_to_arduino("0");
bool test=j.ajoute_joueur();


            if(test)
            {

                QMessageBox::information(nullptr, QObject::tr("OK"),
                              QObject::tr("Ajout effectue\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);



            }
            else
            {QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                      QObject::tr("Ajout non effectue\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

            }


}




}

void MainWindow::on_pushButton_5_clicked()
{
     ui->tableViewjoueur->setModel(j.afficher_joueur());
}



void MainWindow::on_supprimer_2_clicked()
{
   int id=ui->comboBox_3->currentText().toInt();

A.write_to_arduino("1");
     bool test=j.supprimer_joueur(id);

    if(test)
    {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("Suppression effectue\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
 ui->comboBox_3->addItems(j.sup_id());



    }
        else
            QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                        QObject::tr("Suppression non effectue.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_6_clicked()
{
    QString nom=ui->lenomupdated->text();
    int nb=ui->lenbupdated->text().toInt();
    QString dis=ui->comboBoxupdated->currentText();
     int score=ui->lescoreupdated->text().toInt();
          equipe e(dis,nom,nb,score);
        bool  test=e.update_equipe(ui->comboBox_5->currentText().toInt());


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

void MainWindow::on_pushButton_9_clicked()
{
    QString nom=ui->LENOMJUPDATED->text();
    QString prenom=ui->leprenomjoueurupdated->text();

    JOUEURS j(nom,prenom);
        bool  test=j.update(ui->comboBox_4->currentText().toInt());


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

void MainWindow::on_pushButton_7_clicked()
{
ui->tableView->setModel(e.classementfoot());
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->tableView_2->setModel(e.classementbasket());
}

void MainWindow::on_pushButton_10_clicked()
{int dis=ui->comboBox_7->currentText().toInt();

     ui->tableView_3->setModel(j.afficher_joueur_equipe(dis));
}

void MainWindow::on_pushButton_11_clicked()
{
     ui->tableView_4->setModel(e.afficher_historiques_equipe());
}

void MainWindow::on_pushButton_14_clicked()
{
    QString dis=ui->comboBox_8->currentText();
    QString nom=ui->listedenom->currentText();
   QString score=ui->lineediterecords->text();
    equipe e(dis,score,nom);
bool test=e.ajouter_equipe_records();


if(test)
{
    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("Ajout effectue\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);




}
else
{QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                        QObject::tr("Ajout non effectue\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}}

void MainWindow::on_pushButton_13_clicked()
{ QString dis=ui->comboBox_8->currentText();
    QString nom=ui->listedenom->currentText();
   QString score=ui->lineediterecords->text();
     ui->tableView_6->setModel(e.afficher_records());
}

void MainWindow::on_pushButton_12_clicked()
{
     ui->tableView_5->setModel(e.afficher_historiques());
}





////////////////////////////Pays////////////////////////////////////
////////////////////////////////////////////////////////
/// /////////////////////////////////////////////




void MainWindow::on_pushButton_15_clicked()
{ui->textEdit->setText("ajout d une pays");
    QString nom=ui->comboBox_10->currentText();
    QSqlQuery query;
        QSqlQueryModel* model= new QSqlQueryModel();

        query.prepare("SELECT ID_PAYS FROM PAYS  ");
              query.exec();
              model->setQuery(query);



    ui->comboBox_11->setModel(model);
    ui->comboBox_12->setModel(model);
    ui->comboBox_13->setModel(model);

////Actualisation

    QSqlQuery q;
    QSqlQueryModel* modell= new QSqlQueryModel();
    q.prepare("SELECT NOM_PAYS FROM PAYS  ");

    q.exec();
          modell->setQuery(q);
          ui->comboBox_15->setModel(modell);



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

void MainWindow::on_pushButton_16_clicked()
{

    QSqlQuery query;
               QSqlQueryModel* model= new QSqlQueryModel();

               query.prepare("SELECT ID_PAYS FROM PAYS  ");
                     query.exec();
                     model->setQuery(query);



           ui->comboBox_11->setModel(model);
           ui->comboBox_12->setModel(model);
           ui->comboBox_13->setModel(model);

           QSqlQuery q;
           QSqlQueryModel* modell= new QSqlQueryModel();
           q.prepare("SELECT NOM_PAYS FROM PAYS  ");

           q.exec();
                 modell->setQuery(q);
                 ui->comboBox_15->setModel(modell);

        Pays P;
       ui->tab_Pays->setModel(P.afficher());
}






void MainWindow::on_pushButton_17_clicked()
{
    int id=ui->comboBox_11->currentText().toInt();
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





void MainWindow::on_pushButton_18_clicked()
{
    QString nom=ui->n_pays->text();

ui->textEdit->setText("modification  d une pays");
if(nom!="")
         {     Pays p(nom);
            bool  test=p.update(ui->comboBox_12->currentText().toInt());


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

void MainWindow::on_pushButton_19_clicked()
{
    Pays P;
  ui->TAB_Classement->setModel(P.ClassementPays());
}

void MainWindow::on_pushButton_20_clicked()
{
ui->tab_r->setModel(P.classementpop());
}

void MainWindow::on_pushButton_21_clicked()
{
 ui->tab_h->setModel(P.nb_habitans());
}

void MainWindow::on_pushButton_22_clicked()
{
    ui->textEdit->setText(" une pays a declarer un forfait ");
  int id=ui->comboBox_13->currentText().toInt();
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

void MainWindow::on_pushButton_23_clicked()
{
    ui->textEdit->setText("une pays a passer une reclamation ");

    QString raison=ui->comboBox_16->currentText();
    QString nom=ui->comboBox_15->currentText();
    Pays P(nom,raison);
     bool test=P.ajouter_rec();

    if(test)
    {
    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("reclamation envoye\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);




    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                QObject::tr("error d envoi.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    }


}



////////////////////////////////////LIEUX////////////////////////////////////////////////////////
///////////////////////////////////////
////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////////////////////////////////////////





void MainWindow::on_pushButton_24_clicked()
{
    QSqlQuery query;
        int Id =ui->lineEdit->text().toInt();
        QString a =ui->lineEdit->text();
        QString Nom=ui->lineEdit_2->text();
        QString etat=ui->lineEdit_3->text();
        QString type=ui->lineEdit_4->text();
        lieux C(Id,Nom,etat,type);
        bool alreadyExist = false;
        query.prepare("select * from lieux where id_lieux=:id_lieux");
        query.bindValue(":id_lieux",Id);
        if(!query.exec())
        {
            QMessageBox::critical(nullptr, QObject::tr("ERROR"),
            QObject::tr("Failed adding.\n"
            "Click Cancel to exit."), QMessageBox::Cancel);
        }

        alreadyExist = query.next();
        if(alreadyExist){
            C.modifier(a);
        QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
        QObject::tr("UPDATED.\n"
        "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else{
                  C.ajouter();
                  QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                  QObject::tr("ADDED.\n"
                  "Click Cancel to exit."), QMessageBox::Cancel);
        }
        ui->tableView_7->setModel(C.afficher());
}

void MainWindow::on_pushButton_28_clicked()
{

    int Id =ui->lineEdit_6->text().toInt();
    lieux C;
    bool test=C.supprimer(Id);
    if(test)
    {
         ui->tableView_7->setModel(C.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("DELETED.\n click cancel to exit."),QMessageBox::Cancel);

    }
    else
       QMessageBox::critical(nullptr, QObject::tr("Not ok"),QObject::tr("ERROR.\n click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_tabWidget_lieux_tabBarClicked(int index)
{
    if(index==1)
    ui->tableView_7->setModel(L.afficher());
}



void MainWindow::on_comboBox_17_currentIndexChanged(int index)
{
    switch (index)
    {
      case 0:  ui->tableView_7->setModel(L.trier());break;
      case 1:  ui->tableView_7->setModel(L.trier1());break;
      case 2:  ui->tableView_7->setModel(L.trier2());break;
      case 3:  ui->tableView_7->setModel(L.trier3());break;

    }
}

void MainWindow::on_pushButton_27_clicked()
{
    val_lieux=ui->lineEdit_6->text();
    ui->tabWidget_lieux->setCurrentIndex(0);
    QSqlQuery qry;
    qry.prepare("SELECT * FROM lieux where id_lieux='"+val_lieux+"'");
    if(qry.exec( ))
    {
        while (qry.next())
        {
            ui->lineEdit->setText(qry.value(0).toString());
            ui->lineEdit_2->setText(qry.value(1).toString());
            ui->lineEdit_3->setText(qry.value(2).toString());
            ui->lineEdit_4->setText(qry.value(3).toString());

        }

    }
}

void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
     ui->tableView_7->setModel(L.rechercher(arg1));
}




void MainWindow::on_pushButton_26_clicked()
{
    QString strStream;
       QTextStream out(&strStream);

       const int rowCount = ui->tableView_7->model()->rowCount();
       const int columnCount = ui->tableView_7->model()->columnCount(); // Collones de tableaux

       out <<  "<html>\n"
           "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
           <<  QString("<title>%1</title>\n").arg("strTitle")
           <<  "</head>\n"
           "<body bgcolor=#ffffff link=#5000A0>\n"

           //     "<align='right'> " << datefich << "</align>"
           "<center> <H1>Liste Des Lieux </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n\n\n";

       // headers
       out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
       for (int column = 0; column < columnCount; column++)
           if (!ui->tableView_7->isColumnHidden(column))
               out << QString("<th>%1</th>").arg(ui->tableView_7->model()->headerData(column, Qt::Horizontal).toString());
       out << "</tr></thead>\n";

       // data table
       for (int row = 0; row < rowCount; row++)
       {
           out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
           for (int column = 0; column < columnCount; column++)
           {
               if (!ui->tableView_7->isColumnHidden(column))
               {
                   QString data = ui->tableView_7->model()->data(ui->tableView_7->model()->index(row, column)).toString().simplified();
                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
               }
           }
           out << "</tr>\n";
       }
       out <<  "</table> </center>\n"
           "</body>\n"
           "</html>\n";

       QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
       if (QFileInfo(fileName).suffix().isEmpty())
       {
           fileName.append(".pdf");
       }

       QPrinter printer (QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        doc.setHtml(strStream);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}

void MainWindow::on_pushButton_25_clicked()
{
    QPrinter printer;
        printer.setPrinterName("Imprimante");
        QPrintDialog dialog(&printer, this);
        if (dialog.exec() == QDialog::Rejected) return;
        ui->tableView_7->render(&printer);
}
