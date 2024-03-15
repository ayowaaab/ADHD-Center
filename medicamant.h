#ifndef MEDICAMANT_H
#define MEDICAMANT_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class medicamant
{
public:
    medicamant();
    medicamant(QString,QString,QString);

    QString getid_medicamant();
    QString getnom_medicamant();
    QString getqte_medicamant();



    void setid_medicamant(QString);
    void setnom_medicamant(QString);
    void setqte_medicamant(QString);



    bool ajouter_medi();
    QSqlQueryModel *afficherenfant();
    QSqlQueryModel *affichermedi();
    //QSqlQueryModel *tri(QString);
    QSqlQueryModel *trid();
    QSqlQueryModel *tritype();
    QSqlQueryModel *trinom();
    bool takeone(QString);
    bool updateenfant(QString,QString);


    private:
        QString id_medicamant;
        QString nom_medicamant;
        QString qte_medicamant;


};

#endif // MEDICAMANT_H
