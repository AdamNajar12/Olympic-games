#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "discipline.h"
#include "arduino.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
   // void update_label(); //slot permettant la mise à jour du label état de la lampe, ce slot est lancé à chaque récupération d'un message de arduino
    void on_pushButtonajouter_clicked();

    void on_pushButton_clicked();

    void on_pushButtonmodifier_clicked();

    void on_pushButton_Rechercher_clicked();


    void on_pushButton_his_clicked();

    void on_pushButton_EnvoyerReclamation_clicked();

    void on_afficher_c_clicked();

    void on_pushButton_A_clicked();

    void on_pushButton_R_clicked();

private:
    Ui::MainWindow *ui;
    discipline tmpDiscipline;
    QByteArray data;
    arduino A;
    QString uid;
};
#endif // MAINWINDOW_H

