#include "match.h"

unsigned int Match::id_match = 0;

Match::Match()
{
    id_equipe = 0;
    id_match = 0;
}

Match::Match(unsigned int mtrcl, unsigned int nom, QString prenom, QDate daten)
{

    id_match = mtrcl;
    id_equipe = nom;
    discipline = prenom;
    date_match = daten;
}

bool Match::ajouter()
{
    QString id_match_string = QString::number(id_match);
    QString id_equipe_string = QString::number(id_equipe);
    QSqlQuery query;


    query.prepare("INSERT INTO MATCHS (id_match, id_equipe, discipline, date_match)"
                  "VALUES (:matricule_emp, :nom, :prenom, :DATEN)");
    query.bindValue(":matricule_emp", id_match_string);
    query.bindValue(":nom", id_equipe_string);
    query.bindValue(":prenom", discipline);
    query.bindValue(":DATEN", date_match);


    return query.exec();
}

QSqlQueryModel* Match::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT* FROM MATCHS");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_match"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_match"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_equipe"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("discipline"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_lieu_fk"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("nom_discipline_fk"));

    return model;
}


bool Match::supprimer(int id_match)
{
    QSqlQuery query;



     QString id_match_string = QString::number(id_match);

    QString queryString = "DELETE FROM MATCHS where id_match=:matricule";
    query.prepare(queryString);
    query.bindValue(":matricule", id_match_string);

    query.prepare("SELECT COUNT(*) AS 'id_match' FROM users AS u");

    return query.exec();
}

bool Match::modifier(int ancn_idmatch, int nv_idmatch, int nv_idequipe, QString nv_discipline, QDate nv_datematch)
{
    QSqlQuery query;
    QString nv_idmatch_string = QString::number(nv_idmatch);
    QString nv_idequipe_string = QString::number(nv_idequipe);
    QString ancn_idmatch_string = QString::number(ancn_idmatch);

    query.prepare("update matchs set id_match=:mtrcl, date_match=:daten, id_equipe=:nom, discipline=:prenom where id_match=:ancien_mtrcl");

    query.bindValue(":mtrcl", nv_idmatch_string);
    query.bindValue(":nom", nv_idequipe_string);
    query.bindValue(":prenom", nv_discipline);
    query.bindValue(":daten", nv_datematch);
    query.bindValue(":ancien_mtrcl", ancn_idmatch);

    return query.exec();
}

