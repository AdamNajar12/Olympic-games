#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "match.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QIntValidator>

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
    void on_btn_ajouter_clicked();

    void on_btn_supprimer_clicked();

    void on_btn_modifier_clicked();

private:
    Ui::MainWindow *ui;
    Match E;
};
#endif // MAINWINDOW_H
