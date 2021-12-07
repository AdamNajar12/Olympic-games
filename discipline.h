#ifndef DISCIPLINE_H
#define DISCIPLINE_H
#include <QString>
#include <QSqlQueryModel>


class discipline
{
public:
    discipline();
    discipline(int,QString,QString);
    int getid(){return id;}
    QString getNom(){return nom;}
    QString getType(){return type;}


       void setid(int);
       void setnom(QString);
       void settype(QString);

       bool ajouter();
       QSqlQueryModel*  afficher();
       bool supprimer(int);
       bool modifier(int);
       QSqlQueryModel * chercher(const QString &nom);
       bool reclamer(QString);
       QSqlQueryModel * afficher_calendrier();
       bool select();
     /*  QSqlQueryModel *recherche_id(int id);
       QSqlQueryModel *recherche_nom(QString nom);
       QSqlQueryModel *recherche_type(QString type);*/



   private :
       int id;
       QString nom, type, date_debut, date_fin;
};

#endif // DISCIPLINE_H
