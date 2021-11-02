#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "joueurs.h"
#include"equipes.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:



    void on_PB_ajouter_clicked();

    void on_pushButton_clicked();

    void on_SUPPRIMERPB_clicked();



    void on_pushButton_2_clicked();

    void on_ajouterequipes_clicked();

    void on_pbsupprimerequipes_clicked();

    void on_pbafficherequipes_clicked();

private:
    Ui::MainWindow *ui;
  joueurs j;
  equipes e;
};

#endif // MAINWINDOW_H
