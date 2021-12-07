#ifndef LIEUX_H
#define LIEUX_H
#include <QString>
#include <QSqlQueryModel>

class lieux
{
public:
    lieux();
    lieux(int,QString,QString,QString);
    int getid();
    QString getnom();
    QString gettype();


    void setid(int);
    void setnom(QString);
    void settype(QString);

    bool ajouter();
    QSqlQueryModel*  afficher();
    bool supprimer(int);
    bool modifier(QString);
    QSqlQueryModel * trier();
    QSqlQueryModel * trier1();
    QSqlQueryModel * trier2();
    QSqlQueryModel * trier3();
    QSqlQueryModel * rechercher(QString rech);



private :
    int id_lieux;
    QString nom, etat, type;
};


#endif // LIEUX_H
