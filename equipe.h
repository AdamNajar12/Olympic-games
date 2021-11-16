#ifndef EQUIPE_H
#define EQUIPE_H
#include<QString>
#include<QSqlQueryModel>

class equipe
{
   QString nom_dis;
   QString nom;
   int nb;
   QString dis;
   int score;
   QString records;


public:
    equipe();

    equipe(QString,QString,int,int);
    equipe(QString,QString,QString);

   QString get_nom();

   int get_nb();

 void set_nom(QString);
 void set_nb(int);
 bool ajouter_equipe();
 bool ajouter_equipe_records();
 QSqlQueryModel *afficher();
 QSqlQueryModel *afficher_records();
bool supprimer(int id);
bool update_equipe(int id);
QSqlQueryModel *afficher_historiques_equipe();
QSqlQueryModel *afficher_historiques();
QSqlQueryModel *classementfoot();
QSqlQueryModel *classementbasket();
QStringList sup_id();
};

#endif // EQUIPE_H
