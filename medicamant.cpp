#include "medicamant.h"

medicamant::medicamant()
{
    id_medicamant="";
    nom_medicamant="";
    qte_medicamant="";
};



medicamant::medicamant(QString id_medicamant,QString nom_medicamant,QString qte_medicamant)
{
    this->id_medicamant=id_medicamant;
    this->nom_medicamant=nom_medicamant;
    this->qte_medicamant=qte_medicamant;


};


QString medicamant::getid_medicamant(){return id_medicamant;}
QString medicamant::getnom_medicamant(){return nom_medicamant;}
QString medicamant::getqte_medicamant(){return qte_medicamant;}


void medicamant::setid_medicamant(QString id_medicamant){this ->id_medicamant;}
void medicamant::setnom_medicamant(QString nom_medicamant){this ->nom_medicamant;}
void medicamant::setqte_medicamant(QString qte_medicamant){this ->qte_medicamant;}



bool medicamant::ajouter_medi()
{
    QSqlQuery Query;
    Query.prepare("INSERT INTO MEDICAMENTS (ID_MEDIC, NOM_MEDIC, QTE_MEDIC)"
                  "VALUES (:ID_MEDIC, :NOM_MEDIC,:QTE_MEDIC)");

    Query.bindValue(":ID_MEDIC",id_medicamant);
    Query.bindValue(":NOM_MEDIC",nom_medicamant);
    Query.bindValue(":QTE_MEDIC",qte_medicamant);
    return  Query.exec();

};




QSqlQueryModel * medicamant::affichermedi(){

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM MEDICAMENTS");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_MEDIC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_MEDIC"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QTE_MEDIC"));

    return model;
}

    //**** afficher enfant ****

QSqlQueryModel * medicamant::afficherenfant(){

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM ENFANTS");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ENFANT"));
    return model;
}

bool medicamant::takeone(QString take){

    QSqlQuery query;
    query.prepare("UPDATE MEDICAMENTS SET QTE_MEDIC=QTE_MEDIC-1 WHERE ID_MEDIC = '"+take+"%");
    query.bindValue(":val",take);
    query.exec();


    return query.exec();


}


bool medicamant::updateenfant(QString id_enfant,QString moy_bpm)
{
    QSqlQuery query;

    query.prepare("UPDATE ENFANTS  SET MOY_BPM=:MOY_BPM WHERE ID_ENFANT=:ID_ENFANT");
    query.bindValue(":ID_ENFANT",id_enfant);
    query.bindValue(":MOY_BPM",moy_bpm);


    return query.exec();

}





QSqlQueryModel * medicamant::trid(){

        QSqlQuery *q = new QSqlQuery();
        QSqlQueryModel *model = new QSqlQueryModel();
        q->prepare("SELECT * FROM MEDICAMENTS ORDER BY ID_MEDIC");
        q->exec();
        model->setQuery(*q);

        return model;

    }

    QSqlQueryModel * medicamant::tritype(){

        QSqlQuery *q = new QSqlQuery();
        QSqlQueryModel *model = new QSqlQueryModel();
        q->prepare("SELECT * FROM MEDICAMENTS ORDER BY QTE_MEDIC");
        q->exec();
        model->setQuery(*q);

        return model;

    }
    QSqlQueryModel *medicamant::trinom(){

        QSqlQuery *q = new QSqlQuery();
        QSqlQueryModel *model = new QSqlQueryModel();
        q->prepare("SELECT * FROM MEDICAMENTS ORDER BY NOM_MEDIC");
        q->exec();
        model->setQuery(*q);

        return model;
    }


















