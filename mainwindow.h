#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "joueurs.h"
#include <QMainWindow>
#include "equipe.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    equipe e;
    JOUEURS j;


private slots:
    void on_pushButton_clicked();

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

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
