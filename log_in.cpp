#include "log_in.h"
#include "mainwindow.h"
#include "ui_log_in.h"
#include <QFileInfo>
#include <QString>
#include "connexion.h"
#include <QtSerialPort/QSerialPort>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QObject>
#include <QtCore>


Log_in::Log_in(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Log_in)
{
    ui->setupUi(this);


    int ret=f.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< f.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<f.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";

    }
     QObject::connect(f.getserial(),SIGNAL(readyRead4()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).



}

Log_in::~Log_in()
{
    delete ui;
}

void Log_in::update_label4()
{
    data=f.read_from_arduino();

    qDebug() << "Received data:" << data.size() << data.data();
    QString str = QString::fromUtf8(data.constData());
    qDebug() << "Converted string:" << str << "Size:" << str.size();

    Connexion c;
    bool test =c.createconnect();

    if(str =="1" || str == "1\r\n" ){

            this->hide();
            MainWindow *m=new MainWindow();
            m->show();
     if(test){

            QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection Succeful.\n"
                                "Click cancel to exit"),QMessageBox::Cancel);
        //}else{
         //    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
           //          QObject::tr("connection Failed.\n"
             //                    "Click cancel to exit"),QMessageBox::Cancel);
         //}

    //}else
      //  QMessageBox::critical(this,"ERROR","Nom d'utilisateur\nOU\nMot de Passe\nincorrecte");

}
}
}


void Log_in::on_signin_clicked()
{
    QString user=ui->username->text();
    QString mdp=ui->password->text();
    Connexion c;
    bool test =c.createconnect();

    if(user=="ayoub" || mdp=="123"){
            this->hide();
            MainWindow *m=new MainWindow();
            m->show();

        if(test){

            QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection Succeful.\n"
                                "Click cancel to exit"),QMessageBox::Cancel);
        }else{
             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                     QObject::tr("connection Failed.\n"
                                 "Click cancel to exit"),QMessageBox::Cancel);
         }

    }else
        QMessageBox::critical(this,"ERROR","Nom d'utilisateur\nOU\nMot de Passe\nincorrecte");


}
