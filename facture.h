#ifndef FACTURE_H
#define FACTURE_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QString>



class facture
{
public:

    facture();
    facture(int,int,QString,QString,int);
    void set_id_facture(int id_facture){this->id_facture=id_facture;}
    void set_montant_a_payer(int montant_a_payer){this->montant_a_payer=montant_a_payer;}
    void set_statut_paiement(QString statut_paiement){this->statut_paiement=statut_paiement;}

    void set_date_paiement(QString date_paiement){this->date_paiement=date_paiement;}
int get_id_facture(){return id_facture;}

    QString get_statut_paiement(){return statut_paiement;}
    QString get_date_paiement(){return date_paiement;}

    int get_montant_a_payer(){return montant_a_payer;}
    bool ajout_facture();
    QSqlQueryModel* afficher_facture();
    bool supprimer_facture(int val,int vv);


    QSqlQueryModel* afficher_facture2(QString);
    bool modifier(int,int,QString,int);
    QSqlQueryModel* trier(int);

private:
    int id_facture,montant_a_payer,ide;
    QString statut_paiement,date_paiement;
};

#endif // FACTURE_H
