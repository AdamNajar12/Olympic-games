#include "equipes.h"


equipes::equipes()
{
nom="";
categorie="";
nb_joueurs=0;
id_equipe=0;
}
equipes::equipes(QString a,QString b,int c,int d)
{categorie=a;
    nom=b;
    nb_joueurs=c;
    id_equipe=d;



}
QString equipes::get_equipe_nom()
{
    return nom;
}
QString equipes::get_equipe_categorie()
{return categorie;}
int equipes::get_equipe_nb()
{return nb_joueurs;}
int equipes::get_equipe_id()
{return id_equipe;}
 void equipes::set_equipe_nom(QString nom)
 {this->nom=nom;}
 void equipes::set_equipe_categorie(QString categorie){this->categorie=categorie;}
 void equipes::set_equipe_nb(int a)
 {this->nb_joueurs=a;}
void equipes::set_equipe_id(int b)
{this->id_equipe=b;}
bool equipes::ajouter()
{

    QSqlQuery query;
    QString test= QString::number(id_equipe);
     QString run= QString::number(nb_joueurs);
          query.prepare("INSERT INTO equipes ( categorie, nom, nb_joueurs, id) "
                        "VALUES ( :categorie, :nom, :nb_joueurs, :id)");
         query.bindValue(":categorie",categorie);
         query.bindValue(":nom",nom);

          query.bindValue(":nb_joueurs",run);
          query.bindValue(":id",test);


          return query.exec();//EXECUTER LA REQUETTE

}
bool equipes::supprimer(int id)
{
    QSqlQuery query;
   query.prepare("Delete from equipes where ID= :id");//preparer la requette
   query.bindValue(":id",id);//avec la valeur de l'id;
 return query.exec();//executer la requette

}
QSqlQueryModel* equipes::afficher()
{
    QSqlQuery query ;
    QSqlQueryModel *model=new QSqlQueryModel();
query.prepare("SELECT * FROM equipes");
query.exec();
model->setQuery(query);

    return model;

}
