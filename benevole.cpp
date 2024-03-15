#include "benevole.h"

benevole::benevole()
{

}
benevole::benevole(QString nom,QString email,QString adress,QString disp,QString activite,
                    int id,int tel,int score,int abs)
{
    this->nom=nom;
     this->email=email;
     this->adress=adress;
     this->disp=disp;
     this->tel=tel;
     this->id=id;
     this->score=score;
     this->abs=abs;
     this->activite=activite;
}

bool benevole::ajouter()
{


    QSqlQuery query;

    query.prepare("INSERT INTO BENEVOLE (ID_BEN, NOM_BEN, ADRESS_BEN, EMAIL_BEN, ACTIVITE_BEN, TEL_BEN, SCORE_BEN, ABS_BEN, DISP_DEB_BEN) "
                  "VALUES (:id, :nom ,:adress, :email ,:activite ,:tel ,:score ,:abs , :disp)");
    query.bindValue(":id",Getid());
    query.bindValue(":nom",Getnom());
    query.bindValue(":adress",Getadress());
    query.bindValue(":email",Getemail());
    query.bindValue(":activite",Getactivite());
    query.bindValue(":tel",Gettel());
    query.bindValue(":score",Getscore());
    query.bindValue(":abs",Getabs());
    query.bindValue(":disp",Getdisp());

    return  query.exec(); //exec() tlanci requette lel serveur
}

QSqlQueryModel * benevole::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from BENEVOLE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Adress"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Activite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Tel"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Score"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Abs"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("Disp_date"));




    return model;
}

bool benevole::supprimer(int val)
{
    QSqlQuery query;
    query.prepare("DELETE FROM BENEVOLE WHERE ID_BEN =:id");
    query.bindValue(":id",val);
    return    query.exec();
}

bool benevole::modifier(int id,QString nom,QString adr,QString email,QString act,int tel,int score,int abs,QString disp)
{
    QSqlQuery query;
   query.prepare("update BENEVOLE set ID_BEN=:id,NOM_BEN=:noms,ADRESS_BEN=:adr,EMAIL_BEN=:eml,ACTIVITE_BEN=:act,TEL_BEN=:tl,\
    SCORE_BEN=:scr,ABS_BEN=:ab,DISP_DEB_BEN=:disp   where ID_BEN=:id");
   query.bindValue(":id",id);
    query.bindValue(":noms",nom);
   query.bindValue(":adr",adr);
   query.bindValue(":eml",email);
   query.bindValue(":act",act);
   query.bindValue(":tl",tel);
   query.bindValue(":scr",score);
   query.bindValue(":ab",abs);
   query.bindValue(":disp",disp);
   return query.exec();

}

