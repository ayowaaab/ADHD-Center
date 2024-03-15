#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "etudiant.h"
#include "evenement.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>

//***************** Aziz ****************

#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkAccessManager>

//***************** Mariem ****************
#include <QNetworkAccessManager>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "enfant.h"
#include "facture.h"
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <iostream>
#include <QValidator>
#include <QtPrintSupport/QPrintDialog>
#include <QFileDialog>
#include <QTextStream>
#include <QTextDocument>
#include<QSystemTrayIcon>
#include<QPrinter>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QtCharts>
#include <QFile>

//***************** achref ****************

#include <persone.h>
#include <task.h>
#include <QIntValidator>
#include <QProcess>
#include <QDesktopServices>
#include <QUrl>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QRgb>
#include <QPalette>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
QT_CHARTS_USE_NAMESPACE
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPainter>
#include <QTextDocument>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QFileDialog>
#include <QLabel>
#include <QPixmap>
#include <QSortFilterProxyModel>
#include <QSortFilterProxyModel>

//***************** Toujani ****************

#include "medecin.h"
#include <QMessageBox>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QSqlQueryModel>
#include <QVBoxLayout>
#include <QSqlTableModel>
#include <QIntValidator>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QTextTableCell>
#include <QTableWidget>
#include <QTextDocument>
#include "medicamant.h"
#include "consultation.h"

// ------------------------ Haithem -----------------------------

#include <QFile>
#include <QPrinter>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QtCharts>



/// ******************** 5idmet AYOUB ********************

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_etudiant->setModel(e.afficher());
    ui->tab_event->setModel(E.afficher());
    ui->table_enfant->setModel(ef.afficher_enfant());
    ui->table_facture->setModel(f.afficher_facture());
    //*************************integration arduino*******************************
 int ret=A.connect_arduino(); // lancer la connexion à arduino
switch(ret){
case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
    break;
case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
   break;
case(-1):qDebug() << "arduino is not available";
}
///  ------------------------------------------------------ Touja -------------------------------------------------------
    ui->lineEdit_ID_medecin->setMaxLength(10);
    ui->tableView_med->setModel(M.afficher());
    ui->comboBoxdelete->setModel(M.afficher());
    ui->comboBoxupdate->setModel(M.afficher());
    ui->comboBoxmed_consul->setModel(M.afficher());
    ui->comboBoxenfant_consul->setModel(ME.afficherenfant());
    ui->comboBoxmedeca_consul->setModel(ME.affichermedi());
    ui->lineEdit_qte_medic->setValidator(new QIntValidator(0,999999999,this));
    ui->tableView_medic->setModel(ME.affichermedi());
    ui->tableView_cons->setModel(CN.afficher_cons());
    ui->comboBoxmedeca_consul->addItem("NULL");

//houna lezem tzid condition
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label2()));

////------------------------------------------------------------------------------------------------------


////------------------------------------------------- Haithem --------------------------------------------


    //---------------------------ard------------------//
//houna lezem tzid condition
    // QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));


    //------------------------------------------------//
    popUp = new PopUp();
    ui->ben_tab_2->setModel(execb.afficher());
    ui->table_ben_part->setModel(execb.afficher_ben());
    ui->tab_activite->setModel(execb.afficher_event());
    ui->tab_particip->setModel(exepar.afficher());

     //-----------------------validation for inscription-------------------------//
        ui->idben_3->setValidator(new QIntValidator(0, 99, this));
        ui->tel_3->setValidator(new QIntValidator(0, 99999999, this));
        ui->score_3->setValidator(new QIntValidator(0, 60, this));
        ui->abs_3->setValidator(new QIntValidator(0, 10, this));

        ui->NOM_3->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
        ui->adress_3->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));

        ui->activite_3->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));

        QIntValidator *validator = new QIntValidator(ui->idben_3);
            ui->idben_3->setValidator(validator);

        QIntValidator *validato1r = new QIntValidator(ui->tel_3);
            ui->tel_3->setValidator(validato1r);
        QIntValidator *validator2 = new QIntValidator(ui->score_3);
            ui->score_3->setValidator(validator2);
        QIntValidator *validator3 = new QIntValidator(ui->abs_3);
            ui->abs_3->setValidator(validator3);

            //----------------disp------------//
            QRegExp R_date("(0[1-9]|[12][0-9]|3[01]{1,2})/(0[1-9]|[12]{1,2})/(19[0-9][0-9]|20[0-9][0-9])");
            QRegExpValidator *valida = new QRegExpValidator(R_date, this);
            ui->disp_3->setValidator(valida);
            ui->disp_4->setValidator(valida);
     //-----------------------validation for modificantion-------------------------//

            ui->tel_4->setValidator(new QIntValidator(0, 99999999, this));
            ui->score_4->setValidator(new QIntValidator(0, 60, this));
            ui->abs_4->setValidator(new QIntValidator(0, 10, this));

            ui->NOM_4->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
            ui->adress_4->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
            ui->disp_4->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
            ui->activite_4->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));


            QIntValidator *validato4r = new QIntValidator(ui->tel_4);
                ui->tel_4->setValidator(validato4r);
            QIntValidator *validator5 = new QIntValidator(ui->score_4);
                ui->score_4->setValidator(validator5);
            QIntValidator *validator6 = new QIntValidator(ui->abs_4);
                ui->abs_4->setValidator(validator6);

                    //------------------------Chart-----------------------------//
    int a=0,b=0,c=0;
    QSqlQuery query;
    query.prepare("SELECT * FROM PARTICIPATION");
    if(query.exec()){
        while (query.next()){
            QString type=query.value("EVENT_NOM").toString();
            if(type=="esprit"){a++;}
            else if(type=="party_twin"){b++;}
            else if(type=="halloween"){c++;}
        }
    }
        QBarSet *set0 = new QBarSet ("esprit");
        QBarSet *set1 = new QBarSet ("party_twin");
        QBarSet *set2 = new QBarSet ("halloween");
        *set0 << a <<b <<c  ;

        QBarSeries *series_ben = new QBarSeries();
        series_ben->append(set0);
        series_ben->append(set1);
        series_ben->append(set2);


        QChart *chart_ben = new QChart();
        chart_ben->addSeries(series_ben);
        chart_ben->setTitle("BarChart Event nb ");
        chart_ben->setAnimationOptions(QChart::SeriesAnimations);



        QStringList categories;
        categories << "esprit" << "party_twin" << "halloween"  ;
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart_ben->createDefaultAxes();
        chart_ben->setAxisX(axis, series_ben);

        QChartView *chartView_ben = new QChartView(chart_ben);
        chartView_ben->setParent(ui->plot);


////------------------------------------------------------------------------------------------------------








        QFile fichierx("C:/Users/ayoub/OneDrive/Documents/ADHD Center 2/produit.txt");
        if (fichierx.open(QIODevice::ReadOnly|QIODevice::Text)){
         QString text12;
         text12 =fichierx.readAll();
         fichierx.close();
         ui->nb_produit_stock->setText(text12);
        }
    ///---------- Chart Ya Rojla ----------------

    QSqlQuery qry,qry2;
                qry.prepare("select REPORTER from SEANCE ");
                qry2.prepare("select ANNULATION from SEANCE ");
                qry.exec();
                qry2.exec();

                int no=0,dec=0,noo=0,decc=0;

                while(qry.next()){
                   no=qry.value(0).toInt();
                   if(no!=0) noo=noo+no;
                }

                while(qry2.next()){
                    dec=qry2.value(0).toInt();
                    if (dec!=0) decc++;
                }


    QPieSeries *series = new QPieSeries();
    series->append("Rapporter", noo);
    series->append("Annuler", decc);
    series->setHoleSize(0.5);
    QPieSlice *slice = series->slices().at(1);
    QPieSlice *slice1 = series->slices().at(0);
    slice->setExploded();
    slice->setLabelVisible();
    slice1->setLabelVisible();

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTitle("Statistiques des Séance de Soutient");

    QChartView *view =new QChartView();
    view->setChart(chart);
    view->setParent(ui->horizontalFrame);






/*
    ui->le_nom->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->le_nom2->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->le_description->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->le_description2->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->le_type->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->le_type2->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->le_id->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
*/



    int money=0,fun=0,study=0;
    QSqlQuery query_E;
    query_E.prepare("select * from evenement");
    if(query_E.exec()){
    while(query_E.next()){
    int type=query_E.value("TYPE_EVENT").toInt();
    if(type==1){fun++;}
    else if (type==2){money++;}
     else if (type==3){study++;}
    }
    }

    QString money_string = QString::number(money);
    QString fun_string = QString::number(fun);
    QString study_string = QString::number(study);

    QPieSeries *seriesEvent=new QPieSeries();
    seriesEvent->setHoleSize(0.20);
    seriesEvent->append("money : "+money_string,money);
    seriesEvent->append("fun : "+fun_string,fun);
    seriesEvent->append("study : "+study_string,study);
    QChart *chartEvent=new QChart();
    chartEvent->addSeries(seriesEvent);
    chartEvent->setAnimationOptions(QChart::SeriesAnimations);
    chartEvent->setTitle("Les Evenements");
    chartEvent->setBackgroundVisible(true);

    QChartView *chartviewEvent=new QChartView(chartEvent);
    chartviewEvent->setChart(chartEvent);
    chartviewEvent->setParent(ui->label_stat);
    chartviewEvent->setFixedSize(300,450);
    ui->label_stat->update();

//************************    Achref   **********************

     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label1())); // permet de lancer

     //le slot update_label suite à la reception du signal readyRead (reception des données).
    m_originalModel = new QStandardItemModel(this);
    ui->l_cin->setValidator(new QIntValidator(0, 9999999, this));
    ui->table_persone->setModel(P.afficher(ui->find->text()));
    ui->treeView1->setModel(T.afficher(ui->find_task->text()));
    //contraint
    QIntValidator *valid_achref = new QIntValidator(ui->l_cin);
    ui->l_cin->setValidator(valid_achref);
    QIntValidator *validatorx = new QIntValidator(0, 9999, this);
    ui->l_salaire->setValidator(validatorx);
    ui->l_cin1->setValidator(validator);
    ui->l_salaire1->setValidator(validatorx);
    QRegularExpression emailRegex("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");
    QValidator *validator1 = new QRegularExpressionValidator(emailRegex,ui->l_email);
    ui->l_email->setValidator(validator1);
     ui->l_email1->setValidator(validator1);
    QRegExpValidator *validator21 = new QRegExpValidator(QRegExp("[a-zA-Z]+"), this);
    ui->l_nom->setValidator(validator21);
    ui->l_prenom->setValidator(validator21);
    ui->l_nom1->setValidator(validator21);
    ui->l_prenom1->setValidator(validator21);

    connect(ui->find_task, &QLineEdit::textChanged, [=](const QString& text) {
        QSqlQueryModel *model = T.afficher(text);
        ui->treeView1->setModel(model);
    });
    connect(ui->table_persone, &QTreeView::clicked, [=]() {
        ui->find->clear();

    });
    connect(ui->table_persone, &QTreeView::clicked, [=]() {
        ui->ggg12->setChecked(true);
    });

   timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(afficher_message()));
    timer->start(1000);
    buttonGroup->addButton(ui->trier);
    buttonGroup->addButton(ui->salaire);
    buttonGroup->addButton(ui->age);
     buttonGroup->addButton(ui->ggg12);
    buttonGroup->setExclusive(true);
    connect(ui->trier, &QCheckBox::toggled, this, &MainWindow::handleCheckBoxes);
    connect(ui->salaire, &QCheckBox::toggled, this, &MainWindow::handleCheckBoxes);
    connect(ui->age, &QCheckBox::toggled, this, &MainWindow::handleCheckBoxes);
    connect(ui->trier, &QCheckBox::stateChanged, this, &MainWindow::toggleTreeViewSorting);
    connect(ui->salaire, &QCheckBox::stateChanged, this, &MainWindow::slaireSorting);
      connect(ui->age, &QCheckBox::stateChanged, this, &MainWindow::ageSorting);

}

MainWindow::~MainWindow()
{
    delete ui;
}

///////////// 5IDMET AYOUB //////////////////////
void MainWindow::on_ajouter_clicked()
{
    QString commentaire=ui->Comment->text();
    QString nom_mat=ui->nom_mat->text();
    QString date=ui->date_ajout->text();
    int heureD=ui->heureD->text().toInt();
    int heureF=ui->heureF->text().toInt();
    int suiv=ui->suivi->text().toInt();
    int idE=ui->ide->text().toInt();
    etudiant e(nom_mat,commentaire,heureD,heureF,suiv,0,idE,0,date);

    bool test = e.ajouter();

    if(test){

        ui->tab_etudiant->setModel(e.afficher());
    }else{
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                QObject::tr("ajout non effectué.\n"
                            "Click cancel to exit"),QMessageBox::Cancel);
    }

}

