#ifndef BENEVOLE_H
#define BENEVOLE_H


#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QSqlQuery>
#include <QSqlQueryModel>

class benevole
{
public:
    benevole();
    benevole(QString nom,QString email,QString adress,QString disp,QString activite
                 ,int id,int tel,int score,int abs);
       //getters
        QString Getnom() { return nom; }
                void Setnom( QString  val) { nom = val; }
                 QString  Getemail() { return email; }
                void Setemail( QString  val) { email = val; }
                 QString  Getadress() { return adress; }
                void Setadress( QString  val) { adress = val; }
                 QString  Getdisp() { return disp; }
                void Setdisp( QString  val) { disp = val; }
                int Getid() { return id; }
                void Setid(int val) { id = val; }
                int Getscore() { return score; }
                void Setscore(int val) { score = val; }
                int Gettel() { return tel; }
                void Settel(int val) { tel = val; }
                int Getabs() { return abs; }
                void Setabs(int val) { abs = val; }
                QString Getactivite(){return activite;}
                void Setactivite(QString val){ activite = val;}
       //Fonction de base relative a benevole
       bool ajouter();
       QSqlQueryModel * afficher();

       bool Export(int );
       bool supprimer(int);
       bool modifier(int ,QString ,QString ,QString ,QString ,int ,int ,int,QString );
       QSqlQueryModel * trier(int);
       QSqlQueryModel * rechercher(QString);

        void statistique(QVector<double>* ticks,QVector<QString> *labels);
        QStringList list_Sum(QString var);
        int calcul_Sum(QString date_naissance,QString val);
        QSqlQueryModel * afficher_ben();
        QSqlQueryModel * afficher_event();
        int check(QString);
protected:

private:

    QString nom,email,adress,activite,disp;
    int id,tel,abs,score;
};

class participent:benevole
{
public:

    int Getid_participent() { return id_participent; }
    void Setid_participent(int val) { id_participent = val; }
    int Getid_event() { return id_event; }
    void Setid_event(int val) { id_event = val; }
    int Getid_benevole() { return id_benevole; }
    void Setid_benevole(int val) { id_benevole = val; }
    QString Getbene_nom() { return bene_nom; }
    void Setbene_nom(QString val) { bene_nom = val; }
    QString Getevent_nom() { return event_nom; }
    void Setevent_nom(QString val) { event_nom = val; }
    QString Getdate_event() { return date_event; }
    void Setdate_event(QString val) { date_event = val; }

    bool ajouter_participent(int ,int  ,QString,QString);
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * trier(int);
    bool supprimer(int,int,int);
    void updatesup(int);
    void updateevnt(int);
    void updatben(int,QString);
    void updatesupben(int);


private:
    int id_participent;
           int id_event;
           int id_benevole;
           QString bene_nom;
           QString event_nom;
           QString date_event;
};

#endif // BENEVOLE_H
