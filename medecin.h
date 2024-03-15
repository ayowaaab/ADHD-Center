#ifndef CRUD_MEDECIN_H
#define CRUD_MEDECIN_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class medecin
{
public:
    medecin();
    medecin(QString,QString,QString,QString,QString,QString);
    QString getnom_medecin();
    QString getprenom_medecin();
    QString getadresse_medecin();
    QString getadressemail_medecin();
    QString getparcour_medecin();
    QString getID_medecin();

    void setnom_medecin(QString);
    void setprenom_medecin(QString);
    void setadresse_medecin(QString);
    void setadressemail_medecin(QString);
    void setparcour_medecin(QString);
    void setID_medecin(QString);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool update(QString);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tric();
    QSqlQueryModel * trid();

private:
    QString nom_medecin,prenom_medecin,adresse_medecin;
    QString adressemail_medecin,parcour_medecin;
    QString ID_medecin;

};



#endif // CRUD_MEDECIN_H
