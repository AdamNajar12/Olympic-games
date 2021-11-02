#ifndef JOUEURS_H
#define JOUEURS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class joueurs
{private:
    QString prenom;
    QString nom;
    int ID;

public: 
    joueurs();
    joueurs(QString a,QString b,int c);
    QString get_nom();
    QString get_prenom();
    int get_id();
    void set_nom(QString nom);
    void set_prenom(QString prenom);
    void set_id(int id);
    bool ajouter();
    bool supprimer(int i);
   QSqlQueryModel *afficher();






};

#endif // JOUEURS_H
