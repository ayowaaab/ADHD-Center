#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtDebug>
class Connexion
{
public:
    Connexion();
    bool createconnect();
};

#endif // CONNECTION_H
