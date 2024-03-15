#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QSqlQueryModel>
#include "connexion.h"

class etudiant
{
public:
    etudiant();
    etudiant(int,QString);
    etudiant(QString,QString,int,int,int,int,int,int,QString);

    int GetheureD() { return heureD; }
            void SetheureD(int val) { heureD = val; }
            int GetheureF() { return heureF; }
            void SetheureF(int val) { heureF = val; }
            int Getsuiv() { return suiv; }
            void Setsuiv(int val) { suiv = val; }
            int Getreport() { return report; }
            void Setreport(int val) { report = val; }
            int GetidE() { return idE; }
            void SetidE(int val) { idE = val; }
            int Getid() { return id; }
            void Setid(int val) { id = val; }
            int Getannuler() { return annuler; }
            void Setannuler(int val) { annuler = val; }
            QString Getnom_mat() { return nom_mat; }
            void Setnom_mat(QString val) { nom_mat = val; }
            QString Getcommentaire() { return commentaire; }
            void Setcommentaire(QString val) { commentaire = val; }

    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher2(QString);
    QSqlQueryModel* affiche_tri(QString);
    bool supprimer(int id);
    bool update(int id);
    bool decalage(int id);
    bool annuler_methode(int val);
private:
    QString nom_mat,commentaire,date;
    int heureD,heureF,suiv,report,idE,annuler,id;

};

#endif // ETUDIANT_H
