#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lieux.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QMessageBox>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include<QFileInfo>
#include<QFileDialog>
#include <QTextEdit>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget_lieux->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    QSqlQuery query;
    int Id =ui->lineEdit->text().toInt();
    QString a =ui->lineEdit->text();
    QString Nom=ui->lineEdit_2->text();
    QString etat=ui->lineEdit_3->text();
    QString type=ui->lineEdit_6->text();
    lieux C(Id,Nom,etat,type);
    bool alreadyExist = false;
    query.prepare("select * from lieux where id_lieux=:id_lieux");
    query.bindValue(":id_lieux",Id);
    if(!query.exec())
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
        QObject::tr("Failed adding.\n"
        "Click Cancel to exit."), QMessageBox::Cancel);
    }

    alreadyExist = query.next();
    if(alreadyExist){
        C.modifier(a);
    QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
    QObject::tr("UPDATED.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
              C.ajouter();
              QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
              QObject::tr("ADDED.\n"
              "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->tableView->setModel(C.afficher());
}

void MainWindow::on_pushButton_clicked()
{
    int Id =ui->lineEdit_4->text().toInt();
    lieux C;
    bool test=C.supprimer(Id);
    if(test)
    {
         ui->tableView->setModel(C.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("DELETED.\n click cancel to exit."),QMessageBox::Cancel);

    }
    else
       QMessageBox::critical(nullptr, QObject::tr("Not ok"),QObject::tr("ERROR.\n click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_3_clicked()
{
    val_lieux=ui->lineEdit_4->text();
    ui->tabWidget_lieux->setCurrentIndex(0);
    QSqlQuery qry;
    qry.prepare("SELECT * FROM lieux where id_lieux='"+val_lieux+"'");
    if(qry.exec( ))
    {
        while (qry.next())
        {
            ui->lineEdit->setText(qry.value(0).toString());
            ui->lineEdit_2->setText(qry.value(1).toString());
            ui->lineEdit_3->setText(qry.value(2).toString());
            ui->lineEdit_6->setText(qry.value(3).toString());

        }

    }
}

void MainWindow::on_tabWidget_lieux_tabBarClicked(int index)
{
    if(index==1)
    ui->tableView->setModel(L.afficher());
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    switch (index)
    {
      case 0:  ui->tableView->setModel(L.trier());break;
      case 1:  ui->tableView->setModel(L.trier1());break;
      case 2:  ui->tableView->setModel(L.trier2());break;
      case 3:  ui->tableView->setModel(L.trier3());break;

    }
}

void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
    ui->tableView->setModel(L.rechercher(arg1));
}

void MainWindow::on_pushButton_4_clicked()//PDF
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->columnCount(); // Collones de tableaux

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("strTitle")
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"

        //     "<align='right'> " << datefich << "</align>"
        "<center> <H1>Liste Des Lieux </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n\n\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->tableView->isColumnHidden(column))
            {
                QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table> </center>\n"
        "</body>\n"
        "</html>\n";

    QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".pdf");
    }

    QPrinter printer (QPrinter::PrinterResolution);
     printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setPaperSize(QPrinter::A4);
     printer.setOutputFileName(fileName);

     QTextDocument doc;
     doc.setHtml(strStream);
     doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
     doc.print(&printer);
}

void MainWindow::on_pushButton_5_clicked()
{
    QPrinter printer;
     printer.setPrinterName("Imprimante");
     QPrintDialog dialog(&printer, this);
     if (dialog.exec() == QDialog::Rejected) return;
     ui->tableView->render(&printer);
}