void MainWindow::on_load_seance_clicked()
{
    int id=ui->id_update->text().toInt();
    QString xs=QString ::number(id);
    QSqlQuery qry;
    qry.prepare("SELECT * FROM seance WHERE ID_Seance="+xs);
    if(qry.exec())
    {
        while(qry.next()){

        ui->nom_mat_update->setText(qry.value(4).toString());
        ui->ide_update->setText(qry.value(8).toString());
        ui->suivi_update->setText(qry.value(5).toString());
        ui->heureD_update->setText(qry.value(1).toString());
        ui->heureF_update->setText(qry.value(2).toString());
        ui->id_update->setText(qry.value(0).toString());
        ui->Comment_update->setText(qry.value(3).toString());



        }
        }
}
void MainWindow::on_supprimer_clicked()
{
    QModelIndexList selectedIndexes = ui->tab_etudiant->selectionModel()->selectedIndexes();
       if (!selectedIndexes.isEmpty()) {
           int row = selectedIndexes.first().row();
           // Récupérez les données associées à cette ligne à partir du modèle de données du TableView
           QString id = ui->tab_etudiant->model()->index(row, 0).data().toString();
           // Supprimez la ligne du modèle de données du TableView
           ui->tab_etudiant->model()->removeRow(row);

           // Supprimez la ligne de la base de données en utilisant une requête SQL
           QSqlQuery query;
           query.prepare("DELETE FROM seance WHERE id_seance = ?");
           query.addBindValue(id);
           if (query.exec()) {
               // La suppression a réussi
               qDebug() << "Ligne supprimée de la base de données";
               ui->tab_etudiant->setModel(e.afficher());
           } else {
               // La suppression a échoué
               qDebug() << "Erreur lors de la suppression de la ligne dans la base de données";
               qDebug() << query.lastError().text();
           }
       } else {
           // Aucune ligne sélectionnée
           qDebug() << "Aucune ligne sélectionnée";
       }
}




void MainWindow::on_update_clicked(){
    int id=ui->id_update->text().toInt();
    QString commentaire=ui->Comment_update->text();
    QString nom_mat=ui->nom_mat_update->text();
    int heureD=ui->heureD_update->text().toInt();
    int heureF=ui->heureF_update->text().toInt();
    int suiv=ui->suivi_update->text().toInt();
    int idE=ui->ide_update->text().toInt();

    etudiant e(nom_mat,commentaire,heureD,heureF,suiv,0,idE,0,"");
    bool chercher=recherche(id);
    if(chercher){
    bool test=e.update(id);

    if(test){
        ui->tab_etudiant->setModel(e.afficher());
        QMessageBox::information(this,"Alerte","Update effectué");
    }else{
        QMessageBox::information(this,"Alerte","Update non effectué");
    }
    }
     else{QMessageBox::critical(this,"Alerte","id not found");}

}

bool MainWindow::recherche(int id){
    QSqlQuery query;
    QString idd=QString::number(id);
    query.prepare("select * from seance where id_seance=:id_seance");
            query.bindValue(":id_seance",idd);
            query.exec();
            if(query.next())return true;
            else return  false;
}


void MainWindow::on_rech_seance_textEdited(const QString &rech)
{

    if(rech == "")
        ui->tab_etudiant->setModel(e.afficher());
            else
        ui->tab_etudiant->setModel(e.afficher2(rech));
}


void MainWindow::on_tri_id_clicked()
{
    ui->tab_etudiant->setModel(e.affiche_tri("id_seance"));
}

void MainWindow::on_tri_mat_clicked()
{
    ui->tab_etudiant->setModel(e.affiche_tri("NOM_MATIER"));
}

void MainWindow::on_tri_heure_clicked()
{
    ui->tab_etudiant->setModel(e.affiche_tri("HEURE_DEBUT"));
}

void MainWindow::on_pdf_seance_clicked()
{

        QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->tab_etudiant->model()->rowCount();
                const int columnCount = ui->tab_etudiant->model()->columnCount();

                out <<  "<html>\n"
                    "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%1</title>\n").arg("strTitle")
                    <<  "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"

                   //     "<align='right'> " << datefich << "</align>"
                    "<center> <H1>Liste Des Seance De Soutient </H1></br></br></br></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                // headers
                out << "<thead><tr bgcolor=#3498DB> <th>Numero</th>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tab_etudiant->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tab_etudiant->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr> <td bkcolor=0"<<row+1<<"</td>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tab_etudiant->isColumnHidden(column)) {
                            QString data = ui->tab_etudiant->model()->data(ui->tab_etudiant->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table> </center>\n"
                    "</body>\n"
                    "</html>\n";

          QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
            if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

            QPrinter printer (QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);
            printer.setOutputFileName(fileName);

            QTextDocument doc;
            doc.setHtml(strStream);
            doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
            doc.print(&printer);

}



void MainWindow::on_all_Dec_clicked()
{
    int id=ui->ID_dec_line->text().toInt();
    QString date_decal=ui->date_dec_line->text();
    int heure_decal=ui->heure_dec_line->text().toInt();
    etudiant e(heure_decal,date_decal);
    bool chercher=recherche(id);
    if(chercher){
    bool test=e.decalage(id);

    if(test){
        ui->tab_etudiant->setModel(e.afficher());
        QMessageBox::information(this,"Alerte","Décalage effectué");
        id_decaler=id;

    }else{
        QMessageBox::information(this,"Alerte","Décalage non effectué");
    }
    }
     else{QMessageBox::critical(this,"Alerte","ID Not found");}

}





void MainWindow::on_all_Anuller_clicked()
{
    int id=ui->ID_annuler_line->text().toInt();
    etudiant e;
    bool chercher=recherche(id);
    if(chercher){
    bool test=e.annuler_methode(id);

    if(test){
        QMessageBox::information(this,"Alerte","Séance Annuler");
        ui->tab_etudiant->setModel(e.afficher());

    }else{
        QMessageBox::warning(this,"Alerte","Séance Déja Annuler");
    }
}
    else{QMessageBox::critical(this,"Alerte","id not found");}


}

/// ------------------- 5idmet aziz -------------------

void MainWindow::on_pushButton_2_clicked()
{
    QModelIndexList selectedIndexes = ui->tab_event->selectionModel()->selectedIndexes();
       if (!selectedIndexes.isEmpty()) {
           int row = selectedIndexes.first().row();
           // Récupérez les données associées à cette ligne à partir du modèle de données du TableView
           QString id = ui->tab_event->model()->index(row, 0).data().toString();
           // Supprimez la ligne du modèle de données du TableView
           ui->tab_event->model()->removeRow(row);

           // Supprimez la ligne de la base de données en utilisant une requête SQL
           QSqlQuery query;
           query.prepare("DELETE FROM evenement WHERE ID_EVENT = ?");
           query.addBindValue(id);
           if (query.exec()) {
               // La suppression a réussi
               qDebug() << "Ligne supprimée de la base de données";
               ui->tab_event->setModel(E.afficher());
           } else {
               // La suppression a échoué
               qDebug() << "Erreur lors de la suppression de la ligne dans la base de données";
               qDebug() << query.lastError().text();
           }
       } else {
           // Aucune ligne sélectionnée
           qDebug() << "Aucune ligne sélectionnée";
       }
}

void MainWindow::on_pb_ajouter_clicked(){



 /*   QString nom=ui->le_nom->text();
    QString description=ui->le_description->text();
    QString type=ui->le_type->text();
    QString date_event=ui->le_dateevent->text();

 evenement E(nom,description,type,date_event);
 bool test=E.ajouter();
 if (test)
         { //Actualiser
      ui->tab_event->setModel(E.afficher());
         QMessageBox:: information(nullptr, QObject::tr("OK"),
                                            QObject::tr("Ajout effectué\n"
                                                        "click cancel to exit."),QMessageBox::Cancel);

         ui->comboBox->setModel(E.afficher());
         ui->modifierIDEVEN->setModel(E.afficher());


         ui->le_id->clear();

             ui->le_id->clear();

              ui->le_nom->clear();
              ui->le_description->clear();
              ui->le_type->clear();
              ui->le_dateevent->clear();
              int money=0,fun=0,study=0;
              QSqlQuery query;
              query.prepare("select * from evenement");
              if(query.exec()){
              while(query.next()){
              QString type=query.value("type").toString();
              if(type=="fun"){fun++;}
              else if (type=="money"){money++;}
               else if (type=="study"){study++;}
              }
              }
              QString money_string = QString::number(money);
              QString fun_string = QString::number(fun);
               QString study_string = QString::number(study);

              QPieSeries *series=new QPieSeries();
              series->setHoleSize(0.20);
              series->append("money : "+money_string,money);
              series->append("fun : "+fun_string,fun);
              series->append("study : "+study_string,study);
              QChart *chart=new QChart();
              chart->addSeries(series);
              chart->setAnimationOptions(QChart::SeriesAnimations);
              chart->setTitle("les evenements");
              chart->setBackgroundVisible(true);


              QChartView *chartview=new QChartView(chart);
              chartview->setRenderHint(QPainter::Antialiasing);
              chartview->setParent(ui->label_stat);
              chartview->setMinimumSize(300,450);
              chartview->setMaximumSize(400,450);


         }
     else
         QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                               QObject::tr("id deja .\n"
                                           "click Cancel to exit."),QMessageBox::Cancel);*/
 }


void MainWindow::on_modifier_2_clicked()
{
    /*
    QString id=ui->modifierIDEVEN->currentText();
    QString nom=ui->le_nom2->text();
    QString description=ui->le_description2->text();
    QString type=ui->le_type2->text();
    QString date_event=ui->le_dateevent2->text();

    evenement E(id,nom,description,type,date_event);

            QSqlQuery query;
                if (ui->le_nom2->text().isEmpty())
                   {QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP nom !!!!") ;
                        QMessageBox::critical(0, qApp->tr("Modifier"),
                             qApp->tr("Probleme de modification"), QMessageBox::Cancel);
                     }
                   else if (ui->le_description2->text().isEmpty())
                      {
                          QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP description  !!!!") ;

                          QMessageBox::critical(0, qApp->tr("Modifier"),
                                          qApp->tr("Probleme de modification"), QMessageBox::Cancel);

                      }
                 else if (ui->le_type2->text().isEmpty())
                 {QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP type !!!!") ;
                      QMessageBox::critical(0, qApp->tr("Modifier"),
                           qApp->tr("Probleme de modification"), QMessageBox::Cancel);
      }
                 else if (ui->le_dateevent2->text().isEmpty())
                 {QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP date event !!!!") ;
                      QMessageBox::critical(0, qApp->tr("Modifier"),
                           qApp->tr("Probleme de modification"), QMessageBox::Cancel);
      }


 else {


            bool test=E.modifier();
            if(test)
            {
                ui->tab_event->setModel(E.afficher());
                QMessageBox::information(nullptr, QObject::tr("Modifier evenement"),
                            QObject::tr("evenement Modifier.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

                ui->comboBox->setModel(E.afficher());
                ui->modifierIDEVEN->setModel(E.afficher());
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Modifier evenement"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }

            ui->modifierIDEVEN->clear();

                ui->le_benevole2->clear();
                 ui->le_nom2->clear();
                 ui->le_description2->clear();
                 ui->le_type2->clear();
                 ui->le_dateevent2->clear();
}
*/
}



void MainWindow::on_valider1_clicked()
{
   /* {
        QString id=ui->modifierIDEVEN->currentText();
                  QSqlQuery query;
                  query.prepare("select * from evenement where id='"+id+"'");
                  if (query.exec())
                  {
                   while (query.next())
                   {
                      ui->le_benevole2->setText(query.value(1).toString());
                       ui->le_nom2->setText(query.value(2).toString());
                       ui->le_description2->setText(query.value(3).toString());

                       ui->le_type2->setText(query.value(4).toString());
                       ui->le_dateevent2->setText(query.value(5).toString());

                   }
                  }
}
*/
}


void MainWindow::on_pushButton_3_clicked()
{
     /*ui->modifierIDEVEN->clear();
     ui->le_benevole2->clear();
     ui->le_nom2->clear();
     ui->le_description2->clear();
     ui->le_type2->clear();
     ui->le_dateevent2->clear();*/
}


void MainWindow::on_Tribox_currentIndexChanged(const QString &arg1)
{
QString selectionvalue= ui->Tribox->currentText();
if (selectionvalue=="ID"){ui->tab_event->setModel(E.trid());}
else if (selectionvalue=="NOM"){ui->tab_event->setModel(E.trinom());}
else if (selectionvalue=="TYPE"){ui->tab_event->setModel(E.tritype());}
else if    (selectionvalue=="NON TRIER"){ui->tab_event->setModel(E.afficher());}
}


void MainWindow::on_recherche_textChanged(const QString &arg1){

    ui->tab_event->setModel(E.rechercher(arg1));

}

