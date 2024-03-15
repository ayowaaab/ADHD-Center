#ifndef CONSULTATION_H
#define CONSULTATION_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class consultation
{
public:
    consultation();
    consultation(QString,QString,QString,QString,QString,QString,QString);

    QString getid_cons();
    QString gettemps_cons();
    QString getsalle_cons();
    QString getdiag_cons();
    QString getid_medecin();
    QString getid_medica();
    QString getid_enfant();




    void setid_cons(QString);
    void settemps_cons(QString);
    void setsallecons(QString);
    void setdiag_cons(QString);
    void setid_medecin(QString);
    void setid_medica(QString);
    void setid_enfant(QString);




    bool ajouter_cons();
    QSqlQueryModel *afficherenfant();
    QSqlQueryModel *affichermedi();
    QSqlQueryModel *tri_cons();
    QSqlQueryModel *trid_cons();
    QSqlQueryModel *afficher_cons();


    private:
        QString ID_cons;
        QString Temps_cons;
        QString Salle_cons;
        QString diag_cons;
        QString id_medecin;
        QString id_medica;
        QString id_enfant;

};

#endif // CONSULTATION_H
