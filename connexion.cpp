#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::createconnect(){
    bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
/*db.setDatabaseName("projet_qt");
db.setUserName("lemsi");//inserer nom de l'utilisateur
db.setPassword("lemsi");//inserer mot de passe de cet utilisateur*/
db.setDatabaseName("doctor");
db.setUserName("SYSTEM");//inserer nom de l'utilisateur
db.setPassword("yyyy");
if (db.open())
test=true;

    return  test;
}
