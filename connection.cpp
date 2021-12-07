#include "connection.h"
#include<QDebug>
#include<QMessageBox>

Connection::Connection(){}

bool Connection::createconnection()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("Admin");
    db.setPassword("admin");

    if (db.open())
    {
        test=true;
    }
    return test;
}

void Connection::closeconnection()
{
    QSqlDatabase db;
    db.close();
}


