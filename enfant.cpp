#include "enfant.h"
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
enfant::enfant()
{
     nom="";prenom="";adresse_mail_parent="";date_naissance="";
    statut_produit=0;
}
enfant::enfant(int id,int statut_produit,QString nom,QString prenom,QString adresse_mail_parent,QString date_naissance)
{
    this->id=id;
    this->nom=nom;
   this->prenom=prenom;
    this->adresse_mail_parent=adresse_mail_parent;
    this->date_naissance=date_naissance;
   this->statut_produit=statut_produit;
}
bool enfant::ajout_enfant()
{
    QSqlQuery query;
    query.prepare("insert into enfants (ID_ENFANT,NOM_ENFANT,PRENOM_ENFANT,ADRESSE_MAIL_PARENT,DATE_NAISSANCE,STATUE_PRODUIT)"
                  "values(:id,:nom,:prenom,:adresse,:date,:statut)");
    query.bindValue(":id",get_id());
    query.bindValue(":nom",get_nom(nom));
    query.bindValue(":prenom",get_prenom(prenom));
    query.bindValue(":adresse",get_adresse_mail_parent(adresse_mail_parent));
    query.bindValue(":date",get_date_naissance(date_naissance));
    query.bindValue(":statut",get_statut_produit(statut_produit));
    return query.exec();
}
QSqlQueryModel* enfant::afficher_enfant(){
    QSqlQueryModel* f=new QSqlQueryModel();
    f->setQuery("select * from ENFANTS");
        f->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ENFANT"));
        f->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_ENFANT"));
        f->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_ENFANT"));
        f->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE_MAIL_PARENT"));
        f->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
        f->setHeaderData(5, Qt::Horizontal, QObject::tr("STATUT_PRODUIT"));
    return f;
}
QSqlQueryModel* enfant::afficher_enfant2(QString rech){
    QSqlQueryModel* f=new QSqlQueryModel();
    f->setQuery("SELECT * FROM ENFANTS WHERE (id_enfant LIKE '%"+rech+"%' OR NOM_ENFANT LIKE '%"+rech+"%' OR ADRESSE_MAIL_PARENT LIKE '%"+rech+"%')");
    f->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ENFANT"));
    f->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_ENFANT"));
    f->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_ENFANT"));
    f->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE_MAIL_PARENT"));
    f->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
    f->setHeaderData(5, Qt::Horizontal, QObject::tr("STATUT_PRODUIT"));
    return f;
}




bool enfant::supprimer_enfant(int val)
{
    QSqlQuery query;
    query.prepare("delete from enfants where id_enfant = :id");
    query.bindValue(":id",val);
    return  query.exec();
}


bool enfant::modifier_enfant(int id,QString nom,QString prenom,QString adresse_mail_parent,QString date_naissance,int statut_produit  )

     {      QSqlQuery query;

            query.prepare("UPDATE ENFANTS SET ID_ENFANT= :id ,NOM_ENFANT= :nom ,PRENOM_ENFANT=:prenom,ADRESSE_MAIL_PARENT=:adresse ,DATE_NAISSANCE=:date, STATUE_PRODUIT=:statut WHERE ID_ENFANT=:id");

                    query.bindValue(":id",id);
                    query.bindValue(":nom", nom);
                    query.bindValue(":prenom", prenom);
                    query.bindValue(":adresse",adresse_mail_parent);
                    query.bindValue(":date",date_naissance);
                    query.bindValue(":statut",statut_produit);

                return query.exec();
    }


QSqlQueryModel * enfant::RechercherEnfant(QString id)
{
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM enfants WHERE  id_enfant ="+id);

        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Mail Parent"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date Naissance"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("Stat Produit"));

        return model;
}

QStringList enfant::list_Sum(QString var)
{

    QSqlQuery query;
    query.prepare("select DISTINCT("+var+") from consultation");
    query.exec();
    QStringList list;
    while(query.next())
    {
        list.append(query.value(0).toString());
    }

    return list;
}
int enfant::calcul_Sum(QString DIAGNOSTIQUE_CONSULTATION,QString val)
{
    QSqlQuery query;
     query.prepare("select  * from consultation WHERE "+val+"=:DIAGNOSTIQUE_CONSULTATION");
     query.bindValue(":DIAGNOSTIQUE_CONSULTATION", DIAGNOSTIQUE_CONSULTATION );
     query.exec();
     int total=0;
     while(query.next())
     {
       total++;
     }
     return total;
}

QSqlQueryModel* enfant ::trier(int i)
{
    enfant R;
    QSqlQueryModel* model=new QSqlQueryModel();
    if(i==0)
        model= R.afficher_enfant();
    if(i==1)
             {
                 model->setQuery("SELECT * FROM enfants ORDER BY ID_ENFANT ASC");
             }
    else if (i==2)
             {
                 model->setQuery("SELECT * FROM enfants ORDER BY ID_ENFANT DESC");
             }
    else if (i==3)
            {
                 model->setQuery("SELECT * FROM enfants ORDER BY ADRESSE_MAIL_PARENT DESC");
            }

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ENFANT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_ENFANT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_ENFANT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE_MAIL_PARENT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("STATUT_PRODUIT"));
return model;

    return model;
}
