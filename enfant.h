#ifndef ENFANT_H
#define ENFANT_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QString>
#include<QStringList>

class enfant
{

public:
    enfant();
    enfant(int,int,QString,QString,QString,QString);
    void set_id(int id){this->id=id;}
    void set_nom(QString nom){this->nom=nom;}
    void set_prenom(QString prenom){this->prenom=prenom;}
    void set_adresse_mail_parent(QString adresse_mail_parent){this->adresse_mail_parent=adresse_mail_parent;}
    void set_date_naissance(QString date_naissance){this->date_naissance=date_naissance;}
    void set_statut_produit(int statut_produit){this->statut_produit=statut_produit;}
    int get_id(){return id;}
    QString get_nom(QString nom){return nom;}
    QString get_prenom(QString prenom){return prenom;}
    QString get_adresse_mail_parent(QString adresse_mail_parent){return adresse_mail_parent;}
    QString get_date_naissance(QString date_naissance){return date_naissance;}
    int get_statut_produit(int statut_produit){return statut_produit;}
    bool ajout_enfant();
    QSqlQueryModel* afficher_enfant();
    bool supprimer_enfant(int val);
    bool modifier_enfant(int,QString,QString,QString,QString,int);
    QSqlQueryModel *RechercherEnfant(QString id);
    QSqlQueryModel *afficher_enfant2(QString rech);
    QStringList list_Sum(QString var);
    int calcul_Sum(QString DIAGNOSTIQUE_CONSULTATION,QString val);
    QSqlQueryModel * trier(int);
private:
    QString nom,prenom,adresse_mail_parent,date_naissance;
    int id,statut_produit;

};

#endif // ENFANT_H
