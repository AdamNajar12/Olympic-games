/*#include "statistique.h"
#include "ui_mainwindow.h"
#include "discipline.h"
#include"QSqlRecord"
#include"QSqlQuery"
Statistique::Statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistique)
{
    ui->setupUi(this);
    this->setWindowTitle("Statistique");
    makePolt();
}

Statistique::~Statistique()
{
    delete ui ;
}

void Statistique::makePolt()
{
    //set-up
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->stat->setBackground(QBrush(gradient));
    QCPBars *regen = new QCPBars(ui->stat->xAxis, ui->stat->yAxis);
    regen->setAntialiased(false);
    regen->setStackingGap(1);
    regen->setName("Quantités");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));

    //x axis
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 ;
    labels << "Marsa" << " Tunis" << "Gammarth" ;//axe x
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);

    ui->stat->xAxis->setTicker(textTicker);
    ui->stat->xAxis->setTickLabelRotation(60);
    ui->stat->xAxis->setSubTicks(false);
    ui->stat->xAxis->setTickLength(0, 4);
    ui->stat->xAxis->setRange(0, 8);
    ui->stat->xAxis->setBasePen(QPen(Qt::white));
    ui->stat->xAxis->setTickPen(QPen(Qt::white));
    ui->stat->xAxis->grid()->setVisible(true);
    ui->stat->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->stat->xAxis->setTickLabelColor(Qt::white);
    ui->stat->xAxis->setLabelColor(Qt::white);

    //y axis

    ui->stat->yAxis->setRange(0,100);//intervale de x
    ui->stat->yAxis->setPadding(5); // espace cote d
    ui->stat->yAxis->setBasePen(QPen(Qt::white));
    ui->stat->yAxis->setTickPen(QPen(Qt::white));
    ui->stat->yAxis->setSubTickPen(QPen(Qt::white));
    ui->stat->yAxis->grid()->setSubGridVisible(true);
    ui->stat->yAxis->setTickLabelColor(Qt::white);
    ui->stat->yAxis->setLabelColor(Qt::white);
    ui->stat->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->stat->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

//donnees
    QVector<double> regenData;

    QSqlQuery query1("select SUM(QUANTITES)from disciplines where NOM_DISCIPLINE ='Football' ");

    while (query1.next()) {
                int  nbr_faute=0;
                int  nbr_fautee = query1.value(0).toInt();
                int nbr_fauteee;

              QSqlQuery query2("select SUM(QUANTITES)from disciplines where NOM_DISCIPLINE ='Basketball' ");
              while (query2.next()) {
                                       QSqlQuery query3("select SUM(QUANTITES)from disciplines where NOM_DISCIPLINE ='Volleyball' ");
                                      nbr_faute = query2.value(0).toInt();
                                      while(query3.next())
                                       {
                                            nbr_fauteee =query3.value(0).toInt();
                                            break;
                                       }
                            }
              regenData<< nbr_fautee << nbr_faute << nbr_fauteee;
                            break;
                           }

    regen->setData(ticks, regenData);

    //legend


    ui->stat->legend->setVisible(true);
    ui->stat->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->stat->legend->setBrush(QColor(255, 255, 255, 100));
    ui->stat->legend->setBorderPen(Qt::NoPen);

    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->stat->legend->setFont(legendFont);
    ui->stat->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);





}



statistique::statistique()
{

}
*/
