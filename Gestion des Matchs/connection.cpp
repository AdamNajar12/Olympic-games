#include "connection.h"

Connection::Connection(){}

bool Connection::ouvrirConnexion()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test-bd");
    db.setUserName("jalel");
    db.setPassword("jalel");

    if (db.open())
        test=true;

    return  test;
}

void Connection::fermerConnexion(){ db.close(); }
