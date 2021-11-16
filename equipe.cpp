#include "equipe.h"

#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<iostream>
#include<QMessageBox>

equipe::equipe()
{
nom="";
nb=0;
dis="";
records="";
}

equipe::equipe(QString v,QString n,int a,int d)
{dis=v;
   nom=n;
    nb=a;
    score=d;

}
equipe::equipe(QString v,QString n,QString d)
{
  dis=v;
 records=n;
 nom=d;


}



QString equipe::get_nom()
{return nom;}

int equipe::get_nb()
{return nb;}

void equipe::set_nom(QString nom)
{this->nom=nom;}
void equipe::set_nb(int nb)
{this->nb=nb;}
bool equipe::ajouter_equipe()
{

     QString run= QString::number(nb);
     QString runs= QString::number(score);
         QSqlQuery query;
    query.prepare("INSERT INTO EQUIPE (NOM_DISCIPLINE,NOM,NB_JOUEURS,SCORE) VALUES (:nom_discipline,:nom,:nb_joueurs,:score);");
 query.bindValue(":nom_discipline",dis);
   query.bindValue(":nom",nom );
   query.bindValue(":nb_joueurs",run);
   query.bindValue(":score",runs);
    return query.exec();
}
QSqlQueryModel* equipe::afficher()
{
    QSqlQuery query;
        QSqlQueryModel* model= new QSqlQueryModel();

        query.prepare("SELECT* FROM EQUIPE ");
              query.exec();
              model->setQuery(query);


       return model;
}
bool equipe::supprimer(int id)
{
QString rid=QString::number(id);
    QSqlQuery query;
    query.prepare("Delete from equipe where id_equipe=:id ");
    query.bindValue(":id", rid);

    return query.exec();

}
bool equipe::update_equipe(int id)
{QString rid=QString::number(id);
    QString rnb=QString::number(nb);
    QString runs= QString::number(score);
    QSqlQuery query;
       query.prepare(QString("update equipe set nom_discipline=:nom_discipline,nom=:nom,nb_joueurs=:nb_joueurs,score=:score where id_equipe=:id"));

       query.bindValue(":id",rid);
       query.bindValue(":nom_discipline",dis);
       query.bindValue(":nom",nom);
       query.bindValue(":nb_joueurs",rnb);
        query.bindValue(":score",runs);

     return  query.exec();
}
QStringList equipe::sup_id(){
    QSqlQuery query;
query.prepare("Select id_equipe from equipe;");


 query.exec();
    QStringList list;
    while (query.next()) {
        list << query.value(0).toString();
    }
    return list;
}
QSqlQueryModel *equipe::classementfoot()
{
    QSqlQuery query;
        QSqlQueryModel* model= new QSqlQueryModel();

        query.prepare("SELECT nom,score FROM EQUIPE where nom_discipline='football' order by score desc;  ");
              query.exec();
              model->setQuery(query);


       return model;

}

QSqlQueryModel *equipe::classementbasket()
{
    QSqlQuery query;
        QSqlQueryModel* model= new QSqlQueryModel();

        query.prepare("SELECT nom,score FROM EQUIPE where nom_discipline='basketball' order by score desc;  ");
              query.exec();
              model->setQuery(query);


       return model;

}
QSqlQueryModel* equipe::afficher_historiques_equipe()
{
    QSqlQuery query;
        QSqlQueryModel* model= new QSqlQueryModel();

        query.prepare("SELECT* FROM historique_equipe ");
              query.exec();
              model->setQuery(query);


       return model;
}
bool equipe::ajouter_equipe_records()
{



     QSqlQuery query;
     query.prepare("INSERT INTO records (NOM_DISCIPLINE,score,nom) VALUES (:nom_discipline,:score,:nom);");

     query.bindValue(0,dis);
     query.bindValue(1,records);
     query.bindValue(2,nom);


    return query.exec();
}
QSqlQueryModel* equipe::afficher_records()
{
    QSqlQuery query;
        QSqlQueryModel* model= new QSqlQueryModel();

        query.prepare("SELECT* FROM records");
              query.exec();
              model->setQuery(query);


       return model;
}
QSqlQueryModel* equipe::afficher_historiques()
{
    QSqlQuery query;
        QSqlQueryModel* model= new QSqlQueryModel();

        query.prepare("SELECT* FROM basket ");
              query.exec();
              model->setQuery(query);


       return model;
}
