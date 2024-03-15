#include "dialog.h"
#include "ui_dialog.h"
#include "smtp.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::Dialog(QString e,QString n,QString s,QString date,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    QString contenu="Vous n'avez pas encore paye votre tranche de la date "+date+"\n Veuillez la payer au plus tôt que possible";
    QString xx="Facture Non-Payer";
    ui->setupUi(this);


    ui->uname->setText("mariem.ellefi@esprit.tn");
    ui->passwd->setText("pzdudfagzzcizqow ");
    ui->passwd->setEchoMode(QLineEdit::Password);
    ui->recipient->setText(e);
    ui->recipient_n->setText(n);
    ui->recipient_s->setText(s);
    ui->subjectLineEdit->setText(xx);
    ui->message->setText("Cher client "+s+" "+n+",\n\n"+contenu+"\n\n"+"Cordialement,\n");

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_envoyer_dialog_clicked()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->passwd->text(), "smtp.gmail.com", 465);

    smtp->sendMail(ui->uname->text(), ui->recipient->text() , ui->subjectLineEdit->text() ,ui->message->toPlainText());

    /*if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );*/

}

