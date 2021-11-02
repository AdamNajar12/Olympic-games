#include "joueurs.h"
#include<QSqlQuery>
#include <QtDebug>
#include <QObject>
joueurs::joueurs()
{
prenom="";
nom="";
ID=0;
}
joueurs::joueurs(QString a,QString b,int c)
{
   prenom=a;
   nom=b;
   ID=c;
}

QString joueurs::get_prenom()
{
    return prenom;
}
QString joueurs::get_nom()
{
    return nom;
}
int joueurs::get_id()
{
    return ID;

}
void joueurs::set_prenom(QString prenom)
{
    this->prenom=prenom;
}
void joueurs::set_nom(QString nom)
{
 this->nom=nom;

}
void joueurs::set_id(int id)
{
    this->ID=id;
}
bool joueurs::ajouter()
{

    QSqlQuery query;
    QString test= QString::number(ID);
          query.prepare("INSERT INTO joueurs (id, prenom, nom) "
                        "VALUES (:id, :prenom, :nom)");
          query.bindValue(":id",test);
          query.bindValue(":prenom",prenom);
          query.bindValue(":nom",nom);


          return query.exec();//EXECUTER LA REQUETTE

}

 QSqlQueryModel* joueurs::afficher()
 {
     QSqlQuery query ;
     QSqlQueryModel *model=new QSqlQueryModel();
query.prepare("SELECT * FROM joueurs");
query.exec();
model->setQuery(query);

     return model;

 }
bool joueurs::supprimer(int id)
{
    QSqlQuery query;
   query.prepare("Delete from joueurs where ID= :id");
   query.bindValue(":id",id);
 return query.exec();

}
