#include "discipline.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include "arduino.h"
//#include<iostream>
//using namespace std;

discipline::discipline()
{
    this->id=0;
    this->nom="";
    this->type="";
}

discipline::discipline(int id, QString nom,QString type)
{
    this->id=id;
    this->nom=nom;
    this->type=type;
}


bool discipline::ajouter()
{
    QSqlQuery query;//query2;
    QString ids = QString::number(id);
    query.prepare("INSERT INTO disciplines (ID_DISCIPLINE,NOM_DISCIPLINE,TYPE) VALUES (:id, :nom, :type )");
    query.bindValue(":id", ids);
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
query.next();
   /* query2.prepare("SELECT COUNT(ID_DISCIPLINE) FROM disciplines");


  query2.exec();

    query.next();
    int nbrDisciplines = query.value(0).toInt();
//cout<<nbrDisciplines;
    arduino A;
if(nbrDisciplines>3){
A.write_to_arduino("5");
}*/
    return query.exec();
}

QSqlQueryModel *discipline::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT ID_DISCIPLINE,NOM_DISCIPLINE,TYPE FROM disciplines");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));

    return model;
}

bool discipline::supprimer(int id)
{
    QSqlQuery query;
   QString ids = QString::number(id);
    query.prepare("Delete from disciplines where ID_DISCIPLINE = :id");
    query.bindValue(":id",ids);
    return query.exec();
}






bool discipline::modifier(int id)
{
    QSqlQuery query;
   QString ids = QString::number(id);
    query.prepare("UPDATE disciplines SET  NOM_DISCIPLINE=:nom, TYPE=:type where ID_DISCIPLINE=:id");
    query.bindValue(":id", ids);
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);



    return    query.exec();

}

QSqlQueryModel * discipline::chercher(const QString &nom)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM DISCIPLINES WHERE NOM_DISCIPLINE  LIKE'%"+nom+"%' or TYPE  LIKE'%"+nom+"%' or ID_DISCIPLINE  LIKE'%"+nom+"%'  ");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));


        return model;

}

bool discipline::reclamer(QString rec)
{
    QSqlQuery query;
   query.prepare("INSERT into reclamation(REC) values(:rec);");
   query.bindValue(":rec",rec);
   return query.exec();

}


QSqlQueryModel* discipline::afficher_calendrier()
{
    QSqlQuery query;
    QSqlQueryModel* model= new QSqlQueryModel();
    query.prepare("SELECT * FROM CALENDRIER ");
    query.exec();
    model->setQuery(query);
    return model;
}


bool discipline::select()
{
 QSqlQuery q;
 int rows = 0;


     QString execute = "SELECT COUNT(*) FROM DISCIPLINES ";
     q.prepare(execute);
     q.exec();
arduino A;
    while(q.next())
     {
         rows= q.value(0).toInt();}
      if(rows>3)
       {  A.write_to_arduino("5");
          return true;
      }
   return false;
}




















/*
QSqlQueryModel * discipline::recherche_id(int id)
   {
   QSqlQuery q;
   q.prepare("select * from discipline where ID_DISCIPLINE = :id");
   q.bindValue(":ID_DISCIPLINE", id);
   q.exec();
   QSqlQueryModel * model = new QSqlQueryModel;
   model->setQuery(q);
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
   QSqlRecord rec = model->record(0);
   int idr = rec.value("ID_DISCIPLINE").toInt();
   if( idr == id){
       return model;
     }
   return nullptr;
   }

QSqlQueryModel * discipline::recherche_nom(QString nom)
{
QSqlQuery q;
q.prepare("select * from discipline where NOM_DISCIPLINE=:nom");
q.bindValue(":NOM_DISCIPLINE", nom);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
QSqlRecord rec = model->record(0);
QString :nom = rec.value("NOM_DISCIPLINE").toString();
if( nom == nom){
    return model;
  }
return nullptr;
}

QSqlQueryModel * discipline::recherche_type(QString type)
{
QSqlQuery q;
q.prepare("select * from discipline where TYPE=:type");
q.bindValue(":TYPE", type);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
QSqlRecord rec = model->record(0);
QString :type = rec.value("TYPE").toString();
if( type == type){
    return model;
  }
return nullptr;
}
*/