void MainWindow::on_pushButton_clicked(){

QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName("C:/Users/ayoub/OneDrive/Bureau/evenement.pdf");

        QTableView* tableView = ui->tab_event; // replace with the name of your QTableView

        // create a QTextDocument with the contents of the QTableView
        QTextDocument doc;
        QTextCursor cursor(&doc);
        doc.setPageSize(printer.pageRect().size());
           doc.setDocumentMargin(10.0);

        // insert the title in the middle
            QTextBlockFormat blockFormat;
            blockFormat.setAlignment(Qt::AlignCenter);
            cursor.insertBlock(blockFormat);
            QTextCharFormat titleFormat;
            titleFormat.setFontWeight(QFont::Thin);
            titleFormat.setFontPointSize(14);
            cursor.insertText("", titleFormat);

            // insert the image in the top left corner
            QImage image("C:/Users/azizh/OneDrive/Bureau/Clezzy_logo_shih.png"); // replace with the name and path of your image
            if (!image.isNull()) {
                QPixmap pixmap = QPixmap::fromImage(image);
                if (!pixmap.isNull()) {
                    pixmap = pixmap.scaled(QSize(200, 50), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    QTextImageFormat imageFormat;
                    imageFormat.setWidth(pixmap.width());
                    imageFormat.setHeight(pixmap.height());
                    imageFormat.setName("event.pdf");
                    cursor.movePosition(QTextCursor::Start);
                    cursor.insertImage(imageFormat);
                    doc.addResource(QTextDocument::ImageResource, QUrl("event.pdf"), QVariant(pixmap));
                }
            }

            // insert the table
            cursor.insertBlock();
            QTextBlockFormat tableBlockFormat;
                tableBlockFormat.setAlignment(Qt::AlignCenter);
                cursor.insertBlock(tableBlockFormat);
        cursor.insertText("Les evenements\n\n");
        int rows = tableView->model()->rowCount();
        int columns = tableView->model()->columnCount();
        QTableWidget table(rows + 1, columns);
        table.setHorizontalHeaderLabels(QStringList() << "id" << "nom" << "benevole" << "description" << "type" << "date"); // replace with your column headers
        for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                table.setItem(row + 1, column, new QTableWidgetItem(tableView->model()->data(tableView->model()->index(row, column)).toString()));
            }
        }
        QTextTableFormat tableFormat;
        tableFormat.setHeaderRowCount(1);
        QTextTable* textTable = cursor.insertTable(rows + 1, columns, tableFormat);

        for (int column = 0; column < columns; column++) {
            QTextTableCell headerCell = textTable->cellAt(0, column);
            QTextCursor headerCursor = headerCell.firstCursorPosition();
            headerCursor.insertText(table.horizontalHeaderItem(column)->text());
        }

        QTextCharFormat cellFormat;
        cellFormat.setFont(QFont("Helvetica", 10, QFont::Bold));
        for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                QTextTableCell cell = textTable->cellAt(row + 1, column);
                cell.setFormat(cellFormat);
                cell.firstCursorPosition().insertText(tableView->model()->data(tableView->model()->index(row, column)).toString());
            }
        }
        //la date ou le pdf a ete generer
        cursor.movePosition(QTextCursor::PreviousBlock);
            QTextBlockFormat dateBlockFormat;
            dateBlockFormat.setAlignment(Qt::AlignRight);
            cursor.insertBlock(dateBlockFormat);
            QTextCharFormat dateFormat;
            dateFormat.setFontPointSize(8);
            cursor.insertText("Generated on " + QDate::currentDate().toString("dd/MM/yyyy"), dateFormat);

        // print the QTextDocument to the PDF printer
        QPainter painter(&printer);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);
        doc.setPageSize(printer.pageRect().size());
        doc.drawContents(&painter);





        QMessageBox::information(nullptr,QObject::tr("pdf"),
        QObject::tr("pdf is printed.\n"
                    "click cancel and exit"),QMessageBox::Cancel);

}



void MainWindow::on_stats_clicked()
{


}



void MainWindow::on_label_stat_linkActivated(const QString &link)
{

}

void MainWindow::on_recherche_selectionChanged()
{

}

void MainWindow::on_SMS_clicked()
{
      QNetworkAccessManager * manager = new QNetworkAccessManager(this);
      QUrl url("https://ACf660a291d5dfe56deebefc4df0a8030c:28f876c33c1e32b4aca098350137fabf@api.twilio.com/2010-04-01/Accounts/ACf660a291d5dfe56deebefc4df0a8030c/Messages.json");
            QNetworkRequest request(url);
           request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
            QUrlQuery params;
            params.addQueryItem("From", "+15075026412");
            params.addQueryItem("To",ui->numero->text() );//"+21652225446"
            params.addQueryItem("Body", ui->message_2->toPlainText());
           // params.addQueryItem("Body", "test");

            // etc

            connect(manager, SIGNAL(finished(QNetworkReply )), this, SLOT(replyFinished(QNetworkReply)));
            manager->post(request, params.query().toUtf8());
            QMessageBox::information(this, tr("SMS envoyé"), tr("SMS envoyé"));
}


void MainWindow::replyFinished(QNetworkReply* reply)
{

        QByteArray buffer = reply->readAll();
        qDebug() << buffer;
        QJsonDocument jsonDoc(QJsonDocument::fromJson(buffer));
        QJsonObject jsonReply = jsonDoc.object();
        QJsonObject response = jsonReply["response"].toObject();
        QJsonArray  data     = jsonReply["data"].toArray();
        qDebug() << data;
        qDebug() << response;

}



