#include "medecin.h"



medecin::medecin()
{

    ID_medecin="";
    nom_medecin="";
    prenom_medecin="";
    adresse_medecin="";
    adressemail_medecin="";
    parcour_medecin="";

};


medecin::medecin(QString ID_medecin,QString nom_medecin,QString prenom_medecin,QString adresse_medecin,QString adressemail_medecin,QString parcour_medecin){

    this->ID_medecin=ID_medecin;
    this->nom_medecin=nom_medecin;
    this->prenom_medecin=prenom_medecin;
    this->adresse_medecin=adresse_medecin;
    this->adressemail_medecin=adressemail_medecin;
    this->parcour_medecin=parcour_medecin;

};

QString medecin::getID_medecin() {return ID_medecin;}
QString medecin::getnom_medecin() {return nom_medecin;}
QString medecin::getprenom_medecin() {return prenom_medecin;}
QString medecin::getadresse_medecin() {return adresse_medecin;}
QString medecin::getadressemail_medecin() {return adressemail_medecin;}
QString medecin::getparcour_medecin() {return parcour_medecin;}


void medecin::setID_medecin(QString ID_medecin){this->ID_medecin=ID_medecin;}
void medecin::setnom_medecin(QString nom_medecin){this->nom_medecin=nom_medecin;}
void medecin::setprenom_medecin(QString prenom_medecin){this->prenom_medecin=prenom_medecin;}
void medecin::setadresse_medecin(QString adresse_medecin){this->adresse_medecin=adresse_medecin;}
void medecin::setadressemail_medecin(QString adressemail_medecin){this->adressemail_medecin=adressemail_medecin;}
void medecin::setparcour_medecin(QString parcour_medecin){this->parcour_medecin=parcour_medecin;}




bool medecin::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO MEDECIN (ID_MEDECIN, NOM_MEDECIN, PRENOM_MEDECIN, ADRESSE_MEDECIN, ADRESSEMAIL_MEDECIN, PARCOUR_MEDECIN)"
                  "VALUES (:ID_MEDECIN, :NOM_MEDECIN,:PRENOM_MEDECIN,:ADRESSE_MEDECIN,:ADRESSEMAIL_MEDECIN,:PARCOUR_MEDECIN)");

    query.bindValue(":ID_MEDECIN",ID_medecin);
    query.bindValue(":NOM_MEDECIN",nom_medecin);
    query.bindValue(":PRENOM_MEDECIN",prenom_medecin);
    query.bindValue(":ADRESSE_MEDECIN",adresse_medecin);
    query.bindValue(":ADRESSEMAIL_MEDECIN",adressemail_medecin);
    query.bindValue(":PARCOUR_MEDECIN",parcour_medecin);

    return query.exec();

};

QSqlQueryModel * medecin::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM MEDECIN");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_medecin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_MEDECIN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_MEDECIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE_MEDECIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSEMAIL_MEDECIN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PARCOUR_MEDECIN"));

    return model;
}

bool medecin::supprimer(QString ID_medecin){

    QSqlQuery query;
    query.prepare("DELETE FROM MEDECIN WHERE ID_MEDECIN=:ID_MEDECIN");
    query.bindValue(0,ID_medecin);
    return query.exec();

}


bool medecin::update(QString ID_medecin)
{
    QSqlQuery query;

    query.prepare("UPDATE MEDECIN SET PARCOUR_MEDECIN=:PARCOUR_MEDECIN WHERE ID_MEDECIN=:ID_MEDECIN");
    query.bindValue(":ID_MEDECIN",ID_medecin);
    query.bindValue(":NOM_MEDECIN",nom_medecin);
    query.bindValue(":PRENOM_MEDECIN",prenom_medecin);
    query.bindValue(":ADRESSE_MEDECIN",adresse_medecin);
    query.bindValue(":ADRESSEMAIL_MEDECIN",adressemail_medecin);
    query.bindValue(":PARCOUR_MEDECIN",parcour_medecin);
    return query.exec();

}


QSqlQueryModel *medecin::rechercher(QString rech)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from MEDECIN where ID_MEDECIN LIKE '"+rech+"%' OR NOM_MEDECIN LIKE '"+rech+"%' OR PRENOM_MEDECIN LIKE '"+rech+"%'");

    return model;


}









