#ifndef PAYS_H
#define PAYS_H
#include<QString>
#include<QSqlQueryModel>

class Pays
{
public:
    Pays();
    Pays(QString n);
    Pays(QString a,QString b);
   Pays(QString a,QString b,QString d);
    void setid(int );
    int getid();
    void setnom(QString);
    QString getnom();
bool ajouter();
QSqlQueryModel* afficher();
bool Supprimer( int id);
bool update(int id);
QStringList sup_id();
QSqlQueryModel* ClassementPays();
QSqlQueryModel* classementpop();
QSqlQueryModel* nb_habitans();
QSqlQueryModel* nom_Pays(int id);
bool ajouter_rec();
bool declarer_forfait(int id);

private:
QString r;
QString nom_pays;
QString forfait;



};

#endif // PAYS_H
