#ifndef JOUEURS_H
#define JOUEURS_H
#include <QString>
#include<QSqlQueryModel>
class JOUEURS
{QString nom;
    QString prenom;
    int id ;

public:
    JOUEURS();
    JOUEURS(QString,QString);
     JOUEURS(QString,QString,int);

    QString get_nom();
    QString get_prenom();
    void set_nom(QString);
    void set_prenom(QString);
    bool ajoute_joueur();
    QSqlQueryModel *afficher_joueur();
    bool supprimer_joueur(int id);
    bool update(int id);
    QStringList sup_id();
     QSqlQueryModel *afficher_joueur_equipe(int id);

};

#endif // JOUEURS_H
