#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lieux.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    QSqlQuery query;
    int Id =ui->lineEdit->text().toInt();
    QString Nom=ui->lineEdit_2->text();
    QString Prenom=ui->lineEdit_3->text();
    lieux C(Id,Nom,Prenom);
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
    QString a; a.setNum(Id);
    C.modifier(a);
    QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
    QObject::tr("UPDATED.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
              C.ajouter();
    }
    ui->tableView->setModel(C.afficher());
}

void MainWindow::on_pushButton_clicked()
{
    int Id =ui->lineEdit->text().toInt();
    lieux C;
    bool test=C.supprimer(Id);
    if(test)
    {
         ui->tableView->setModel(C.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("Ajout effectué.\n click cancel to exit."),QMessageBox::Cancel);

    }
    else
       QMessageBox::critical(nullptr, QObject::tr("Not ok"),QObject::tr("Ajout non effectué.\n click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_3_clicked()
{
    val_lieux=ui->lineEdit_4->text();
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
        }

    }
}
