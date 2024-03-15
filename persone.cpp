#include "persone.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
#include <QDate>
persone::persone()
{

}
persone::persone(int cin,QString nom,QString prenom,QString date,QString sex,QString metier,QString email,QString experience,QString containt ,QString salaire){
this->cin=cin;
this->nom=nom;
this->prenom=prenom;
this->date=date;
this->sex=sex;
this->email=email;
this->experience=experience;
this->contraint=containt;
this->salaire=salaire;
this->metier=metier;


}
int persone::get_cin(){
    return cin;
}
QString persone::get_nom(){
    return nom;
}
QString persone::get_prenom(){
    return prenom;
}
QString persone::get_date(){
    return date;
}
QString persone::get_email(){
    return email;
}
QString persone::get_experience(){
    return experience;
}
QString persone::get_contraint(){
    return  contraint;
}
QString persone::get_sex(){
    return sex;
}
QString persone::get_salaire(){
    return salaire;
}
QString persone::get_metier(){
    return  metier;
}
void persone::set_cin(int cin){
    this->cin =cin;
}
void persone::set_nom(QString nom){
    this->nom=nom;
}
void persone::set_prenom(QString prenom){
    this->prenom=prenom;
}
void persone::set_date(QString date){
    this->date=date;
}
void persone::set_email(QString email){
    this->email=email;
}
void persone::set_experience(QString experience){
    this->experience=experience;
}
void persone::set_contraint(QString contraint){
    this->contraint=contraint;
}
void persone::set_sex(QString sex){
    this->sex=sex;
}
void persone::set_salaire(QString salaire){
    this->salaire=salaire;
}
void persone::set_metier(QString metier){
    this->metier=metier;
}
bool persone::ajouter(QByteArray mg){
QSqlQuery query;
    query.prepare("INSERT INTO persone (cin,nom,prenom,birthday,metier,salaire,sex,experience,contraint,email,id_event,IMG) "
                  "VALUES (:cin,:nom,:prenom,:birthday,:metier,:salaire,:sex,:experience,:contraint,:email,:id_event,:IMG)");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    QDate birthday = QDate::fromString(date, "yyyy-MM-dd");
       QDate today = QDate::currentDate();
       int age = today.year() - birthday.year();
       if (today.month() < birthday.month() ||
           (today.month() == birthday.month() && today.day() < birthday.day())) {
           age--;
       }

    query.bindValue(":birthday",age);
    query.bindValue(":metier",metier);
    query.bindValue(":salaire",salaire);
    query.bindValue(":sex",sex);
    query.bindValue(":experience",experience);
    query.bindValue(":contraint",contraint);
    query.bindValue(":email",email);
     query.bindValue(":id_event",3);
     query.bindValue(":IMG",mg);
  return  query.exec();


}

/*QSqlQueryModel* persone::afficher(){
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("SELECT cin,nom,prenom,metier FROM persone where nom LIKE :nom");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3 , Qt::Horizontal, QObject::tr("metier"));

return model;
}
QSqlQueryModel* persone::afficher(QString searchStr) {
    QSqlQueryModel * model=new QSqlQueryModel();
    QString query = "SELECT cin,nom,prenom,metier FROM persone";
    if(!searchStr.isEmpty()){
        query += QString(" WHERE nom LIKE '%%1%'").arg(searchStr);
    }
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3 , Qt::Horizontal, QObject::tr("metier"));

    return model;
}*/

QSqlQueryModel* persone::afficher(const QString &nom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString query = "SELECT cin, nom, prenom, metier, salaire,birthday FROM persone WHERE nom LIKE '%" + nom + "%'"
                    " OR cin LIKE '%" + nom + "%'"
                    " OR prenom LIKE '%" + nom + "%'"
                    " OR metier LIKE '%" + nom + "%'";
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Metier"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("slaire"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("age"));
    return model;
}




bool persone::supprimer(int id){
    QSqlQuery query;
    query.prepare("SELECT * FROM persone WHERE cin=:cin");
    query.bindValue(":cin",cin);
    query.exec();
    if(!query.next()){
        return false;
    }
    query.prepare("DELETE FROM persone WHERE cin=:id");
    query.bindValue(":id",id);

    return  query.exec();
}

bool persone::modifier(){
    QSqlQuery query;
    query.prepare("SELECT * FROM persone WHERE cin=:cin");
    query.bindValue(":cin",cin);
    query.exec();
    if(!query.next()){
        return false;
    }
    query.prepare("UPDATE persone SET nom=:name,prenom=:prenom,birthday=:birthday,metier=:metier,salaire=:salaire,sex=:sex,experience=:experience,contraint=:contraint,email=:email WHERE cin=:cin");
    query.bindValue(":cin",cin);
    query.bindValue(":name",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":birthday",date);
    query.bindValue(":metier",metier);
    query.bindValue(":salaire",salaire);
    query.bindValue(":sex",sex);
    query.bindValue(":experience",experience);
    query.bindValue(":contraint",contraint);
    query.bindValue(":email",email);

    return  query.exec();

}
