#include "pays.h"
#include<QString>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>


Pays::Pays()
{

nom_pays="";

r="";
forfait="";

}

Pays::Pays(QString n)
{

nom_pays=n;
forfait=n;
}
Pays::Pays(QString a,QString b)
{
    nom_pays=a;
    r=b;


}


void Pays::setnom(QString)
{this->nom_pays=nom_pays;}

QString Pays::getnom()
{return nom_pays;}

bool Pays::ajouter()
{



 QSqlQuery query;
 query.prepare("INSERT INTO PAYS ( NOM_PAYS) "
               "VALUES ( :nom)");

 query.bindValue(":nom", nom_pays);

 return query.exec();

}

bool Pays::Supprimer(int  id)
{

    QSqlQuery query;
    query.prepare("Delete from PAYS where id_pays=:id");
    query.bindValue(":id", id);

    return query.exec();

}


QSqlQueryModel* Pays::afficher()
{
QSqlQuery query;
    QSqlQueryModel* model= new QSqlQueryModel();

    query.prepare("SELECT NOM_PAYS,ID_PAYS FROM PAYS ORDER BY ID_PAYS DESC ");
          query.exec();
          model->setQuery(query);


   return model;

}

bool Pays::update(int id)
{QString rid=QString::number(id);

    QSqlQuery query;
       query.prepare(QString("update pays set NOM_PAYS=:nom where ID_PAYS=:id"));

       query.bindValue(":id",rid);
       query.bindValue(":nom",nom_pays);



     return  query.exec();
}


QStringList Pays::sup_id()
{

  QSqlQuery query;
query.prepare("Select id_pays from pays");
QStringList list;
while(query.next())
{

    list<<query.value(0).toString();
}
return list;


}
QSqlQueryModel* Pays::ClassementPays()
{
    QSqlQuery query;
        QSqlQueryModel* model= new QSqlQueryModel();

        query.prepare("SELECT NOM_PAYS,MEDAILLE_OR,MEDAILLE_AR,MEDAILLE_BR FROM PAYS ORDER BY MEDAILLE_AR+MEDAILLE_OR+MEDAILLE_BR DESC ");
              query.exec();
              model->setQuery(query);


       return model;



}

QSqlQueryModel* Pays::nb_habitans()
{
    QSqlQuery query;
        QSqlQueryModel* model= new QSqlQueryModel();

        query.prepare("SELECT NOM_PAYS,POURCENT_HB FROM PAYS ORDER BY POURCENT_HB DESC ");
              query.exec();
              model->setQuery(query);


       return model;






}

QSqlQueryModel* Pays::classementpop()
{

    QSqlQuery query;
        QSqlQueryModel* model= new QSqlQueryModel();

        query.prepare("SELECT NOM_PAYS,MEDAILLE_OR,MEDAILLE_AR,POURCENT_POP FROM PAYS ORDER BY POURCENT_POP DESC ");
              query.exec();
              model->setQuery(query);


       return model;





}
bool Pays::ajouter_rec()
{

    QSqlQuery query;
    query.prepare("INSERT INTO RECLAMATION_PAYS ( NOM,RAISON)  "
                  "VALUES ( :nom,:raison)");

    query.bindValue(":nom", nom_pays);
   query.bindValue(":raison", r);

    return query.exec();




  }
bool Pays::declarer_forfait(int id)
{


        QSqlQuery query;
           query.prepare("UPDATE PAYS SET FORFAIT=:forfait WHERE ID_PAYS=:id");

           query.bindValue(":id",id);
query.bindValue(":forfait",forfait);



         return  query.exec();








}



















