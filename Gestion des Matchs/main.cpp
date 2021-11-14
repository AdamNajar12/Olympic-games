#include "mainwindow.h"
#include "connection.h"

#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    bool test = c.ouvrirConnexion();

    MainWindow w;

    if( test )
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Connection successful.\n"
                                             "Click cancel to exit."),
                                 QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                                 QObject::tr("Connection failed.\n"
                                             "Click cancel to exit."),
                                 QMessageBox::Cancel);
    }

    return a.exec();
}