void MainWindow::on_pushButton_4_clicked()
{
QString nom=ui->nom->text();
QString prenom=ui->prenom->text();
QString date=ui->date_naissance->text();
int id=ui->date_naissance_2->text().toInt();
int statut=ui->statut_produit->isChecked();
QString adresse=ui->adresse_mail_parent->text();
enfant e(id,statut,nom,prenom,adresse,date);

QFile filex("produit_quantité");
if(ui->statut_produit->isChecked())
{
        QFile fichier("C:/Users/ayoub/OneDrive/Documents/ADHD Center 2/produit.txt");
            if (fichier.open(QIODevice::ReadOnly|QIODevice::Text)){
             QString text;
             text =fichier.readAll();
             fichier.close();

            // Création d'un objet QFile
            QFile file("C:/Users/ayoub/OneDrive/Documents/ADHD Center 2/produit.txt");
            // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
                return;

            // Création d'un objet QTextStream à partir de notre objet QFile
            QTextStream flux(&file);
            // On choisit le codec correspondant au jeu de caractères que l'on souhaite ; ici, UTF-8
            flux.setCodec("UTF-8");
            // Écriture des différentes lignes dans le fichier
            int a=text.toUInt();
            a=a-1;

            flux << a << endl;
            QString xs=QString::number(a);
            ui->nb_produit_stock->setText(xs);
}
}

    bool test=e.ajout_enfant();


if(test)
   {
       QMessageBox::information(nullptr, QObject::tr("Succes"),
                                QObject::tr("Ajout effecté successfully\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
       ui->table_enfant->setModel(e.afficher_enfant());
   }
   else
   {
       QMessageBox::critical(nullptr, QObject::tr("Not good at all"),
                                QObject::tr("Ajout non effecté Error.\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
   }

}



//********************* Achref *************************
void MainWindow::readUID(Arduino* arduino)
{
    data = arduino->read_from_arduino();
    str = QString(data).trimmed();
    qDebug() << str;
    if (str.length()<2) {
        return;
    }
else{
        QString ky=str;
    QSqlQuery query;
    query.prepare("SELECT * FROM persone WHERE key=:key");
    query.bindValue(":key",ky);

    if (query.exec()) {
        if (query.next()) {
            A.write_to_arduino("0");
            qDebug() << "good";
            return;
        } else {
            QMessageBox msgBox;
            msgBox.setText("The key does not exist in the database. Would you like to add it?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::Yes);
            int reply = msgBox.exec();
            if (reply == QMessageBox::Yes) {
                // Get list of cins from database
                QSqlQuery cinQuery;
                cinQuery.prepare("SELECT cin FROM persone");
                if (!cinQuery.exec()) {
                    qWarning() << "Failed to get list of cins from database";
                    return;
                }

                // Create list of cins
                QStringList cinList;
                while (cinQuery.next()) {
                    QString cin = cinQuery.value(0).toString();
                    cinList.append(cin);
                }

                // Ask user to select cin from list
                bool ok;
                QString cin = QInputDialog::getItem(this, "Select CIN", "Please select the CIN for the record you want to update:", cinList, 0, false, &ok);
                if (ok && !cin.isEmpty()) {
                    QSqlQuery updateQuery;
                    updateQuery.prepare("UPDATE persone SET key=:key WHERE cin=:cin");
                    updateQuery.bindValue(":key", ky);
                    updateQuery.bindValue(":cin", cin);
                    if (updateQuery.exec()) {
                        qDebug() << "Updated key for CIN " << cin;
                    } else {
                        qWarning() << "Failed to update key for CIN " << cin;
                    }
                }
            }
            //
        }
    }
}
}
void MainWindow::update_label1()
{
    if(ca==1){
   readUID(&A);
    }
}
void MainWindow::updateTask(int id, const QString &com)
{

    QSqlQuery query;
    query.prepare("UPDATE TASK SET COM1 = COALESCE(NULLIF(COM1, ''), :com), "
                  "COM2 = CASE WHEN COM1 IS NOT NULL THEN COALESCE(NULLIF(COM2, ''), :com) ELSE COM2 END, "
                  "COM3 = CASE WHEN COM1 IS NOT NULL AND COM2 IS NOT NULL THEN COALESCE(NULLIF(COM3, ''), :com) ELSE COM3 END "
                  "WHERE ID_TASK = :id");
    query.bindValue(":id", id);
    query.bindValue(":com", com);
    if (!query.exec()) {
        qWarning() << "Failed to update task:" ;
        return;
    }
}


void MainWindow::handleCheckBoxes(bool checked)
{

    QCheckBox *senderCheckBox = qobject_cast<QCheckBox*>(sender());

    if (checked)
    {
        for (QAbstractButton *button : buttonGroup->buttons())
        {
            QCheckBox *checkBox = qobject_cast<QCheckBox*>(button);
            if (checkBox != senderCheckBox)
            {
                checkBox->setChecked(false);
            }
        }

    }
}
void MainWindow::sort_age()
{

    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
      proxyModel->setSourceModel(ui->table_persone->model());
      proxyModel->setSortRole(Qt::DisplayRole);
      proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
      proxyModel->setSortLocaleAware(true);
      proxyModel->setSortCaseSensitivity(Qt::CaseSensitive);
      proxyModel->sort(5, Qt::DescendingOrder);
      ui->table_persone->setModel(proxyModel);
}
void MainWindow::sortTreeViewBySalary()
{

    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
      proxyModel->setSourceModel(ui->table_persone->model());
      proxyModel->setSortRole(Qt::DisplayRole);
      proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
      proxyModel->setSortLocaleAware(true);
      proxyModel->setSortCaseSensitivity(Qt::CaseSensitive);
      proxyModel->sort(4, Qt::DescendingOrder);
      ui->table_persone->setModel(proxyModel);
}

void MainWindow::toggleTreeViewSorting(int state) {
    if (state == Qt::Checked) {
     triertreeView();

    } else {
         ui->table_persone->setModel(P.afficher(ui->find->text()));
    }
}
void MainWindow::slaireSorting(int state) {
    if (state == Qt::Checked) {
        sortTreeViewBySalary();

    } else {
         ui->table_persone->setModel(P.afficher(ui->find->text()));
    }
}
void MainWindow::ageSorting(int state) {
    if (state == Qt::Checked) {

      sort_age();

    } else {
         ui->table_persone->setModel(P.afficher(ui->find->text()));
    }
}

void MainWindow::triertreeView()
{
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(ui->table_persone->model());
    proxyModel->setSortRole(Qt::DisplayRole);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setSortLocaleAware(true);
    proxyModel->sort(1, Qt::AscendingOrder);
    ui->table_persone->setModel(proxyModel);

}


void MainWindow::displayImageFromDatabase()
{

    QString cin = login;
    QSqlQuery query;
    query.prepare("SELECT IMG FROM PERSONE WHERE CIN = :cin");
    query.bindValue(":cin", cin);

    if (query.exec() && query.next()) {
       imgg = query.value(0).toByteArray();
        QPixmap pixmap;
        pixmap.loadFromData(imgg);
    } else {
        qDebug() << "Error fetching image data from database";
    }
}

void MainWindow::uploadImage()
{

       imagePath = QFileDialog::getOpenFileName(this, tr("Select Image"), "", tr("Images (*.png *.jpg *.bmp)"));
       QFile file(imagePath);
       if (!file.open(QIODevice::ReadOnly)) {
           qDebug() << "Failed to open file";
           return;
       }
       imageBytes = file.readAll();
       file.close();
}

void MainWindow::afficher_message(){
    QSqlQuery query;
    query.prepare("SELECT NOM, MESSAGE, IMG FROM CHAT");

    if(query.exec())
    {
        ui->chat_box->clear();
        while (query.next())
        {
            QString nom = query.value(0).toString();
            QString message = query.value(1).toString();
            QByteArray imgData = query.value(2).toByteArray();
            QPixmap pixmap;

            if(!imgData.isEmpty())
            {
                pixmap.loadFromData(imgData);
            }

            QListWidgetItem* item = new QListWidgetItem(nom + ": " + message, ui->chat_box);
            item->setIcon(QIcon(pixmap));
            ui->chat_box->addItem(item);
             ui->chat_box->setIconSize(QSize(50, 50));
        }
    }
}
void MainWindow::send_message(){
    QSqlQuery query;
    query.exec("SELECT MAX(ID) FROM CHAT");
    query.next();
    int lastId = query.value(0).toInt();
    int newId = lastId + 1;

    query.prepare("INSERT INTO CHAT (ID, NOM, MESSAGE, IMG) VALUES (:id, :nom, :message, :img)");
    query.bindValue(":id", newId);
    query.bindValue(":nom", name);
    query.bindValue(":message", ui->message->text());
    query.bindValue(":img", imgg);
    if(query.exec()) {
        qDebug() << "Data inserted successfully";
    }
}
void MainWindow::update_id(){
    QSqlQuery query;
       QString queryString = "SELECT ROWID, ID FROM PERSONE";
       if (!query.exec(queryString)) {

           return;
       }
       int row = 0;
       while (query.next()) {
           QSqlRecord record = query.record();
           QString rowid = record.value("ROWID").toString();
           QString id = QString::number(row);
           QString updateString = "UPDATE PERSONE SET ID=:id WHERE ROWID=:rowid";
           QSqlQuery updateQuery;
           updateQuery.prepare(updateString);
           updateQuery.bindValue(":id", id);
           updateQuery.bindValue(":rowid", rowid);
           if (!updateQuery.exec()) {

               return;
           }
           row++;
       }
}
void  MainWindow::update_id_task(){
    QSqlQuery query;
       QString queryString = "SELECT ROWID, ID FROM TASK";
       if (!query.exec(queryString)) {

           return;
       }
       int row = 0;
       while (query.next()) {
           QSqlRecord record = query.record();
           QString rowid = record.value("ROWID").toString();
           QString id = QString::number(row);
           QString updateString = "UPDATE TASK SET ID=:id WHERE ROWID=:rowid";
           QSqlQuery updateQuery;
           updateQuery.prepare(updateString);
           updateQuery.bindValue(":id", id);
           updateQuery.bindValue(":rowid", rowid);
           if (!updateQuery.exec()) {

               return;
           }
           row++;
       }
}
QModelIndex MainWindow::getSelectedIndex(QTreeView *treeView)
{
    QModelIndex selectedIndex = treeView->currentIndex();

    if (!selectedIndex.isValid()) {
        qDebug() << "No row selected.";
        return QModelIndex();
    }

    return selectedIndex;
}
void MainWindow::generatePDF() {
    update_id();
    QModelIndex selectedIndex = getSelectedIndex(ui->table_persone);
    if (!selectedIndex.isValid()) {
        return;
    }

    int row = selectedIndex.row();
    QString cin,firstName, lastName,birthday,metier,salaire , experience,contraint,email;

        QSqlQuery query;
        query.prepare("SELECT CIN,NOM,PRENOM,BIRTHDAY,METIER,SALAIRE,EXPERIENCE,CONTRAINT,EMAIL FROM persone WHERE id=:id");
        query.bindValue(":id",row);
        if (!query.exec() || !query.first()) {
            qDebug() << "Database query error.";
            return;
        }
        cin=query.value(0).toString();
        firstName = query.value(1).toString();
        lastName = query.value(2).toString();
        birthday= query.value(3).toString();
        metier= query.value(4).toString();
        salaire= query.value(5).toString();
        experience= query.value(6).toString();
        contraint= query.value(7).toString();
        email=query.value(8).toString();
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("example.pdf");
        QPainter painter(&printer);

        painter.setFont(QFont("Arial", 20, QFont::Bold));
           painter.drawText(QRectF(0, 0, printer.width(), 50), Qt::AlignCenter, "Contrat de Travail");
           painter.setFont(QFont("Arial", 14));
           QRectF textRect(0, 50, printer.width(), printer.height()-500);
           painter.drawText(textRect, Qt::AlignCenter, QString("Dans le cadre de cet emploi, %1 %2 ,de cin %3 né le %4,\n \n"
                                                               "avec %5 ans d'expérience dans le domaine, recevra un salaire de %6 dollars \n \n"
                                                               "par mois. Il devra fournir une adresse e-mail valide (%7) pour les communications\n \n"
                                                               " relatives à son travail.\n \n").arg(firstName,lastName,cin,birthday,experience,salaire,email).arg(cin,firstName,lastName,birthday,metier,salaire,experience));

           QImage image(":/sign.png");
           QRectF targetRect(0, 500, 200, 200);
           painter.drawImage(targetRect, image);

           QString filename = "./example.pdf";
                   QUrl url = QUrl::fromLocalFile(filename);
                   QDesktopServices::openUrl(url);

}


void MainWindow::openChartWindow() {
    QSqlQuery query;
      QPieSeries *series = new QPieSeries();
    int num=0;
    query.prepare("SELECT COUNT(*) FROM persone WHERE  metier= 'Professeur'");
    if (query.exec() && query.next()) {
       num = query.value(0).toInt();
    }
    series->append("Professeur",num);
    query.prepare("SELECT COUNT(*) FROM persone WHERE  metier= 'un garde'");
    if (query.exec() && query.next()) {
        num= query.value(0).toInt();
    }
     series->append("un garde",num);
    query.prepare("SELECT COUNT(*) FROM persone WHERE  metier= 'nettoyeur'");
    if (query.exec() && query.next()) {
       num = query.value(0).toInt();
    }
    series->append("nettoyeur",num);
    query.prepare("SELECT COUNT(*) FROM persone WHERE  metier= 'administrateur'");
    if (query.exec() && query.next()) {
        num = query.value(0).toInt();
    }
    series->append("administrateur",num);
    query.prepare("SELECT COUNT(*) FROM persone WHERE  metier= 'autre'");
    if (query.exec() && query.next()) {
        num = query.value(0).toInt();
    }
    series->append("autre",num);

    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 2));
    slice1->setBrush(Qt::green);

    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelVisible();
    QPieSlice *slice3 = series->slices().at(3);
    slice3->setLabelVisible();
    QPieSlice *slice4 = series->slices().at(4);
    slice4->setLabelVisible();

    QChart *chart = new QChart();

    chart->addSeries(series);
    chart->setTitle("resource hummane");
    chart->legend()->hide();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow *chartWindow = new QMainWindow();
    chartWindow->setCentralWidget(chartView);
    chartWindow->resize(420, 300);
    chartWindow->show();
}

void MainWindow::on_pushButton_11_clicked()
{

    int cin=ui->l_cin->text().toInt();
    QString nom=ui->l_nom->text();
     QString prenom=ui->l_prenom->text();
      QString sex=ui->l_sex->currentText();
      QDate date = ui->l_date->date();
      QString datex = date.toString("yyyy-MM-dd");
        QString email=ui->l_email->text();
         QString experience=ui->l_experience->currentText();
          QString contraint=ui->l_contraint->currentText();
           QString salaire=ui->l_salaire->text();
           QString metier=ui->l_metier->currentText();
           persone P(cin,nom,prenom,datex,sex,metier,email,experience, contraint ,salaire);
           test=P.ajouter(imageBytes);
           if(test){
               ui->table_persone->setModel(P.afficher(ui->find->text()));
               QMessageBox::information(nullptr, QObject::tr("AJOUTER"),
                           QObject::tr("ajouter successful.\n"
                                       "Click Cancel to exit."), QMessageBox::Ok);
           }
           else{
               QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                           QObject::tr("ajouter failed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           }
}





void MainWindow::on_modifier_clicked()
{
    update_id();
    QModelIndex selectedIndex = getSelectedIndex(ui->table_persone);
    if (!selectedIndex.isValid()) {
        return;
    }

    int row = selectedIndex.row();
    QSqlQuery query;
    query.prepare("SELECT cin FROM persone WHERE id=:id");
    query.bindValue(":id",row);
    if (!query.exec()) {
            qDebug() << "Failed to execute query";
            return;
        }
     int c;
        while (query.next()) {
           c= query.value("CIN").toInt();
        }
  P.set_cin(c);
  P.set_nom(ui->l_nom1->text());
  P.set_prenom(ui->l_prenom1->text());
  P.set_date(ui->l_date1->text());
  P.set_email(ui->l_email1->text());
  P.set_metier(ui->l_metier1->currentText());
  P.set_sex(ui->l_sex1->currentText());
  P.set_experience(ui->l_experience1->currentText());
  P.set_contraint(ui->l_contrain1->currentText());
  P.set_salaire(ui->l_salaire1->text());
  test=P.modifier();
  if(test){
      ui->table_persone->setModel(P.afficher(ui->find->text()));
      QMessageBox::information(nullptr, QObject::tr("MODIFIER"),
                  QObject::tr("modifier successful.\n"
                              "Click ok to exit."), QMessageBox::Ok);
  }
  else{
      QMessageBox::critical(nullptr, QObject::tr("MODIFIER"),
                  QObject::tr("modifier failed.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

}

void MainWindow::on_persone0_clicked()
{
  ui->Widget_perso->setCurrentIndex(2);
}



void MainWindow::on_ajouter1_clicked()
{
    ui->Widget_perso->setCurrentIndex(1);
}


void MainWindow::on_afficher1_clicked()
{
    ui->Widget_perso->setCurrentIndex(2);
}

void MainWindow::on_persone1_clicked()
{
    ui->Widget_perso->setCurrentIndex(2);
}

void MainWindow::on_modifier1_clicked()
{    update_id();
     QModelIndex selectedIndex = getSelectedIndex(ui->table_persone);
     if (!selectedIndex.isValid()) {
         return;
     }
     int row = selectedIndex.row();
     QSqlQuery query;
     query.prepare("SELECT cin FROM persone WHERE id=:id");
     query.bindValue(":id",row);
     if (!query.exec()) {
             qDebug() << "Failed to execute query";
             return;
         }
      int c;
         while (query.next()) {
            c= query.value("CIN").toInt();
         }
             query.prepare("SELECT nom,prenom,birthday,email,metier,SALAIRE FROM persone where cin = :cin");
             query.bindValue(":cin",c);
              if (query.exec() && query.next()) {
                  QString value = QString::number(c);
                  ui->l_cin1->setText(value);
                  value = query.value(0).toString();
                  ui->l_nom1->setText(value);
                  value = query.value(1).toString();
                  ui->l_prenom1->setText(value);
                  value = query.value(2).toString();
                  QDate date = QDate::fromString(value, "yyyy-MM-dd");
                  ui->l_date1->setDate(date);
                  value = query.value(3).toString();
                  ui->l_email1->setText(value);
                  value = query.value(4).toString();
                  ui->l_metier1->setCurrentText(value);
                  int number =query.value(5).toInt();
                  ui->l_salaire1->setText(QString::number(number));
              }
    ui->Widget_perso->setCurrentIndex(3);
}

void MainWindow::on_supprimer1_clicked()
{
    update_id();
    QModelIndex selectedIndex = getSelectedIndex(ui->table_persone);
    if (!selectedIndex.isValid()) {
        return;
    }

    int row = selectedIndex.row();
    QSqlQuery query;
    query.prepare("SELECT cin FROM persone WHERE id=:id");
    query.bindValue(":id",row);
    if (!query.exec()) {
            qDebug() << "Failed to execute query";
            return;
        }
     int c;
        while (query.next()) {
           c= query.value("CIN").toInt();
        }

    P.set_cin(c);
    test=P.supprimer(P.get_cin());
    if(test){
        ui->table_persone->setModel(P.afficher(ui->find->text()));
        QMessageBox::information(nullptr, QObject::tr("SUPPRIMER"),
                    QObject::tr("supprimer successful.\n"
                                "Click Cancel to exit."), QMessageBox::Ok);
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("SUPPRIMER"),
                    QObject::tr("supprimer failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
}





void MainWindow::on_supprimer3_clicked()
{
    ui->Widget_perso->setCurrentIndex(4);
}



void MainWindow::on_persone2_clicked()
{
 ui->Widget_perso->setCurrentIndex(2);
}



void MainWindow::on_persone3_clicked()
{
    ui->Widget_perso->setCurrentIndex(2);
}


void MainWindow::on_stat0_clicked()
{
  //stat();
    openChartWindow();
}

void MainWindow::on_Bfind_clicked()
{
generatePDF();

}
void MainWindow::on_find_textChanged()
{
    QString nom = ui->find->text();
    QSqlQueryModel *filteredModel = P.afficher(nom);
    ui->table_persone->setModel(filteredModel);
}



void MainWindow::on_add_task_clicked()
{
    update_id();
    QModelIndex selectedIndex = getSelectedIndex(ui->table_persone);
    if (!selectedIndex.isValid()) {
        return;
    }

    int row = selectedIndex.row();
    QSqlQuery query;
    query.prepare("SELECT cin FROM persone WHERE id=:id");
    query.bindValue(":id",row);
    if (!query.exec()) {
            qDebug() << "Failed to execute query";
            return;
        }
     int c;
        while (query.next()) {
           c= query.value("CIN").toInt();
        }
    QMessageBox::information(nullptr, QObject::tr("AJOUTER"),
                QObject::tr("ajouter successful.\n"
                            "Click ok to exit.").arg(c), QMessageBox::Ok);

    query.prepare("INSERT INTO task (cin_pers,date_limite,description) "
                  "VALUES (:cin_pers,:date_limite,:description)");
    query.bindValue(":cin_pers",c);
    query.bindValue(":date_limite",ui->date_l->date());
     query.bindValue(":description",ui->description->toPlainText());
      query.exec();
}

void MainWindow::on_select_per_clicked()
{
    update_id();
    QModelIndex selectedIndex = getSelectedIndex(ui->table_persone);
    if (!selectedIndex.isValid()) {
        return;
    }
     ui->Widget_perso->setCurrentIndex(5);
}



void MainWindow::on_persone5_clicked()
{
    ui->Widget_perso->setCurrentIndex(2);
}



void MainWindow::on_task0_clicked()
{
    ui->treeView1->setModel(T.afficher(ui->find_task->text()));
    ui->Widget_perso->setCurrentIndex(6);
}

void MainWindow::on_statestique1_clicked()
{
    openChartWindow();
}

void MainWindow::on_tasks1_clicked()
{    ui->treeView1->setModel(T.afficher(ui->find_task->text()));
     ui->Widget_perso->setCurrentIndex(6);
}

void MainWindow::on_stat2_clicked()
{
   openChartWindow();
}

void MainWindow::on_task2_clicked()
{ ui->treeView1->setModel(T.afficher(ui->find_task->text()));
  ui->Widget_perso->setCurrentIndex(6);
}

void MainWindow::on_stat3_clicked()
{
    openChartWindow();
}

void MainWindow::on_task3_clicked()
{  ui->treeView1->setModel(T.afficher(ui->find_task->text()));
   ui->Widget_perso->setCurrentIndex(6);
}


void MainWindow::on_supp_task_clicked()
{
update_id_task();
QModelIndex selectedIndex = getSelectedIndex(ui->treeView1);
if (!selectedIndex.isValid()) {
    return;
}

int row = selectedIndex.row();
QSqlQuery query;
query.prepare("SELECT id_task FROM task WHERE id=:id");
query.bindValue(":id",row);
if (!query.exec()) {
        qDebug() << "Failed to execute query";
        return;
    }
 int c;
    while (query.next()) {
       c= query.value("id").toInt();
    }

test=T.delete_task(c);
if(test){
   ui->treeView1->setModel(T.afficher(ui->find_task->text()));
    QMessageBox::information(nullptr, QObject::tr("SUPPRIMER"),
                QObject::tr("supprimer successful.\n"
                            "Click Cancel to exit."), QMessageBox::Ok);
}
else{
    QMessageBox::critical(nullptr, QObject::tr("SUPPRIMER"),
                QObject::tr("supprimer failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
}

void MainWindow::on_modifier_task_clicked()
{
        update_id_task();
        QModelIndex selectedIndex = getSelectedIndex(ui->treeView1);
        if (!selectedIndex.isValid()) {
            return;
        }
       ui->Widget_perso->setCurrentIndex(4);
}

void MainWindow::on_mod_task_clicked()
{
    QModelIndex selectedIndex = getSelectedIndex(ui->treeView1);
    if (!selectedIndex.isValid()) {
        return;
    }

    int row = selectedIndex.row();
  T.set_date(ui->mod_date->date());
  T.set_disc(ui->mod_disc->toPlainText());
  test=T.mod_task(row);
  ui->treeView1->setModel(T.afficher(ui->find_task->text()));
  if(test){
      ui->table_persone->setModel(P.afficher(ui->find->text()));
      QMessageBox::information(nullptr, QObject::tr("MODIFIER"),
                  QObject::tr("modifier successful.\n"
                              "Click ok to exit.").arg(row), QMessageBox::Ok);
  }
  else{
      QMessageBox::critical(nullptr, QObject::tr("MODIFIER"),
      QObject::tr("modifier failed.\n"
      "Click Cancel to exit."), QMessageBox::Cancel);


}

}

void MainWindow::on_persone4_clicked()
{
  ui->Widget_perso->setCurrentIndex(2);
}

void MainWindow::on_pushButton_16_clicked()
{
    openChartWindow();
}

void MainWindow::on_task4_clicked()
{ ui->treeView1->setModel(T.afficher(ui->find_task->text()));
   ui->Widget_perso->setCurrentIndex(6);
}


void MainWindow::on_pushButton_15_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM PERSONE WHERE CIN=:cin AND NOM=:nom");
    query.bindValue(":cin",ui->password->text().toUInt());
    query.bindValue(":nom",ui->user_name->text());
    if (!query.exec()) {
        qDebug() << "Failed to execute query.";
        return;
    }

    if (query.exec() && query.next()) {
          ui->treeView1->setModel(T.afficher(ui->find_task->text()));
        login=ui->password->text();
        name=ui->user_name->text();
        QSqlQuery query;
        query.prepare("SELECT IMG,metier FROM persone WHERE cin=:cin");
        query.bindValue(":cin",login);
        query.exec();
        QString fg;
        if (query.next()) {
            QByteArray imageData = query.value(0).toByteArray();
             fg=query.value(1).toString();
            QPixmap pixmap;
               pixmap.loadFromData(imageData);
               pixmap = pixmap.scaled(QSize(71, 71), Qt::KeepAspectRatio, Qt::SmoothTransformation);
               ui->profile0->setPixmap(pixmap);
               ui->profile->setPixmap(pixmap);
               ui->profile1->setPixmap(pixmap);
               ui->profile2->setPixmap(pixmap);
               ui->profile3->setPixmap(pixmap);
               ui->profile4->setPixmap(pixmap);
               ui->profile5->setPixmap(pixmap);
               ui->profile6->setPixmap(pixmap);
               ui->profile7->setPixmap(pixmap);


        }

        if(fg=="administrateur"){

            ui->Widget_perso->setCurrentIndex(2);
            ca=1;
        }
        else{
             ui->Widget_perso->setCurrentIndex(7);
             afficher_message();

             ui->modifier_task->setEnabled(false);
             ui->persone6->setEnabled(false);
             ui->stat6->setEnabled(false);
             ui->persone7->setEnabled(false);
             ui->stat7->setEnabled(false);
             ui->supp_task->setEnabled(false);
             ui->persone5->setEnabled(false);
             ui->statestique5->setEnabled(false);
             ca=1;
        }
    } else {
        qDebug() << "Incorrect username or password.";
    }
}



void MainWindow::on_send_clicked()
{   displayImageFromDatabase();
    send_message();
    afficher_message();

}


void MainWindow::on_up_img_clicked()
{
    uploadImage();
}


void MainWindow::on_tools1_clicked()
{
    ui->Widget_perso->setCurrentIndex(8);
}




void MainWindow::on_chat_clicked()
{
   ui->Widget_perso->setCurrentIndex(8);
}

void MainWindow::on_tools0_clicked()
{
    ui->Widget_perso->setCurrentIndex(7);
}



void MainWindow::on_tools2_clicked()
{
  ui->Widget_perso->setCurrentIndex(7);
}

void MainWindow::on_tools3_clicked()
{
  ui->Widget_perso->setCurrentIndex(7);
}

void MainWindow::on_tools4_clicked()
{
    ui->Widget_perso->setCurrentIndex(7);
}

void MainWindow::on_tools5_clicked()
{
    ui->Widget_perso->setCurrentIndex(7);
}

void MainWindow::on_persone6_clicked()
{
    ui->Widget_perso->setCurrentIndex(2);
}


void MainWindow::on_statestique5_clicked()
{
    openChartWindow();
}

void MainWindow::on_stat6_clicked()
{
    openChartWindow();
}

void MainWindow::on_stat4_clicked()
{
    openChartWindow();
}

void MainWindow::on_persone7_clicked()
{
    ui->Widget_perso->setCurrentIndex(2);
}

void MainWindow::on_task5_clicked()
{
    ui->treeView1->setModel(T.afficher(ui->find_task->text()));
    ui->Widget_perso->setCurrentIndex(6);
}

void MainWindow::on_task6_clicked()
{
    ui->treeView1->setModel(T.afficher(ui->find_task->text()));
    ui->Widget_perso->setCurrentIndex(6);
}

void MainWindow::on_task7_clicked()
{
    ui->treeView1->setModel(T.afficher(ui->find_task->text()));
    ui->Widget_perso->setCurrentIndex(6);
}

void MainWindow::on_tools7_clicked()
{
     ui->Widget_perso->setCurrentIndex(7);
}

void MainWindow::on_stat7_clicked()
{
   openChartWindow();
}

void MainWindow::on_google_2_clicked()
{
    QString url = "https://www.google.com";
        QDesktopServices::openUrl(QUrl(url));
}


void MainWindow::on_add_comm_clicked()
{
    update_id_task();
    QModelIndex selectedIndex = getSelectedIndex(ui->treeView1);
    if (!selectedIndex.isValid()) {
        return;
    }
   ui->Widget_perso->setCurrentIndex(9);
}

void MainWindow::on_send_comment_clicked()
{
    QModelIndex selectedIndex = getSelectedIndex(ui->treeView1);
    if (!selectedIndex.isValid()) {
        return;
    }

    int row = selectedIndex.row();
    QSqlQuery query;
    query.prepare("SELECT COM1, COM2, COM3 FROM TASK WHERE ID = :id");
    query.bindValue(":id",row);
    if (query.exec() && query.next()) {
        QString cm1 = query.value(0).toString();
        QString cm2 = query.value(1).toString();
        QString cm3 = query.value(2).toString();
        if(cm1==""){
            T.set_com1(ui->comment->text());
            T.comentaire1(row);
        }
        else if(cm2==""){
             T.set_com2(ui->comment->text());
            T.comentaire2(row);
        }
        else if(cm3==""){
             T.set_com3(ui->comment->text());
            T.comentaire3(row);
        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("espace"),
            QObject::tr("n'est pas d'espace.\n"
            "Click Cancel to exit."), QMessageBox::Cancel);
        }
        ui->treeView1->setModel(T.afficher(ui->find_task->text()));
        ui->Widget_perso->setCurrentIndex(6);


    }

}


void MainWindow::on_perone8_clicked()
{
    ui->Widget_perso->setCurrentIndex(2);
}

void MainWindow::on_stat8_clicked()
{
     openChartWindow();
}

void MainWindow::on_task8_clicked()
{

    ui->treeView1->setModel(T.afficher(ui->find_task->text()));
    ui->Widget_perso->setCurrentIndex(6);
}

void MainWindow::on_tools8_clicked()
{
     ui->Widget_perso->setCurrentIndex(7);
}

void MainWindow::on_ON_clicked()
{
     //A.write_to_arduino("1"); //envoyer 1 à arduino
}

void MainWindow::on_OFF_clicked()
{
    // A.write_to_arduino("0");
}

///------------------------- 5idmet Mariem -------------------------------------

void MainWindow::on_ravitaillement_clicked()
{
    int qtn = ui->lineEdit_6->text().toInt();
    QFile fichier("C:/Users/ayoub/OneDrive/Documents/ADHD Center 2/produit.txt");
        if (fichier.open(QIODevice::ReadOnly|QIODevice::Text)){
         QString text;
         text =fichier.readAll();
         fichier.close();

        // Création d'un objet QFile
        QFile file("C:/Users/ayoub/OneDrive/Documents/ADHD Center 2/produit.txt");
        // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        // Création d'un objet QTextStream à partir de notre objet QFile
        QTextStream flux(&file);
        // On choisit le codec correspondant au jeu de caractères que l'on souhaite ; ici, UTF-8
        flux.setCodec("UTF-8");
        // Écriture des différentes lignes dans le fichier
        int a=text.toInt();
        a=a+qtn;

        flux << a << endl;
        QString xs=QString::number(a);
        ui->nb_produit_stock->setText(xs);
        }
}

void MainWindow::on_pdf_clicked()
{

    QString strStream;
                   QTextStream out(&strStream);

                   const int rowCount = ui->table_enfant->model()->rowCount();
                   const int columnCount = ui->table_enfant->model()->columnCount();

                   out <<  "<html>\n"
                       "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                       <<  QString("<title>%1</title>\n").arg("strTitle")
                       <<  "</head>\n"
                       "<body bgcolor=#ffffff link=#5000A0>\n"

                      //     "<align='right'> " << datefich << "</align>"
                       "<center> <H1>Liste Des Seance De Soutient </H1></br></br></br></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                   // headers
                   out << "<thead><tr bgcolor=#3498DB> <th>Numero</th>";
                   for (int column = 0; column < columnCount; column++)
                       if (!ui->table_enfant->isColumnHidden(column))
                           out << QString("<th>%1</th>").arg(ui->table_enfant->model()->headerData(column, Qt::Horizontal).toString());
                   out << "</tr></thead>\n";

                   // data table
                   for (int row = 0; row < rowCount; row++) {
                       out << "<tr> <td bkcolor=0"<<row+1<<"</td>";
                       for (int column = 0; column < columnCount; column++) {
                           if (!ui->table_enfant->isColumnHidden(column)) {
                               QString data = ui->table_enfant->model()->data(ui->table_enfant->model()->index(row, column)).toString().simplified();
                               out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                           }
                       }
                       out << "</tr>\n";
                   }
                   out <<  "</table> </center>\n"
                       "</body>\n"
                       "</html>\n";

             QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
               if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

               QPrinter printer (QPrinter::PrinterResolution);
               printer.setOutputFormat(QPrinter::PdfFormat);
               printer.setPaperSize(QPrinter::A4);
               printer.setOutputFileName(fileName);

               QTextDocument doc;
               doc.setHtml(strStream);
               doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
               doc.print(&printer);

}

void MainWindow::on_Trie_btn_clicked()
{
    int cls;
    enfant b;
        if (ui->radio_asc->isChecked())
            {
            cls=1;

             ui->table_enfant->setModel(b.trier(cls));
            }
        else if (ui->radio_desc->isChecked())
            {
            cls=2;
          ui->table_enfant->setModel(b.trier(cls));
            }
        else if (ui->radio_desc_parent->isChecked())
            {
            cls=3;
          ui->table_enfant->setModel(b.trier(cls));
            }
        else
            {
            cls=0;
           ui->table_enfant->setModel(b.trier(cls));
            }

}

void MainWindow::on_supprimer_2_clicked()
{
    QModelIndexList selectedIndexes = ui->table_enfant->selectionModel()->selectedIndexes();
       if (!selectedIndexes.isEmpty()) {
           int row = selectedIndexes.first().row();
           // Récupérez les données associées à cette ligne à partir du modèle de données du TableView
           QString id = ui->table_enfant->model()->index(row, 0).data().toString();
           // Supprimez la ligne du modèle de données du TableView
           ui->table_enfant->model()->removeRow(row);

           // Supprimez la ligne de la base de données en utilisant une requête SQL
           QSqlQuery query;
           query.prepare("DELETE FROM ENFANTS WHERE id_enfant = ?");
           query.addBindValue(id);
           if (query.exec()) {
               // La suppression a réussi
               qDebug() << "Ligne supprimée de la base de données";
               ui->table_enfant->setModel(ef.afficher_enfant());
           } else {
               // La suppression a échoué
               qDebug() << "Erreur lors de la suppression de la ligne dans la base de données";
               qDebug() << query.lastError().text();
           }
       } else {
           // Aucune ligne sélectionnée
           qDebug() << "Aucune ligne sélectionnée";
       }
}

void MainWindow::on_rechercher_2_textEdited(const QString &arg1)
{
    if (arg1== "")
       ui->table_enfant->setModel(ef.afficher_enfant());
    else
        ui->table_enfant->setModel(ef.afficher_enfant2(arg1));
}

void MainWindow::on_load_clicked()
{
    int id=ui->id_modifier->text().toInt();
    QString xs=QString ::number(id);
    QSqlQuery qry;
    qry.prepare("SELECT NOM_ENFANT,PRENOM_ENFANT,ADRESSE_MAIL_PARENT,DATE_NAISSANCE,STATUE_PRODUIT FROM ENFANTS WHERE ID_ENFANT="+xs);
    if(qry.exec())
    {
        while(qry.next()){

        ui->nom_modifier->setText(qry.value(0).toString());
        ui->prenom_modifier->setText(qry.value(1).toString());
        ui->adresse_modifier->setText(qry.value(2).toString());
        ui->date_modifier->setText(qry.value(3).toString());
        ui->statut_modifier->setText(qry.value(4).toString());


        }
        }
}

void MainWindow::on_modifier_enf_clicked()
{
    int id=ui->id_modifier->text().toInt();


             QString nom=ui->nom_modifier->text();
             QString prenom=ui->prenom_modifier->text();
             QString adresse=ui->adresse_modifier->text();
             int statut=ui->statut_modifier->text().toInt();
             QString date=ui->date_modifier->text();

              //enfant E(id,statut,nom, prenom,adresse,date);
                     QSqlQuery query;

                     bool test=ef.modifier_enfant(id,nom,prenom,adresse,date,statut);
                     if(test)
                     {

                         ui->table_enfant->setModel(ef.afficher_enfant());

                         QMessageBox::information(nullptr, QObject::tr("Modifier enfant"),
                                     QObject::tr("enfant Modifier.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
                     }
                     else
                     {
                         QMessageBox::critical(nullptr, QObject::tr("Modifier enfant"),
                                     QObject::tr("Erreur !.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
                     }
}

void MainWindow::on_Ajouter_facture_clicked() // ajouter facture
{
    QString statut_paiement=ui->statut->text();
    QString date_paiement=ui->date->text();
    int idee=ui->id_enfant_fac->text().toInt();
    int montant=ui->montant->text().toInt();
    int id=ui->id_fac->text().toInt();

    facture f(id,montant,statut_paiement,date_paiement,idee);

    bool test=f.ajout_facture();
    if(test)
       {
         ui->table_facture->setModel(f.afficher_facture());
           QMessageBox::information(nullptr, QObject::tr("succes"),
                                    QObject::tr("Ajout effecté successfully\n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);
       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("Not good at all"),
                                    QObject::tr("Ajout non effecté Error.\n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);
       }
}

void MainWindow::on_Modifier_facture_clicked()
{

    int statut_paiement=ui->modif_statut->text().toInt();
    QString date_paiement=ui->modif_date_paiment->text();
    int idee=ui->modif_id_facture->text().toInt();
    int montant=ui->modif_montant->text().toInt();

    facture a;

    bool test=a.modifier(montant, statut_paiement, date_paiement, idee);

    if(test)
    {
        ui->table_facture->setModel(a.afficher_facture());
        QMessageBox::information(nullptr, QObject::tr("DB OPEN"),
                                 QObject::tr("modification effecté successfully\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("DB CLOSE"),
                                 QObject::tr("modification non effecté Error.\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
    }

}

void MainWindow::on_recherche_facture_textEdited(const QString &arg1)
{
    if (arg1== "")
       ui->table_facture->setModel(f.afficher_facture());
    else
        ui->table_facture->setModel(f.afficher_facture2(arg1));
}

void MainWindow::on_Trie_facture_clicked()
{
    int cls;
    facture f;
        if (ui->radio_asc_date->isChecked())
            {
            cls=1;

             ui->table_facture->setModel(f.trier(cls));
            }
        else if (ui->radio_desc_date->isChecked())
            {
            cls=2;
          ui->table_facture->setModel(f.trier(cls));
            }
        else if (ui->radio_asc_id_facture->isChecked())
            {
            cls=3;
          ui->table_facture->setModel(f.trier(cls));
            }
        else
            {
            cls=0;
           ui->table_facture->setModel(f.trier(cls));
            }
}

void MainWindow::on_pdf_facture_clicked()
{
    QString strStream;
  QTextStream out(&strStream);

  const int rowCount = ui->table_facture->model()->rowCount();
  const int columnCount = ui->table_facture->model()->columnCount();

  out <<  "<html>\n"
      "<head>\n"
      "<meta Content=\"Text/html; charset=Windows-1251\">\n"
      <<  QString("<title>%1</title>\n").arg("strTitle")
      <<  "</head>\n"
      "<body bgcolor=#ffffff link=#5000A0>\n"

     //     "<align='right'> " << datefich << "</align>"
      "<center> <H1>liste des Facture </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

  // headers
  out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
  for (int column = 0; column < columnCount; column++)
      if (!ui->table_facture->isColumnHidden(column))
          out << QString("<th>%1</th>").arg(ui->table_facture->model()->headerData(column, Qt::Horizontal).toString());
  out << "</tr></thead>\n";

  // data table
  for (int row = 0; row < rowCount; row++) {
      out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
      for (int column = 0; column < columnCount; column++) {
          if (!ui->table_facture->isColumnHidden(column)) {
              QString data = ui->table_facture->model()->data(ui->table_facture->model()->index(row, column)).toString().simplified();
              out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
          }
      }
      out << "</tr>\n";
                                          }
                                          out <<  "</table> </center>\n"
                                              "</body>\n"
                                              "</html>\n";

                                    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "register in PDF", QString(), "*.pdf");
                                      if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                                     QPrinter printer (QPrinter::PrinterResolution);
                                      printer.setOutputFormat(QPrinter::PdfFormat);
                                     printer.setPaperSize(QPrinter::A4);
                                    printer.setOutputFileName(fileName);

                                     QTextDocument doc;
                                      doc.setHtml(strStream);
                                      doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                                      doc.print(&printer);


}

void MainWindow::on_supprimer_facture_clicked()
{
    QModelIndexList selectedIndexes = ui->table_facture->selectionModel()->selectedIndexes();
       if (!selectedIndexes.isEmpty()) {
           int row = selectedIndexes.first().row();
           // Récupérez les données associées à cette ligne à partir du modèle de données du TableView
           QString id = ui->table_facture->model()->index(row, 0).data().toString();
           // Supprimez la ligne du modèle de données du TableView
           ui->table_facture->model()->removeRow(row);

           // Supprimez la ligne de la base de données en utilisant une requête SQL
           QSqlQuery query;
           query.prepare("DELETE FROM FACTURE WHERE id_FACTURE = ?");
           query.addBindValue(id);
           if (query.exec()) {
               // La suppression a réussi
               qDebug() << "Ligne supprimée de la base de données";
               ui->table_facture->setModel(f.afficher_facture());
           } else {
               // La suppression a échoué
               qDebug() << "Erreur lors de la suppression de la ligne dans la base de données";
               qDebug() << query.lastError().text();
           }
       } else {
           // Aucune ligne sélectionnée
           qDebug() << "Aucune ligne sélectionnée";
       }
}

void MainWindow::on_mail_clicked()
{
    int payerorno;
    payerorno=ui->table_facture->model()->data(ui->table_facture->model()->index(ui->table_facture->currentIndex().row(),3)).toInt();
    if(payerorno == 0){
    int id;
    id=ui->table_facture->model()->data(ui->table_facture->model()->index(ui->table_facture->currentIndex().row(),1)).toInt();
    QString datee;
    datee=ui->table_facture->model()->data(ui->table_facture->model()->index(ui->table_facture->currentIndex().row(),4)).toString();
    QString xs=QString ::number(id);
    QSqlQuery qry;
    QString a,b,c;
    qry.prepare("SELECT NOM_ENFANT,PRENOM_ENFANT,ADRESSE_MAIL_PARENT FROM ENFANTS WHERE ID_ENFANT="+xs);
    if(qry.exec())
    {
        while(qry.next()){

        a =qry.value(0).toString();
        b=qry.value(1).toString();
        c=qry.value(2).toString();


        }
        }
   // QItemSelectionModel *select = ui->table_facture->selectionModel();

        QString email_recipient = c;
        QString nom_recipient = a;
        QString prenom_recipient = b;

        QDialog *d=new Dialog(email_recipient,nom_recipient,prenom_recipient,datee,this);
        d->show();
        d->exec();
    }
    else {
        QMessageBox::information(0,tr("test"),tr("Facture payer"));
    }
}

void MainWindow::on_load_facture_2_clicked()
{
    int id=ui->modif_id_facture->text().toInt();
    QString xs=QString ::number(id);
    QSqlQuery qry;
    qry.prepare("SELECT MONTANT_FACT,DATE_FACT,STATUT_FACT FROM FACTURE WHERE ID_FACTURE="+xs);
    if(qry.exec())
    {
        while(qry.next()){

        ui->modif_montant->setText(qry.value(0).toString());
        ui->modif_date_paiment->setText(qry.value(1).toString());
        ui->modif_statut->setText(qry.value(2).toString());



        }
        }
}


/// ------------------- The Menu Slots -------------------


void MainWindow::on_acceuil_btn_clicked()
{   ca=0;
    ui->Menu->setCurrentIndex(0);
    ui->acceuil_btn->setStyleSheet("QPushButton {""background:#2C3E50;""}");
    ui->benevole_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->personnel_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->medecin_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->activite_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->seance_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->enfant_btn->setStyleSheet("QPushButton {""background: #3498DB;""QPushButton:hover {""background: #2C3E50;""}");
}

void MainWindow::on_enfant_btn_clicked()
{   ca=0;
    ui->Menu->setCurrentIndex(1);
    ui->acceuil_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->enfant_btn->setStyleSheet("QPushButton {""background:#2C3E50;""}");
    ui->benevole_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->personnel_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->medecin_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->activite_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->seance_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
}

void MainWindow::on_medecin_btn_clicked()
{   ca=2;
    ui->Menu->setCurrentIndex(2);
    ui->acceuil_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->enfant_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->benevole_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->personnel_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->medecin_btn->setStyleSheet("QPushButton {""background:#2C3E50;""}");
    ui->activite_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->seance_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
}

void MainWindow::on_personnel_btn_clicked()
{    ca=0;
    ui->Menu->setCurrentIndex(3);
    ui->acceuil_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->enfant_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->benevole_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->personnel_btn->setStyleSheet("QPushButton {""background:#2C3E50;""}");
    ui->medecin_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->activite_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->seance_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
}
void MainWindow::on_seance_btn_clicked()
{    ca=0;
    ui->Menu->setCurrentIndex(4);
    ui->acceuil_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->enfant_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->benevole_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->personnel_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->medecin_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->activite_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->seance_btn->setStyleSheet("QPushButton {""background:#2C3E50;""}");

}
void MainWindow::on_activite_btn_clicked()
{    ca=0;
    ui->Menu->setCurrentIndex(5);
    ui->acceuil_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->enfant_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->benevole_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->personnel_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->medecin_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->activite_btn->setStyleSheet("QPushButton {""background:#2C3E50;""}");
    ui->seance_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
}

void MainWindow::on_benevole_btn_clicked()
{   ca=0;
    ui->Menu->setCurrentIndex(6);
    ui->acceuil_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->enfant_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->benevole_btn->setStyleSheet("QPushButton {""background:#2C3E50;""}");
    ui->personnel_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->medecin_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->activite_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
    ui->seance_btn->setStyleSheet("QPushButton {""background:#3498DB;""}""QPushButton:hover {""background: #2C3E50;""}");
}


/// ---------------------------- TOUJANI -----------------------------------------

int iii,bbb,totali;

void MainWindow::update_label2()
{
    if (ca==2){
        data=B.read_from_arduino();
        QString id_enfant=ui->comboBoxenfant_consul->currentText();
        QByteArray bytes = id_enfant.toUtf8();
        B.write_to_arduino(bytes);


        int value = data.toInt();
        qDebug("Value: %d", value);
        if(value>=50)




        if(value>=0)
        {
            ui->label_21->setNum(value); // si les données reçues de arduino via la liaison série sont égales à 1
            ui->lcdNumber->display(data.toInt());

            iii=data.toInt();
                    QString id_enfant=ui->comboBoxenfant_consul->currentText();
                    QByteArray bytes = id_enfant.toUtf8();

            B.write_to_arduino(bytes);


            if(data.toInt()!=0)
            {
                bbb=bbb+1;
                totali=totali+iii;

            }


            if(bbb%5==0)
            {


                QString newx=QString::number(totali/4);

                qDebug("total: %d", totali);
                ME.updateenfant(id_enfant,newx);

            }

        //}while(b!=5);
        qDebug("b=%d",bbb);

        }
    }
}





void MainWindow::on_ajout_2_clicked()
{
    QString ID_medecin=ui->lineEdit_ID_medecin->text();
    QString nom_medecin=ui->lineEdit_Nom_medecin->text();
    QString prenom_medecin=ui->lineEdit_Prenom_medein->text();
    QString adresse_medecin=ui->lineEdit_adress_medecin->text();
    QString adressemainl_medecin=ui->lineEdit_adress_mail_medecin->text();
    QString parcour_medecin=ui->lineEdit_parcour_medecin->text();


    medecin M(ID_medecin,nom_medecin,prenom_medecin,adresse_medecin,adressemainl_medecin,parcour_medecin);

    bool test=M.ajouter();
    if(test)
    {
        ui->tableView_med->setModel(M.afficher());
        ui->comboBoxdelete->setModel(M.afficher());
        ui->comboBoxupdate->setModel(M.afficher());
        QMessageBox::information(nullptr,QObject::tr("OIK"),
                                            QObject::tr("Ajout nice \n"
                                                        "clic cancel"),QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);

}


void MainWindow::on_delet_botton_clicked()
{
    medecin M;
    //M.setID_medecin(ui->lineEdit_ID_medecin_D_2->text());

    QString id=ui->comboBoxdelete->currentText();

        bool test=M.supprimer(id);
        QMessageBox msgBox;
if(test)
{
    msgBox.setText("suppression nej7A");
    ui->tableView_med->setModel(M.afficher());
    ui->comboBoxdelete->setModel(M.afficher());

    ui->comboBoxupdate->setModel(M.afficher());


}
else {
    msgBox.setText("ma tfasa5ech");

}
msgBox.exec();


}









void MainWindow::on_pushButton_update_clicked()
{
    QString id_medecin=ui->comboBoxupdate->currentText();

    //QString ID_medecin=ui->lineEdit_ID_medecin->text();
    QString nom_medecin=ui->lineEdit_Nom_medecin->text();
    QString prenom_medecin=ui->lineEdit_Prenom_medein->text();
    QString adresse_medecin=ui->lineEdit_adress_medecin->text();
    QString adressemainl_medecin=ui->lineEdit_adress_mail_medecin->text();
    QString parcour_medecin=ui->lineEdit_parcour_modif->text();


    medecin M(id_medecin,nom_medecin,prenom_medecin,adresse_medecin,adressemainl_medecin,parcour_medecin);

    if(parcour_medecin.isEmpty())
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout un parcour.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);
    }
    else {
        bool test=M.update(id_medecin);
        if(test)
        {
            QMessageBox msgbox;
            ui->tableView_med->setModel(M.afficher());
            ui->comboBoxupdate->setModel(M.afficher());
            ui->comboBoxdelete->setModel(M.afficher());

            QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("changement effectué.\n"
                                              "click Cancel to exit."),QMessageBox::Cancel);



        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("modification non effectué.\n"
                                              "click Cancel to exit."),QMessageBox::Cancel);
        }
    }

}
//********* rechercher ***********

void MainWindow::on_lineEdit_ID_rechercher_textChanged(const QString &arg1)
{
    QString rech =ui->lineEdit_ID_rechercher->text();

        ui->tableView_med->setModel(M.rechercher(rech));
}



// *************** medicamant ***************







//********* ajout medic ***********
void MainWindow::on_ajout_3_clicked()
{
    QString id_medicamant=ui->lineEdit_ID_medic->text();
    QString nom_medicamant=ui->lineEdit_Nom_medic->text();
    QString qte_medicamant=ui->lineEdit_qte_medic->text();

    medicamant ME(id_medicamant,nom_medicamant,qte_medicamant);

    bool test=ME.ajouter_medi();

    if(test)
    {
        ui->tableView_medic->setModel(ME.affichermedi());

           QMessageBox:: information(nullptr, QObject::tr("OK"),
                                              QObject::tr("Ajout effectué\n"
                                                          "click cancel to exit."),QMessageBox::Cancel);
           }
       else
           QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Ajout non effectué.\n"
                                             "click Cancel to exit."),QMessageBox::Cancel);




}




void MainWindow::on_comboBoxmed_tri_currentIndexChanged(const QString &arg1)
{
    QString selectionvalue= ui->comboBoxmed_tri->currentText();
        if (selectionvalue=="ID"){ui->tableView_medic->setModel(ME.trid());}
        else if (selectionvalue=="Nom"){ui->tableView_medic->setModel(ME.trinom());}
        else if (selectionvalue=="QTE"){ui->tableView_medic->setModel(ME.tritype());}
        else if    (selectionvalue=="non trier"){ui->tableView_medic->setModel(ME.affichermedi());}
}



//********* PDF ***********
void MainWindow::on_pushButtonTouja_clicked()
{

    QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);
            printer.setOutputFileName("medecin.pdf");

            QTableView* tableView = ui->tableView_med; // replace with the name of your QTableView

            // create a QTextDocument with the contents of the QTableView
            QTextDocument doc;
            QTextCursor cursor(&doc);
            doc.setPageSize(printer.pageRect().size());
               doc.setDocumentMargin(10.0);

            // insert the title in the middle
                QTextBlockFormat blockFormat;
                blockFormat.setAlignment(Qt::AlignCenter);
                cursor.insertBlock(blockFormat);
                QTextCharFormat titleFormat;
                titleFormat.setFontWeight(QFont::Bold);
                titleFormat.setFontPointSize(14);
                cursor.insertText("tab medecin", titleFormat);

                // insert the image in the top left corner
                QImage image("C:/Users/ayoub/Desktop/logodevsn.webp"); // replace with the name and path of your image
                if (!image.isNull()) {
                    QPixmap pixmap = QPixmap::fromImage(image);
                    if (!pixmap.isNull()) {
                        pixmap = pixmap.scaled(QSize(200, 50), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                        QTextImageFormat imageFormat;
                        imageFormat.setWidth(pixmap.width());
                        imageFormat.setHeight(pixmap.height());
                        imageFormat.setName("medecin.pdf");
                        cursor.movePosition(QTextCursor::Start);
                        cursor.insertImage(imageFormat);
                        doc.addResource(QTextDocument::ImageResource, QUrl("medecin.pdf"), QVariant(pixmap));
                    }
                }

                // insert the table
                cursor.insertBlock();
                QTextBlockFormat tableBlockFormat;
                    tableBlockFormat.setAlignment(Qt::AlignCenter);
                    cursor.insertBlock(tableBlockFormat);
            cursor.insertText("Table View Data\n\n");
            int rows = tableView->model()->rowCount();
            int columns = tableView->model()->columnCount();
            QTableWidget table(rows + 1, columns);
            table.setHorizontalHeaderLabels(QStringList() << "ID_medecin" << "Nom" << "prenom" << "adresse" << "mail" << "parcour"); // replace with your column headers
            for (int row = 0; row < rows; row++) {
                for (int column = 0; column < columns; column++) {
                    table.setItem(row + 1, column, new QTableWidgetItem(tableView->model()->data(tableView->model()->index(row, column)).toString()));
                }
            }
            QTextTableFormat tableFormat;
            tableFormat.setHeaderRowCount(1);
            QTextTable* textTable = cursor.insertTable(rows + 1, columns, tableFormat);

            for (int column = 0; column < columns; column++) {
                QTextTableCell headerCell = textTable->cellAt(0, column);
                QTextCursor headerCursor = headerCell.firstCursorPosition();
                headerCursor.insertText(table.horizontalHeaderItem(column)->text());
            }

            QTextCharFormat cellFormat;
            cellFormat.setFont(QFont("Helvetica", 10, QFont::Bold));
            for (int row = 0; row < rows; row++) {
                for (int column = 0; column < columns; column++) {
                    QTextTableCell cell = textTable->cellAt(row + 1, column);
                    cell.setFormat(cellFormat);
                    cell.firstCursorPosition().insertText(tableView->model()->data(tableView->model()->index(row, column)).toString());
                }
            }
            //la date ou le pdf a ete generer
            cursor.movePosition(QTextCursor::PreviousBlock);
                QTextBlockFormat dateBlockFormat;
                dateBlockFormat.setAlignment(Qt::AlignRight);
                cursor.insertBlock(dateBlockFormat);
                QTextCharFormat dateFormat;
                dateFormat.setFontPointSize(8);
                cursor.insertText("Generated on " + QDate::currentDate().toString("dd/MM/yyyy"), dateFormat);

            // print the QTextDocument to the PDF printer
            QPainter painter(&printer);
            painter.setRenderHint(QPainter::Antialiasing);
            painter.setRenderHint(QPainter::TextAntialiasing);
            doc.setPageSize(printer.pageRect().size());
            doc.drawContents(&painter);





            QMessageBox::information(nullptr,QObject::tr("pdf"),
            QObject::tr("pdf is printed.\n"
                        "click cancel and exit"),QMessageBox::Cancel);


}








// ********** CONSULTATION *************



void MainWindow::on_ajout_4_clicked()
{
    QString ID_cons=ui->lineEdit_ID_consul->text();
    QString temps_cons=ui->temps->text();
    QString salle_cons=ui->salle->text();
    QString diag_cons=ui->diag->text();
    QString id_medecin=ui->comboBoxmed_consul->currentText();
    QString id_medica=ui->comboBoxmedeca_consul->currentText();
    QString id_enfant=ui->comboBoxenfant_consul->currentText();

    ui->comboBoxmedeca_consul->addItem("NULL");

    consultation CN(ID_cons,temps_cons,salle_cons,diag_cons,id_medecin,id_enfant,id_medica);



    bool test=CN.ajouter_cons();

    if(test)
    {
        ui->tableView_cons->setModel(CN.afficher_cons());
           QMessageBox:: information(nullptr, QObject::tr("OK"),
                                              QObject::tr("Ajout effectué\n"
                                                          "click cancel to exit."),QMessageBox::Cancel);
           }
       else
           QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Ajout non effectué.\n"
                                             "click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_view_stat_clicked()
{
    QSqlQuery q1,q2,q3;
    qreal tot=0,c1=0,c2=0,c3=0;
    q1.prepare("SELECT * FROM CONSULTATION");
    q1.exec();
    q2.prepare("SELECT * FROM CONSULTATION WHERE ID_MEDECA='NULL'");
    q2.exec();
    q3.prepare("SELECT * FROM CONSULTATION WHERE ID_MEDECA!='NULL'");
    q3.exec();

    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}

    c1=c1/tot;
    c2=c2/tot;
    c3=c3/tot;

    QPieSeries *series = new QPieSeries();
    series->append("utiliser med",c2);
    series->append("utiliser med non",c1);
    series->setHoleSize(0.35);
    QChart *Chart = new QChart();
    Chart ->addSeries(series);
    Chart->setTitle("chart med");

    QChartView *chartview = new QChartView(Chart);
    Chart->setAnimationOptions(QChart::SeriesAnimations);
    chartview->setRenderHint(QPainter::Antialiasing);
     Chart->setBackgroundVisible(true);
    chartview->setMinimumSize(400,400);
    chartview->show();
}


/// ------------------------------- 5idmet Haithem -----------------------------------------



void MainWindow::on_Ajouter_benv_clicked()
{
       int id=ui->idben_3->text().toInt();
       int abs=ui->abs_3->text().toInt();
       int scr=ui->score_3->text().toInt();
       int tl=ui->tel_3->text().toInt();
       QString nom=ui->NOM_3->text();
       QString email=ui->email_3->text();
       QString adr=ui->adress_3->text();
       QString act=ui->activite_3->text();
       QString dte=ui->disp_3->text();

       if(ui->email_3->text().contains("@")){

           benevole b(nom,email,adr,dte,act,id,tl,scr,abs); //bech nkaml khedma mnhne kaml constructeur ou les var
            participent a;
           bool test=b.ajouter();

           if(test)
           {
                ui->ben_tab_2->setModel(b.afficher());
                ui->tab_particip->setModel(a.afficher());
                ui->table_ben_part->setModel(execb.afficher_ben());
               QMessageBox::information(nullptr, QObject::tr("DB OPEN"),
                                        QObject::tr("Ajout effecté successfully\n"
                                                    "Click Cancel to exit."),QMessageBox::Cancel);
           }
           else
           {
               QMessageBox::critical(nullptr, QObject::tr("DB CLOSE"),
                                        QObject::tr("Ajout non effecté Error.\n"
                                                    "Click Cancel to exit."),QMessageBox::Cancel);
           }

       }
       else{
           QMessageBox::critical(nullptr, QObject::tr("Erreur @"),
                                    QObject::tr("Ajout non effecté Error.\n"
                                                "champ email @ introvable  \n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);
       }

}

void MainWindow::on_Modification_benv_clicked()
{
    int id_selected;
    id_selected=ui->ben_tab_2->model()->data(ui->ben_tab_2->model()->index(ui->ben_tab_2->currentIndex().row(),0)).toInt();



       int abs=ui->abs_4->text().toInt();
       int scr=ui->score_4->text().toInt();
       int tl=ui->tel_4->text().toInt();
       QString nom=ui->NOM_4->text();
       QString email=ui->email_4->text();
       QString adr=ui->adress_4->text();
       QString act=ui->activite_4->text();
       QString dte=ui->disp_4->text();

       benevole a;

       bool test=a.modifier(id_selected,nom, adr, email, act, tl, scr, abs, dte);

       if(test)
       {
           ui->ben_tab_2->setModel(a.afficher());
           QMessageBox::information(nullptr, QObject::tr("DB OPEN"),
                                    QObject::tr("modification effecté successfully\n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);

       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("DB CLOSE"),
                                    QObject::tr("modification non effecté Error.\n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);
       }

}

void MainWindow::on_Supprimer_benv_clicked()
{
    int id_selected;
    id_selected=ui->ben_tab_2->model()->data(ui->ben_tab_2->model()->index(ui->ben_tab_2->currentIndex().row(),0)).toInt();

    benevole b;

    bool test= b.supprimer(id_selected);
       if(test)
       {
            ui->ben_tab_2->setModel(b.afficher());
           QMessageBox::information(nullptr, QObject::tr("DB OPEN"),
                                    QObject::tr("suppresion effecté successfully\n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);
       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("DB CLOSE"),
                                    QObject::tr("suppresion non effecté Error.\n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);
       }

}



void MainWindow::on_PDF_clicked()
{
    int id_selected;
    id_selected=ui->ben_tab_2->model()->data(ui->ben_tab_2->model()->index(ui->ben_tab_2->currentIndex().row(),0)).toInt();
    bool test =execb.Export(id_selected);

            if (test)
                {
                    QMessageBox::information(nullptr, QObject::tr("Succés"), QObject::tr("Export effectué\n""Click Ok to exit."), QMessageBox::Ok);
                }
                else QMessageBox::warning(nullptr, QObject::tr("Erreur"),QObject::tr("Export non effectué. \n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_PDF_exp_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->ben_tab_2->model()->rowCount();
    const int columnCount = ui->ben_tab_2->model()->columnCount();
    out <<  "<html>\n"
               "<head>\n"
       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
       <<  QString("<title>%1</title>\n").arg("strTitle")
       <<  "</head>\n"
      "<body bgcolor=#ffffff link=#5000A0>\n"

      //     "<align='right'> " << datefich << "</align>"
         "<center> <H1>Tableau des Benevole </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                 // headers
        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
       for (int column = 0; column < columnCount; column++)
       if (!ui->ben_tab_2->isColumnHidden(column))
           out << QString("<th>%1</th>").arg(ui->ben_tab_2->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

                                               // data table
               for (int row = 0; row < rowCount; row++) {
                out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                  for (int column = 0; column < columnCount; column++) {
                if (!ui->ben_tab_2->isColumnHidden(column)) {
         QString data = ui->ben_tab_2->model()->data(ui->ben_tab_2->model()->index(row, column)).toString().simplified();
         out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                                       }
                                                   }
                          out << "</tr>\n";
                                               }
                                out <<  "</table> </center>\n"
                                        "</body>\n"
                                      "</html>\n";
          QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                       QPrinter printer (QPrinter::PrinterResolution);
                        printer.setOutputFormat(QPrinter::PdfFormat);
                       printer.setPaperSize(QPrinter::A4);
                      printer.setOutputFileName(fileName);

                       QTextDocument doc;
                        doc.setHtml(strStream);
                        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                        doc.print(&printer);
}

void MainWindow::on_Trie_ben_btn_clicked()
{
    int cls;
    benevole b;
        if (ui->radio_asc_2->isChecked())
            {
            cls=1;

             ui->ben_tab_2->setModel(b.trier(cls));
            }
        else if (ui->radio_desc_2->isChecked())
            {
            cls=2;
          ui->ben_tab_2->setModel(b.trier(cls));
            }
        else
            {
            cls=0;
           ui->ben_tab_2->setModel(b.trier(cls));
            }

}

void MainWindow::on_Recherche_benv_clicked()
{

            QString rechercheer=ui->recherche_zone->text();

            benevole b;
             ui->ben_tab_2->setModel(b.rechercher(rechercheer));
}


void MainWindow::on_recherche_zone_textEdited(const QString &arg1)
{
    benevole b;
     ui->ben_tab_2->setModel(b.rechercher(arg1));
}

void MainWindow::on_pushButton_5_clicked() //ajout participent
{
    int id_ben;
    id_ben=ui->table_ben_part->model()->data(ui->table_ben_part->model()->index(ui->table_ben_part->currentIndex().row(),0)).toInt();

    int id_event;
    id_event=ui->tab_activite->model()->data(ui->tab_activite->model()->index(ui->tab_activite->currentIndex().row(),0)).toInt();

    QString nom_bent;
    nom_bent=ui->table_ben_part->model()->data(ui->table_ben_part->model()->index(ui->table_ben_part->currentIndex().row(),1)).toString();

    QString nom_event;
    nom_event=ui->tab_activite->model()->data(ui->tab_activite->model()->index(ui->tab_activite->currentIndex().row(),1)).toString();


    participent b;

    bool test = b.ajouter_participent(id_ben,id_event,nom_bent,nom_event);

    if(test)
    {
         ui->tab_particip->setModel(b.afficher());
         ui->tab_activite->setModel(execb.afficher_event());
         ui->table_ben_part->setModel(execb.afficher_ben());
         ui->ben_tab_2->setModel(execb.afficher());
        QMessageBox::information(nullptr, QObject::tr("DB OPEN"),
                                 QObject::tr("Ajout effecté successfully\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("DB CLOSE"),
                                 QObject::tr("Ajout non effecté Error.\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
    }
}


void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    participent p;
    ui->tab_particip->setModel(p.rechercher(arg1));
}

void MainWindow::on_Trie_btn_particip_clicked()
{
    int cls;
    participent b;
        if (ui->radio_asc_particip->isChecked())
            {
            cls=1;

             ui->tab_particip->setModel(b.trier(cls));
            }
        else if (ui->radio_desc_particip->isChecked())
            {
            cls=2;
          ui->tab_particip->setModel(b.trier(cls));
            }
        else
            {
            cls=0;
           ui->tab_particip->setModel(b.trier(cls));
            }
}

void MainWindow::on_certificat_clicked()
{

    benevole be;
    QString id_ben;
    int x;
    x=be.check(id_ben=ui->tab_particip->model()->data(ui->tab_particip->model()->index(ui->tab_particip->currentIndex().row(),2)).toString());

    if(x>=50){
    QString name;
    name=ui->tab_particip->model()->data(ui->tab_particip->model()->index(ui->tab_particip->currentIndex().row(),3)).toString();
    QString event;
    event=ui->tab_particip->model()->data(ui->tab_particip->model()->index(ui->tab_particip->currentIndex().row(),4)).toString();

    QString strStream;
    QTextStream out(&strStream);
    QDate cd = QDate::currentDate();



    out<<"<div style=""width:800px; height:600px; padding:20px; text-align:center; border: 10px solid #787878"">\n"
     " <div style=""width:750px; height:550px; padding:20px; text-align:center; border: 5px solid #787878"">\n"
    "  <span style=""font-size:50px;" "font-weight:bold"">""Certificate of Completion</span>\n"
       "<br><br>\n"
      " <span style=""font-size:25px"">""<""i>This is to certify that</i></span>\n"
        "<br><br>\n"
       << QString(" <span style=""font-size:30px"">""<""b>%1</b></span><br/><br/>\n").arg(name)
       <<"  <span style=""font-size:25px"">""<""i>has hellped our ADHD Center and completed the event</i></span> <br/><br/>\n"
         << QString("  <span style=""font-size:30px"">%1</span> <br/><br/>").arg(event)
        << " <span style=""font-size:25px""><i>dated</i></span><br>\n"
             << QString("<span style=""font-size:30px"">%1</span>\n").arg(cd.toString())
             <<
               " </div>\n"
                 "</div>\n";

          QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                       QPrinter printer (QPrinter::PrinterResolution);
                        printer.setOutputFormat(QPrinter::PdfFormat);
                       printer.setPaperSize(QPrinter::A4);
                      printer.setOutputFileName(fileName);

                       QTextDocument doc;
                        doc.setHtml(strStream);
                        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                        doc.print(&printer);


                        popUp->setPopupText("Impression effecté successfully\n");
                            Ar.write_to_arduino("1");
                           popUp->show();
    }
    else{

        popUp->setPopupText("Le benevole shouiter ne peux \n""pas avoire de certificat encore.\n");
         popUp->show();
    }
}

void MainWindow::on_pushButton_7_clicked()//participent supprimer
{
    int id_selected;
    id_selected=ui->tab_particip->model()->data(ui->tab_particip->model()->index(ui->tab_particip->currentIndex().row(),0)).toInt();
    int id2;
    id2=ui->tab_particip->model()->data(ui->tab_particip->model()->index(ui->tab_particip->currentIndex().row(),1)).toInt();
    int id3;
    id3=ui->tab_particip->model()->data(ui->tab_particip->model()->index(ui->tab_particip->currentIndex().row(),2)).toInt();

    participent b;

    bool test= b.supprimer(id_selected,id2,id3);
       if(test)
       {
           ui->tab_activite->setModel(execb.afficher_event());
           ui->table_ben_part->setModel(execb.afficher_ben());
            ui->tab_particip->setModel(exepar.afficher());
            ui->ben_tab_2->setModel(execb.afficher());
           QMessageBox::information(nullptr, QObject::tr("DB OPEN"),
                                    QObject::tr("suppresion effecté successfully\n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);
       }

       else
       {
           QMessageBox::critical(nullptr, QObject::tr("DB CLOSE"),
                                    QObject::tr("suppresion non effecté Error.\n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);
       }

}



void MainWindow::on_ben_tab_2_activated(const QModelIndex &index)
{
    if(index.isValid()){
        int id_selected;
        id_selected=ui->ben_tab_2->model()->data(ui->ben_tab_2->model()->index(ui->ben_tab_2->currentIndex().row(),0)).toInt();
        QSqlQuery qry;
        QString vall=QString::number(id_selected);
        qry.prepare("SELECT * FROM BENEVOLE WHERE ID_BEN = "+vall);
        if(qry.exec())
        {
            ui->NOM_4->setText(qry.value(0).toString());
            ui->adress_4->setText(qry.value(1).toString());
            ui->activite_4->setText(qry.value(3).toString());
            ui->email_4->setText(qry.value(2).toString());
            ui->tel_4->setText(qry.value(4).toString());
            ui->disp_4->setText(qry.value(7).toString());
            ui->score_4->setText(qry.value(5).toString());
            ui->abs_4->setText(qry.value(6).toString());
        }
    }


}



void MainWindow::on_load_2_clicked()
{

        int id_selected;
        id_selected=ui->ben_tab_2->model()->data(ui->ben_tab_2->model()->index(ui->ben_tab_2->currentIndex().row(),0)).toInt();
        QSqlQuery qry;
        QString vall=QString::number(id_selected);
        qry.prepare("SELECT * FROM BENEVOLE WHERE ID_BEN = "+vall);
        if(qry.exec())
        {
            while(qry.next()){
            ui->NOM_4->setText(qry.value(1).toString());
            ui->adress_4->setText(qry.value(2).toString());
            ui->activite_4->setText(qry.value(4).toString());
            ui->email_4->setText(qry.value(3).toString());
            ui->tel_4->setText(qry.value(5).toString());
            ui->disp_4->setText(qry.value(8).toString());
            ui->score_4->setText(qry.value(6).toString());
            ui->abs_4->setText(qry.value(7).toString());
                    }
        }

}


