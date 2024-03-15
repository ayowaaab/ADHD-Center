#include "task.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
task::task()
{

}
task::task(int id_task,int cin_perso,QString disc,QString com1,QString com2,QString com3){
    this->id_task=id_task;
    this->cin_perso=cin_perso;
    this->disc=disc;
    this->com1=com1;
    this->com2=com2;
    this->com3=com3;
}

int task::get_id_task(){
    return id_task;
}
int task::get_cin_peros(){
    return cin_perso;
}
QString task::get_disc(){
    return disc;
}
QDate task::get_date(){
    return date_limite;
}
QString  task::get_com1(){
    return com1;
}
QString  task::get_com2(){
    return com2;
}
QString  task::get_com3(){
    return com3;
}
void task::set_id_task(int id_task){
    this->id_task=id_task;
}
void task::set_cin_perso(int cin){
    this->cin_perso=cin;
}
void task::set_disc(QString disc){
    this->disc=disc;
}
void task::set_date(QDate d){
    this->date_limite=d;
}
void task::set_com1(QString com1){
    this->com1=com1;
}
void task::set_com2(QString com2){
    this->com2=com2;
}
void task::set_com3(QString com3){
    this->com3=com3;
}

bool task::ajouter_task(){
    QSqlQuery query;
        query.prepare("INSERT INTO task (id_task,cin_pers,date_limite,description,com1,com2,com3) "
                      "VALUES (:id_task,:cin_pers,:date_limite,:description,:com1,:com2,:com3)");
        query.bindValue(":id_task",id_task);
        query.bindValue(":cin_pers",cin_perso);
        query.bindValue(":date_limite",date_limite);
        query.bindValue("::description",disc);
        query.bindValue(":com1",com1);
        query.bindValue(":com2",com2);
        query.bindValue(":com3",com3);
      return  query.exec();
}

QSqlQueryModel* task::afficher(const QString &nom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString query = "SELECT cin_pers,date_limite,description,com1,com2,com3 FROM task WHERE cin_pers LIKE '%" + nom + "%'"
                    " OR date_limite LIKE '%" + nom + "%'"
                    " OR description LIKE '%" + nom + "%'";

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("dedline"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("descriptione"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("com1"));
    return model;
}

bool task::delete_task(int id_t){

        QSqlQuery query;
        query.prepare("DELETE FROM TASK WHERE ID=:id");
        query.bindValue(":id",id_t);

        return  query.exec();

}
bool task::mod_task(int j){
    QSqlQuery query;
    query.prepare("UPDATE task SET date_limite=:date_l,description=:description WHERE id=:id");
     query.bindValue(":id",j);
    query.bindValue(":date_l",date_limite);
    query.bindValue(":description",disc);
    return  query.exec();
}

bool task::comentaire1(int j){
    QSqlQuery query;
    query.prepare("UPDATE task SET COM1=:com WHERE id=:id");
     query.bindValue(":id",j);
    query.bindValue(":com",com1);

    return  query.exec();
}
bool task::comentaire2(int j){
    QSqlQuery query;
    query.prepare("UPDATE task SET COM2=:com WHERE id=:id");
     query.bindValue(":id",j);
    query.bindValue(":com",com2);

    return  query.exec();
}
bool task::comentaire3(int j){
    QSqlQuery query;
    query.prepare("UPDATE task SET COM3=:com WHERE id=:id");
     query.bindValue(":id",j);
    query.bindValue(":com",com3);

    return  query.exec();
}
