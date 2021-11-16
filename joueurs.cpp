#include "joueurs.h"

#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
JOUEURS::JOUEURS()
{
nom="";
prenom="";
id=0;

}

JOUEURS::JOUEURS(QString a,QString b,int i)
{
   nom=a;
  prenom=b;
 id=i;

}
JOUEURS::JOUEURS(QString a,QString b)
{
   nom=a;
  prenom=b;


}
QString JOUEURS::get_nom()
{return nom; }
QString JOUEURS::get_prenom()
{return prenom;}
void JOUEURS::set_nom(QString nom)
{this->nom=nom;}
void JOUEURS::set_prenom(QString prenom)
{this->prenom=prenom;}
bool JOUEURS::ajoute_joueur()
{

    QSqlQuery query;
    query.prepare("INSERT INTO joueur (nom,prenom,id_equipe) VALUES ( :nom, :prenom,:id_equipe);");
query.bindValue(":id_equipe",id );
   query.bindValue(":nom",nom );
   query.bindValue(":prenom",prenom);
    return query.exec();
}
QSqlQueryModel* JOUEURS::afficher_joueur()
{
    QSqlQuery query;
        QSqlQueryModel* model= new QSqlQueryModel();

        query.prepare("SELECT* FROM joueur ");
              query.exec();
              model->setQuery(query);


       return model;
}
bool JOUEURS::supprimer_joueur(int id)
{
QString rid=QString::number(id);
    QSqlQuery query;
    query.prepare("Delete from joueur where id_joueur=:id ");
    query.bindValue(":id", rid);

    return query.exec();

}
bool JOUEURS::update(int id)
{QString rid=QString::number(id);

    QSqlQuery query;
       query.prepare(QString("update joueur set nom=:nom,prenom=:prenom where id_joueur=:id"));

       query.bindValue(":id",rid);
       query.bindValue(":nom",nom);
       query.bindValue(":prenom",prenom);


     return  query.exec();
}
QStringList JOUEURS::sup_id(){
    QSqlQuery query;
query.prepare("Select id_joueur from joueur;");


 query.exec();
    QStringList list;
    while (query.next()) {
        list << query.value(0).toString();
    }
    return list;
}
QSqlQueryModel* JOUEURS::afficher_joueur_equipe(int id)
{
    QSqlQuery query;
        QSqlQueryModel* model= new QSqlQueryModel();
        QString rid=QString::number(id);

        query.prepare("SELECT nom,prenom FROM joueur where id_equipe=:id");
        query.bindValue(":id",rid);
              query.exec();
              model->setQuery(query);


       return model;
}


