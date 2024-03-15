#include "consultation.h"





consultation::consultation()
{

    ID_cons="";
    Temps_cons="";
    Salle_cons="";
    diag_cons="";
    id_medecin="";
    id_enfant="";
    id_medica="";


};


consultation::consultation(QString ID_cons,QString temps_cons,QString salle_cons,QString diag_cons,QString id_medecin,QString id_enfant,QString id_medica ){
    this->ID_cons=ID_cons;
    this->Temps_cons=temps_cons;
    this->Salle_cons=salle_cons;
    this->diag_cons=diag_cons;
    this->id_enfant=id_enfant;
    this->id_medica=id_medica;
    this->id_medecin=id_medecin;
};

QString consultation::getid_cons() {return ID_cons;}
QString consultation::gettemps_cons() {return Temps_cons;}
QString consultation::getsalle_cons() {return Salle_cons;}
QString consultation::getdiag_cons() {return diag_cons;}

QString consultation::getid_enfant() {return id_enfant;}
QString consultation::getid_medica() {return id_medica;}
QString consultation::getid_medecin() {return id_medecin;}

void consultation::setid_cons(QString ID_cons){this->ID_cons=ID_cons;}
void consultation::settemps_cons(QString Temps_cons){this->Temps_cons=Temps_cons;}
void consultation::setsallecons(QString salle_cons){this->Salle_cons=salle_cons;}
void consultation::setdiag_cons(QString diag_cons){this->diag_cons=diag_cons;}

void consultation::setid_enfant(QString id_enfant){this->id_enfant=id_enfant;}
void consultation::setid_medica(QString id_medica){this->id_medica=id_medica;}
void consultation::setid_medecin(QString id_medecin){this->id_medecin=id_medecin;}



bool consultation::ajouter_cons()
{
    QSqlQuery query;


    query.prepare("INSERT INTO CONSULTATION (ID_CONSULTATION, TEMPS_CONSULTATION, SALE_CONSULTATION, DIAGNOSTIQUE_CONSULTATION, ID_MEDECIN,ID_ENFANT,ID_MEDECA)"
                  "VALUES (:ID_CONSULTATION,:TEMPS_CONSULTATION,:SALE_CONSULTATION,:DIAGNOSTIQUE_CONSULTATION,:ID_MEDECIN,:ID_ENFANT,:ID_MEDECA)");


    query.bindValue(":ID_CONSULTATION",ID_cons);
    query.bindValue(":TEMPS_CONSULTATION",Temps_cons);
    query.bindValue(":SALE_CONSULTATION",Salle_cons);
    query.bindValue(":DIAGNOSTIQUE_CONSULTATION",diag_cons);
    query.bindValue(":ID_MEDECIN",id_medecin);
    query.bindValue(":ID_ENFANT",id_enfant);
    query.bindValue(":ID_MEDECA",id_medica);

    return query.exec();

}


QSqlQueryModel * consultation ::afficher_cons(){
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM CONSULTATION");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_CONSULTATION"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TEMPS_CONSULTATION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("SALE_CONSULTATION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DIAGNOSTIQUE_CONSULTATION"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_MEDECIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_ENFANT"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID_MEDECA"));


    return model;
}
















