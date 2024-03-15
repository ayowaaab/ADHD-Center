#include "facture.h"
#include<string>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include <QCalendarWidget>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <iostream>
#include <QMessageBox>
facture::facture()
{
montant_a_payer=0;statut_paiement="non";date_paiement="";
}
facture::facture(int id_facture,int montant_a_payer,QString statut_paiement,QString date_paiement,int id_enfant)
{
    this->id_facture=id_facture;
    this->ide=id_enfant;
    this->montant_a_payer=montant_a_payer;
   this->statut_paiement=statut_paiement;
    this->date_paiement=date_paiement;

}
bool facture::ajout_facture()
{
QSqlQuery query;
QString montant =QString::number(montant_a_payer);
query.prepare("insert into facture (ID_FACTURE,MONTANT_FACT,STATUT_fact,DATE_fact,ID_ENFANT)"
              "values(:id,:montant,:statut,:date,:ide)");
query.bindValue(":id",id_facture);
query.bindValue(":montant",montant);
query.bindValue(":date",get_date_paiement());
query.bindValue(":statut", get_statut_paiement());
query.bindValue(":ide", ide);
return query.exec();
}
QSqlQueryModel* facture::afficher_facture(){
    QSqlQueryModel* f=new QSqlQueryModel();
    f->setQuery("select * from facture");
        f->setHeaderData(0, Qt::Horizontal, QObject::tr("ID FACTURE"));
        f->setHeaderData(2, Qt::Horizontal, QObject::tr("MONTANT A PAYER"));
        f->setHeaderData(3, Qt::Horizontal, QObject::tr("STATUT PAIEMENT"));
        f->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE PAIEMENT"));
        f->setHeaderData(1, Qt::Horizontal, QObject::tr("ID ENFANT"));
        f->setHeaderData(5, Qt::Horizontal, QObject::tr("Duree Paiment"));

    return f;
}
QSqlQueryModel* facture::afficher_facture2(QString rech){
    QSqlQueryModel* f=new QSqlQueryModel();
    f->setQuery("SELECT * FROM facture WHERE (ID_FACTURE LIKE '%"+rech+"%' OR DATE_FACT LIKE '%"+rech+"%' OR ID_ENFANT LIKE '%"+rech+"%' OR DUREE_RETARD_FACT LIKE '%"+rech+"%')");
        f->setHeaderData(0, Qt::Horizontal, QObject::tr("ID FACTURE"));
        f->setHeaderData(2, Qt::Horizontal, QObject::tr("MONTANT A PAYER"));
        f->setHeaderData(3, Qt::Horizontal, QObject::tr("STATUT PAIEMENT"));
        f->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE PAIEMENT"));
        f->setHeaderData(1, Qt::Horizontal, QObject::tr("ID ENFANT"));
        f->setHeaderData(5, Qt::Horizontal, QObject::tr("Duree Paiment"));
    return f;
}
bool facture::supprimer_facture(int id_enfant,int id_facture)
{
    QSqlQuery query;
    query.prepare("delete from facture where ID_ENFANT = :id and ID_FACTURE=:id_f");
    query.bindValue(":id",id_enfant);
    query.bindValue(":id_f",id_facture);
    return  query.exec();
}


bool facture::modifier(int montant, int statut_paiement,QString date_paiement,int idee)

     {

        QSqlQuery query;

                query.prepare("update FACTURE set  MONTANT_FACT=:mont , STATUT_FACT=:stat , DATE_FACT=:date  where ID_FACTURE=:id");
                query.bindValue(":id",idee);

                query.bindValue(":mont", montant);
                query.bindValue(":stat", statut_paiement);

                query.bindValue(":date",date_paiement);






                return query.exec();   //execution de requette
    }

QSqlQueryModel* facture ::trier(int i)
{
    facture R;
    QSqlQueryModel* model=new QSqlQueryModel();
    if(i==0)
        model= R.afficher_facture();
    if(i==1)
             {
                 model->setQuery("SELECT * FROM facture ORDER BY DATE_PAIEMENT ASC");
             }
    else if (i==2)
             {
                 model->setQuery("SELECT * FROM facture ORDER BY DATE_PAIEMENT DESC");
             }
    else if (i==3)
            {
                 model->setQuery("SELECT * FROM facture ORDER BY ID_FACTURE ASC");
            }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FACTURE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("MONTANT_A_PAYER"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("STATUT_PAIEMENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_PAIEMENT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_ENFANT"));
return model;

    return model;
}