QSqlQueryModel * benevole::rechercher(QString rech){
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM BENEVOLE WHERE (ID_BEN LIKE '%"+rech+"%' OR NOM_BEN LIKE '%"+rech+"%' OR EMAIL_BEN LIKE '%"+rech+"%')");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("adress"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("activite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("score"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("abs"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("disp_date"));




    return model;
}


QSqlQueryModel* benevole ::trier(int i)
{
    benevole R;
    QSqlQueryModel* model=new QSqlQueryModel();
    if(i==0)
        model= R.afficher();
    if(i==1)
             {
                 model->setQuery("SELECT * FROM BENEVOLE ORDER BY ID_BEN ASC");
             }
    else if (i==2)
             {
                 model->setQuery("SELECT * FROM BENEVOLE ORDER BY ID_BEN DESC");
             }

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("adress"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("activite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("score"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("abs"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("disp_date"));

    return model;
}

bool benevole::Export(int tst)
{
    QString Tex;
    bool test=false;
    QSqlQueryModel * model=new QSqlQueryModel;
    QString tsst=QString::number(tst);
            model->setQuery("SELECT * FROM BENEVOLE WHERE ID_BEN ="+tsst);///Badalet hethi
            int rows = model->rowCount();
            for (int i = 0; i < rows; i++)
            {


            int a=model->data(model->index(0,i)).toInt();


            QString res=QString::number(a);
            QString b=QString::number(a*0.2);
            QString c=QString::number(a*0.3);
            QString d=QString::number(a*0.5);
            Tex += "Votre Budget de "+res+" se divise sur 3 proportions :\n"
                                               +b+" pour les frais d'organisation \n"
                                               +c+" pour les frais de médiatisation \n"
                                               +d+" pour les joueurs et les gagnants des compétitions\n "

                        ;
            }
            QFile txtFile("Certife.txt");
                if(txtFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
                {
                    test=true;
                    QTextStream out(&txtFile);

                    out << Tex;
                    txtFile.close();
                }

                return test ;///Zedet Hethi

}

void benevole::statistique(QVector<double>* ticks,QVector<QString> *labels)
{
    QSqlQuery q;
    int i=0;
    q.exec("select NOM_BEN from BENEVOLE");
    while (q.next())
    {
        QString identifiant = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<identifiant;
    }
}
QStringList benevole::list_Sum(QString var)
{
    QSqlQuery query;
    query.prepare("select DISTINCT("+var+") from benevole");
    query.exec();
    QStringList list;
    while(query.next())
    {
        list.append(query.value(0).toString());
    }

    return list;
}
int benevole::calcul_Sum(QString date_naissance,QString val)
{
    QSqlQuery query;
     query.prepare("select  * from benevole  WHERE "+val+"=:date_naissance");
     query.bindValue(":date_naissance", date_naissance );
     query.exec();
     int total=0;
     while(query.next())
     {
       total++;
     }
     return total;
}

QSqlQueryModel * benevole::afficher_ben()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select ID_BEN , NOM_BEN , ACTIVITE_BEN, DISP_DEB_BEN  from BENEVOLE WHERE ACTIVITE_BEN LIKE 'NULL' ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("activite"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("disp_date"));


    return model;
}

QSqlQueryModel * benevole::afficher_event()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select ID_EVENT , NOM_EVENT ,BENEVOLE, DATE_EVENT, TYPE  from EVENEMENT where BENEVOLE < 2 ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Benevole"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Type"));



    return model;
}
void participent::updateevnt(int val){
    QSqlQuery query2;
   query2.prepare("UPDATE EVENEMENT SET BENEVOLE = BENEVOLE + 1 WHERE BENEVOLE >= 0 AND ID_EVENT =:id2");
   query2.bindValue(":id2",val);
   query2.exec();
}
void participent::updatben(int val,QString act){
    QSqlQuery query2;
   query2.prepare("UPDATE BENEVOLE SET ACTIVITE_BEN = :act WHERE  ID_BEN =:id2");
   query2.bindValue(":id2",val);
    query2.bindValue(":act",act);
   query2.exec();
}
bool participent::ajouter_participent(int id_ben, int id_event,QString nomben,QString nomevent){
    QSqlQuery query;

    query.prepare("INSERT INTO PARTICIPATION (ID_PARTICIPATION, ID_EVENT, ID_BENEVOLE, BENE_NOM, EVENT_NOM) "
                  "VALUES (:id, :idevent ,:id_ben, :nom_ben ,:nom_event)");
    query.bindValue(":id",Getid_participent());
    query.bindValue(":idevent",id_event);
    query.bindValue(":id_ben",id_ben);
    query.bindValue(":nom_ben",nomben);
    query.bindValue(":nom_event",nomevent);
    updatben(id_ben,nomevent);
    updateevnt(id_event);
    return  query.exec(); //exec() tlanci requette lel serveur
}

QSqlQueryModel * participent::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *  from PARTICIPATION");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("id_event"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("id_ben"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom_ben"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nom_event"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("disp_date"));



    return model;
}

QSqlQueryModel * participent::rechercher(QString rech){
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM PARTICIPATION WHERE (ID_PARTICIPATION LIKE '%"+rech+"%' OR ID_EVENT LIKE '%"+rech+"%' OR ID_BENEVOLE LIKE '%"+rech+"%')");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("id_event"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("id_ben"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom_ben"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nom_event"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("disp_date"));

    return model;
}

QSqlQueryModel * participent::trier(int i){

    benevole R;
    QSqlQueryModel* model=new QSqlQueryModel();
    if(i==0)
        model= R.afficher();
    if(i==1)
             {
                 model->setQuery("SELECT * FROM PARTICIPATION ORDER BY ID_PARTICIPATION ASC");
             }
    else if (i==2)
             {
                 model->setQuery("SELECT * FROM PARTICIPATION ORDER BY ID_PARTICIPATION DESC");
             }

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("id_event"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("id_ben"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom_ben"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nom_event"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("disp_date"));

    return model;
}
int benevole::check(QString id ){//check mta3 certif


    QSqlQuery query("SELECT SCORE_BEN FROM BENEVOLE WHERE ID_BEN="+id);


    query.next();
    int score =query.value(0).toInt();


    return  score;
}
void participent::updatesup(int val2){
     QSqlQuery query2;
    query2.prepare("UPDATE EVENEMENT SET BENEVOLE = BENEVOLE -1 WHERE BENEVOLE >= 0 AND ID_EVENT =:id2");
    query2.bindValue(":id2",val2);
    query2.exec();
}
void participent::updatesupben(int val2){
     QSqlQuery query2;
    query2.prepare("UPDATE BENEVOLE SET ACTIVITE_BEN = 'NULL' WHERE  ID_BEN =:id2");
    query2.bindValue(":id2",val2);
    query2.exec();
}
bool participent::supprimer(int val , int val2,int val3)
{

    QSqlQuery query;

    query.prepare("DELETE FROM PARTICIPATION WHERE ID_PARTICIPATION =:id ");

    query.bindValue(":id",val);
    updatesup(val2);
    updatesupben(val3);
    return    query.exec();
}
