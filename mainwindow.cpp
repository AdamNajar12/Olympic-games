#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QComboBox>
#include "joueurs.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
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

void MainWindow::on_pushButton_2_clicked()
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

void MainWindow::on_pushButton_3_clicked()
{
    QString nom=ui->lenomjoueur->text();
    QString prenom=ui->leprenomjoueur->text();
    int id=ui->comboBox_6->currentText().toInt();


       JOUEURS j(nom,prenom,id);
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

void MainWindow::on_pushButton_4_clicked()
{
     ui->tableViewjoueur->setModel(j.afficher_joueur());
}

void MainWindow::on_supprimer_2_clicked()
{
   int id=ui->comboBox_3->currentText().toInt();


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

void MainWindow::on_pushButton_5_clicked()
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

void MainWindow::on_pushButton_9_clicked()
{int dis=ui->comboBox_7->currentText().toInt();

     ui->tableView_3->setModel(j.afficher_joueur_equipe(dis));
}

void MainWindow::on_pushButton_10_clicked()
{
     ui->tableView_4->setModel(e.afficher_historiques_equipe());
}

void MainWindow::on_pushButton_13_clicked()
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

void MainWindow::on_pushButton_12_clicked()
{ QString dis=ui->comboBox_8->currentText();
    QString nom=ui->listedenom->currentText();
   QString score=ui->lineediterecords->text();
     ui->tableView_6->setModel(e.afficher_records());
}

void MainWindow::on_pushButton_11_clicked()
{
     ui->tableView_5->setModel(e.afficher_historiques());
}
