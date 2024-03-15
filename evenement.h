#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE




class evenement
{
public:
evenement();
evenement(QString,QString,QString,QString,QString);


QString getid();

QString getnom();
QString getdescription();
QString gettype();
QString getdate_event();



QSqlQueryModel *trinom();
QSqlQueryModel * trid();
QSqlQueryModel *tritype();
QSqlQueryModel * afficher();




QSqlQueryModel *rechercher(QString);



void setid(QString);

void setnom(QString);
void setdescription(QString);
void settype(QString);
void setdate_event(QString);


bool ajouter();

bool supprimer(QString);
bool modifier();



private:
QString id;
QString nom,description,type,date_event;




};



#endif // EVENEMENT_H
