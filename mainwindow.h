#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "discipline.h"
#include "arduino.h"
#include "joueurs.h"
#include "equipe.h"
#include"pays.h"
#include"lieux.h"

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




       void on_pushButton_2_clicked();

       void on_supprimer_clicked();

       void on_pushButton_3_clicked();



       void on_comboBox_currentTextChanged(const QString &arg1);


       void on_pushButton_4_clicked();

       void on_supprimer_2_clicked();

       void on_pushButton_5_clicked();

       void on_pushButton_6_clicked();

       void on_pushButton_7_clicked();

       void on_pushButton_8_clicked();

       void on_pushButton_9_clicked();

       void on_pushButton_10_clicked();

       void on_pushButton_13_clicked();

       void on_pushButton_12_clicked();

       void on_pushButton_11_clicked();
       void on_pushButton_14_clicked();

       void on_pushButton_15_clicked();

       void on_pushButton_16_clicked();

       void on_pushButton_17_clicked();

       void on_pushButton_18_clicked();

       void on_pushButton_19_clicked();

       void on_pushButton_20_clicked();

       void on_pushButton_21_clicked();

       void on_pushButton_22_clicked();

       void on_pushButton_23_clicked();

       void on_pushButton_24_clicked();

       void on_pushButton_28_clicked();

       void on_tabWidget_lieux_tabBarClicked(int index);

       void on_comboBox_17_currentIndexChanged(int index);

       void on_pushButton_27_clicked();

       void on_lineEdit_5_textChanged(const QString &arg1);

       void on_pushButton_26_clicked();

       void on_pushButton_25_clicked();

private:
    Ui::MainWindow *ui;
    discipline tmpDiscipline;
       QByteArray data;
       arduino A;
       QString uid;
       equipe e;
          JOUEURS j;
         Pays P; QString val_lieux;
         lieux L;

};
#endif // MAINWINDOW_H
