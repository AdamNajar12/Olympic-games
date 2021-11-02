#ifndef EQUIPES_H
#define EQUIPES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class equipes
{private:
    QString nom;
    QString categorie;
    int nb_joueurs;
    int id_equipe;

public:
 equipes();
 equipes(QString a,QString b,int d,int e);
QString get_equipe_nom();
QString get_equipe_categorie();
int get_equipe_nb();
int get_equipe_id();
void set_equipe_nom(QString nom );
void set_equipe_categorie(QString categorie);
void set_equipe_nb(int a);
void set_equipe_id(int b);
bool ajouter();
bool supprimer(int id );
QSqlQueryModel *afficher();
};

#endif // EQUIPES_H
