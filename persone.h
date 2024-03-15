#ifndef PERSONE_H
#define PERSONE_H
#include <QString>
#include <QSqlQueryModel>

class persone
{
public:
    persone();
    persone(int,QString,QString,QString,QString,QString,QString,QString,QString,QString);

int get_cin();
QString get_nom();
QString get_prenom();
QString get_date();
QString get_email();
QString get_experience();
QString get_contraint();
QString get_sex();
QString get_salaire();
QString get_metier();
void set_cin(int cin);
void set_nom(QString nom);
void set_prenom(QString prenom);
void set_date(QString date);
void set_email(QString email);
void set_experience(QString experience);
void set_contraint(QString contraint);
void set_sex(QString sex);
void set_salaire(QString salaire);
void set_metier(QString metier);
bool ajouter(QByteArray);
QSqlQueryModel* afficher(const QString &nom);
bool supprimer(int);
bool modifier();

private:
    int cin;
    QString nom;
    QString prenom;
    QString date;
    QString sex;
    QString email;
    QString salaire;
    QString experience;
    QString contraint;
    QString metier;


};

#endif // PERSONE_H
