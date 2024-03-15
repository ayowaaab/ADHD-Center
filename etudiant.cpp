#include "etudiant.h"


etudiant::etudiant()
{
    nom_mat="";commentaire="";
    heureD=0;heureF=0;suiv=0;report=0;idE=0;annuler=0;
}

etudiant::etudiant(QString nom_mat,QString commentaire,int heureD,int heureF,int suiv,int report,int idE,int annuler,QString date)
{
    this->nom_mat=nom_mat;this->commentaire=commentaire;
    this->heureD=heureD;this->heureF=heureF;
    this->suiv=suiv;this->report=report;this->idE=idE;this->annuler=annuler;
    this->date=date;
}

etudiant::etudiant(int val1,QString val2){
    heureD=val1;    
    date=val2;    
}

bool etudiant::ajouter(){
    QSqlQuery query;

    QString heureDD = QString::number(heureD);
    QString heureFF = QString::number(heureF);
    QString suivv = QString::number(suiv);
    QString reportee = QString::number(report);
    QString idEE = QString::number(idE);
    QString ann = QString::number(annuler);


    query.prepare("INSERT INTO seance (HEURE_DEBUT,HEURE_FIN,COMMENTAIRE,NOM_MATIER,"
                  "SUIVI_SEANCE,REPORTER,ANNULATION,ID_ENFANT,DATE_SEANCE)"
                  "values(:heureD, :heureF, :cmnt, :nom_mat, :suivi, :reporter, :annul"
                  ", :id_enf, :date)");

    query.bindValue(":heureD",heureDD);
    query.bindValue(":heureF",heureFF);
    query.bindValue(":nom_mat",nom_mat);
    query.bindValue(":cmnt",commentaire);
    query.bindValue(":suivi",suivv);
    query.bindValue(":reporter",reportee);
    query.bindValue(":annul",ann);
    query.bindValue(":id_enf",idEE);
    query.bindValue(":date",date);

    return query.exec();


}
QSqlQueryModel* etudiant::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from seance");
    return model;
}
QSqlQueryModel* etudiant::afficher2(QString rech){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from seance where id_seance like '%"+rech+"%' or NOM_MATIER like '%"+rech+"%' or ID_ENFANT like '%"+rech+"%' ");
    return model;
}
QSqlQueryModel* etudiant::affiche_tri(QString tri){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from seance ORDER BY "+tri);
    return model;
}



bool etudiant::supprimer(int id){
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("DELETE FROM seance WHERE id_seance=:id");
    query.bindValue(0, res);
    return query.exec();
}

bool etudiant::update(int val){
    QSqlQuery query;
    QString res = QString::number(val);
    QString heureDD = QString::number(heureD);
    QString heureFF = QString::number(heureF);
    QString suivii = QString::number(suiv);
    QString idee = QString::number(idE);

    query.prepare("Update seance SET HEURE_DEBUT='"+heureDD+"',HEURE_FIN='"+heureFF+"',COMMENTAIRE='"+commentaire+"',"
                "NOM_MATIER='"+nom_mat+"',SUIVI_SEANCE='"+suivii+"',ID_ENFANT='"+idee+"'"
                "WHERE id_seance='"+res+"'");
    return query.exec();
}
bool etudiant::decalage(int val){
    QSqlQuery query;
    QString res = QString::number(val);
    QString heureDD = QString::number(heureD);
    query.prepare("Update seance SET HEURE_DEBUT='"+heureDD+"',DATE_SEANCE='"+date+"',REPORTER=REPORTER+1 WHERE id_seance='"+res+"'");
    return query.exec();
}
bool etudiant::annuler_methode(int val){
    QSqlQuery query,query1;
    QString res = QString::number(val);
    int value= -1;
    query1.prepare("SELECT ANNULATION FROM SEANCE WHERE ID_SEANCE = :value");
    query1.bindValue(":value",res);
    query1.exec();
    while(query1.next())
    value = query1.value(0).toInt();

    if(value==0){
        query.prepare("Update seance SET ANNULATION=ANNULATION+1 WHERE id_seance='"+res+"'");
        return query.exec();
    }
        return false;
}
















