#ifndef MATCH_H
#define MATCH_H

#include <QString>
#include <QDebug>
#include <QObject>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Match
{
private:
    static unsigned int id_match;
    unsigned int id_equipe;
    QString discipline;
    QDate date_match;

public:
    Match();
    Match(unsigned int, unsigned int, QString, QDate);

    static unsigned int get_id_match() { return id_match; }
    unsigned int get_id_equipe() { return id_equipe; }
    QString get_discipline() { return discipline; }
    QDate get_date_match() { return date_match; }

    void set_id_match(unsigned int m) { id_match = m; }
    void set_id_equipe(unsigned int n) { id_equipe = n; }
    void set_discipline(QString p) { discipline = p; }
    void set_date_match(QDate dn) { date_match = dn; }

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int, int, int, QString, QDate);
};

#endif // MATCH_H
