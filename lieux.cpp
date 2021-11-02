#include "lieux.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
lieux::lieux()
{
    id_lieux =0;
    nom = "";
    type= "";
}

lieux:: lieux(int id, QString nom, QString prenom)
{
    this->id_lieux = id;
    this->nom = nom;
    this->type = prenom;

}

int     lieux:: getid(){return id_lieux;}
QString lieux:: getnom(){return nom ;}
QString lieux:: gettype(){return type;}

void lieux::setid(int id ){this->id_lieux=id ;}
void lieux::setnom(QString nom){this->nom=nom;}
void lieux::settype(QString prenom){this->type=prenom;}

bool lieux::ajouter()
{

    QSqlQuery query;
    query.prepare("INSERT INTO lieux (id_lieux, nom, type) "
                  "VALUES (:id_lieux, :nom, :type)");
    query.bindValue(":id_lieux", id_lieux);
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);

    return query.exec();

}

bool lieux ::supprimer(int id)
{

    QSqlQuery query;

    query.prepare("Delete from lieux where id_lieux=:id_lieux ");

    query.bindValue(":id_lieux",id);

    return query.exec();


}

QSqlQueryModel* lieux::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT* FROM lieux");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_lieux"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));


  return model ;
}
bool lieux::modifier(QString id)
{
    QSqlQuery query;

    query.prepare("UPDATE lieux SET id_lieux=:newid  ,nom=:new_adresse  where id_lieux=:id_lieux ");
    query.bindValue(":newid", id_lieux);
    query.bindValue(":new_nom", nom);
    query.bindValue(":id_lieux", id);
    return query.exec();
}
