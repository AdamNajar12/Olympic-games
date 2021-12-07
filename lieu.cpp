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

lieux:: lieux(int id, QString nom, QString etat, QString type)
{
    this->id_lieux = id;
    this->nom = nom;
    this->etat = etat;
    this->type = type;

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
    query.prepare("INSERT INTO lieux (id_lieux, nom, etat, type) "
                  "VALUES (:id_lieux, :nom, :etat, :type)");
    query.bindValue(":id_lieux", id_lieux);
    query.bindValue(":nom", nom);
    query.bindValue(":etat", etat);
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
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));



  return model ;
}
bool lieux::modifier(QString id)
{
    QSqlQuery query;

    query.prepare("UPDATE lieux SET id_lieux=:newid,nom=:new_nom,etat=:new_etat,type=:new_type   where id_lieux=:id_lieux ");
    query.bindValue(":newid", id_lieux);
    query.bindValue(":new_nom", nom);
    query.bindValue(":new_etat", etat);
    query.bindValue(":new_type", type);
    query.bindValue(":id_lieux", id);
    return query.exec();
}
//tri par id.
QSqlQueryModel *lieux::trier()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM lieux order by id_lieux");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_lieux"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));

    return  model;
}
//tri par nom.
QSqlQueryModel *lieux::trier1()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM lieux order by nom");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_lieux"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));

    return  model;
}
//tri par etat.
QSqlQueryModel *lieux::trier2()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM lieux order by etat");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_lieux"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));

    return  model;
}
//tri par type.
QSqlQueryModel *lieux::trier3()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM lieux order by type");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_lieux"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));

    return  model;
}
//recherche.
QSqlQueryModel *lieux::rechercher(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM lieux WHERE id_lieux  LIKE'%"+rech+"%' or nom  LIKE'%"+rech+"%' or etat  LIKE'%"+rech+"%' or type  LIKE'%"+rech+"%'");
    return model;
}


