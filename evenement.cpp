#include "evenement.h"


#include <QtCharts>
#include <QChartView>
#include <QLineSeries>


evenement::evenement()
{

    id="";
    nom="";
    description="";
    type="";
    date_event="";

};
evenement::evenement(QString id,QString nom,QString description,QString type , QString date_event)
{
    this->id=id;
    this->nom=nom;
    this->description=description;
    this->type=type;
    this->date_event=date_event;

};

QString evenement::getid() {return id;}

QString evenement::getnom(){return nom;}
QString evenement::getdescription(){return description;}
QString evenement::gettype(){return type;}
QString evenement::getdate_event(){return date_event;}



void evenement::setid(QString id){this->id=id;}

void evenement::setnom(QString nom){this->nom=nom;}
void evenement::setdescription(QString description){this->description=description;}
void evenement::settype(QString type){this->type=type;}
void evenement::setdate_event(QString date_event){this->date_event=date_event;}

bool evenement::ajouter()
{
    QSqlQuery query;
          query.prepare("INSERT INTO evenement (ID_EVENT,NOM_EVENT,TYPE_EVENT,DATE_EVENT,DESCRIPTION_EVENT) "
                        "VALUES (:id,:nom,:type,:date_event,:description)");
          query.bindValue(":id", id);
          query.bindValue(":nom",nom);
          query.bindValue(":description", description);
          query.bindValue(":type", type);
          query.bindValue(":date_event", date_event);

          return query.exec();
};
QSqlQueryModel * evenement::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM evenement");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIOTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));

        return model;
    }
    bool evenement::supprimer(QString id )
    {
    QSqlQuery query;
    query.prepare("DELETE FROM evenement  WHERE id=:id ");
    query.bindValue(0, id);
    return    query.exec();
    }

    bool evenement::modifier()

     {      QSqlQuery query;

            query.prepare("update evenement set id=:id,nom=:nom,description=:description ,type=:type,date_event=:date_event where id=:id");
                query.bindValue(":id",id);

                query.bindValue(":nom", nom);
                query.bindValue(":description",description);
                    query.bindValue(":type",type);
                        query.bindValue(":date_event",date_event);



                return query.exec();   //execution de requette
    }


    QSqlQueryModel * evenement::trid(){

        QSqlQuery *q = new QSqlQuery();
        QSqlQueryModel *model = new QSqlQueryModel();
        q->prepare("SELECT * FROM evenement ORDER BY ID_EVENT");
        q->exec();
        model->setQuery(*q);

        return model;

    }

    QSqlQueryModel * evenement::tritype(){

        QSqlQuery *q = new QSqlQuery();
        QSqlQueryModel *model = new QSqlQueryModel();
        q->prepare("SELECT * FROM evenement ORDER BY TYPE_EVENT");
        q->exec();
        model->setQuery(*q);

        return model;

    }
    QSqlQueryModel * evenement::trinom(){

        QSqlQuery *q = new QSqlQuery();
        QSqlQueryModel *model = new QSqlQueryModel();
        q->prepare("SELECT * FROM evenement ORDER BY NOM_EVENT");
        q->exec();
        model->setQuery(*q);

        return model;

    }


    QSqlQueryModel *evenement::rechercher(QString rech)
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("select * from evenement where ID_EVENT LIKE '"+rech+"%' OR NOM_EVENT LIKE '"+rech+"%' OR TYPE_EVENT LIKE '"+rech%+"%'");

        return model;


    }

