#ifndef TASK_H
#define TASK_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class task
{
public:
    task();
     task(int,int,QString,QString,QString,QString);
    int get_id_task();
    int get_cin_peros();
    QString get_disc();
    QDate get_date();
    QString  get_com1();
    QString  get_com2();
    QString  get_com3();
    void set_id_task(int);
    void set_cin_perso(int);
    void set_disc(QString);
    void set_date(QDate);
    void set_com1(QString);
    void set_com2(QString);
    void set_com3(QString);
    bool ajouter_task();
    bool delete_task(int);
    bool mod_task(int);
    bool comentaire1(int);
    bool comentaire2(int);
    bool comentaire3(int);
    QSqlQueryModel* afficher(const QString &nom);
private:
int id_task;
int cin_perso;
QDate date_limite;
QString disc;
QString com1;
QString com2;
QString com3;
};

#endif // TASK_H
