#include "etudiant.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
etudiant::etudiant()
{
    id =0;
    nom = "";
    prenom= "";
}

etudiant:: etudiant(int id, QString nom, QString prenom)
{
    this->id = id;
    this->nom = nom;
    this->prenom = prenom;

}

int     etudiant:: getid(){return id;}
QString etudiant:: getnom(){return nom ;}
QString etudiant:: getprenom(){return prenom;}

void etudiant::setid(int id ){this->id=id ;}
void etudiant::setnom(QString nom){this->nom=nom;}
void etudiant::setprenom(QString prenom){this->prenom=prenom;}

bool etudiant::ajouter()
{

    QSqlQuery query;
    query.prepare("INSERT INTO citoyen (id, nom, prenom) "
                  "VALUES (:id, :nom, :prenom)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);

    return query.exec();

}

bool etudiant ::supprimer(int id)
{

    QSqlQuery query;

    query.prepare("Delete from citoyen where id=:id ");

    query.bindValue(":id",id);

    return query.exec();


}

QSqlQueryModel* etudiant::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT* FROM citoyen");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));


  return model ;
}
