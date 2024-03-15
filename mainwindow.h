#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dialog.h"
#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
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
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkAccessManager>

//******** Achref **********

#include <persone.h>
#include <task.h>
#include<QTreeView>
#include <QTimer>
#include <QStandardItem>
#include <QButtonGroup>
#include "evenement.h"
#include "etudiant.h"
#include "enfant.h"
#include "facture.h"

//******** Touja **********

#include "medecin.h"
#include "medicamant.h"
#include "consultation.h"
#include "bpm.h"
#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

// ************ Haithem *****************

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QTextDocument>
#include <QtCharts>
#include <QBarSeries>
#include <QBarSet>
#include <QChartView>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include "benevole.h"
#include "popup.h"
#include "arduino.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool recherche(int);

   //******* Achref ***********

    void stat();
    void openChartWindow();
    void generatePDF();
   QModelIndex getSelectedIndex(QTreeView *treeView);

private slots:

   /// **************** AYOUB ****************

    void on_ajouter_clicked();
    void on_supprimer_clicked();
    void on_update_clicked();
    void on_rech_seance_textEdited(const QString &arg1);
    void on_tri_id_clicked();
    void on_tri_mat_clicked();
    void on_tri_heure_clicked();
    void on_pdf_seance_clicked();
    void on_all_Dec_clicked();
    void on_all_Anuller_clicked();
    void on_seance_btn_clicked();
    void on_acceuil_btn_clicked();
    void on_enfant_btn_clicked();
    void on_medecin_btn_clicked();
    void on_personnel_btn_clicked();
    void on_activite_btn_clicked();
    void on_benevole_btn_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_load_seance_clicked();
    /// **************** AZIZ ****************

    void on_pb_ajouter_clicked();
    void on_pushButton_2_clicked();
    void on_valider1_clicked();
    void on_pushButton_3_clicked();
    void on_modifier_2_clicked();
    void on_comboBox_2_activated(const QString &arg1);
    void on_Tribox_currentIndexChanged(const QString &arg1);
    void on_lineEdit_textChanged(const QString &arg1);
    void on_recherche_textChanged(const QString &arg1);
    void on_pushButton_clicked();
    void on_stats_clicked();
    void on_label_stat_linkActivated(const QString &link);
    void on_recherche_selectionChanged();
    void on_SMS_clicked();
    void replyFinished(QNetworkReply* reply);
  /// *****************  Achref  ***************
    void update_label1();
      void readUID(Arduino* arduino);
    void on_pushButton_11_clicked();
    void on_modifier_clicked();
    void on_persone0_clicked();
    void on_ajouter1_clicked();
    void on_afficher1_clicked();
    void on_persone1_clicked();
    void on_modifier1_clicked();
    void on_supprimer1_clicked();
    void on_persone2_clicked();
    void on_persone3_clicked();
    void on_stat0_clicked();
    void on_Bfind_clicked();
    void on_find_textChanged();
    void on_add_task_clicked();
    void update_id();
    void on_select_per_clicked();
    void on_persone5_clicked();
    void on_task0_clicked();
    void on_statestique1_clicked();
    void on_tasks1_clicked();
    void on_stat2_clicked();
    void on_task2_clicked();
    void on_stat3_clicked();
    void on_task3_clicked();
    void on_supprimer3_clicked();
    void on_supp_task_clicked();
    void  update_id_task();
    void on_modifier_task_clicked();
    void on_mod_task_clicked();
    void on_persone4_clicked();
    void on_pushButton_16_clicked();
    void on_task4_clicked();
    void on_pushButton_15_clicked();
    void on_send_clicked();
    void send_message();
    void afficher_message();
    void uploadImage();
    void on_up_img_clicked();
    void displayImageFromDatabase();
    void on_tools1_clicked();
    void on_chat_clicked();
    void on_tools0_clicked();
    void on_tools2_clicked();
    void on_tools3_clicked();
    void on_tools4_clicked();
    void on_tools5_clicked();
    void on_persone6_clicked();
    void on_statestique5_clicked();
    void on_stat6_clicked();
    void on_stat4_clicked();
    void on_persone7_clicked();
    void on_task5_clicked();
    void on_task6_clicked();
    void on_task7_clicked();
    void on_tools7_clicked();
    void on_stat7_clicked();
    void on_google_2_clicked();
    void triertreeView();
    void toggleTreeViewSorting(int state);
    void sortTreeViewBySalary();
    void slaireSorting(int state);
    void sort_age();
    void ageSorting(int state) ;
    void handleCheckBoxes(bool checked);
    void on_add_comm_clicked();
    void on_send_comment_clicked();
    void updateTask(int id, const QString &com);
    void on_perone8_clicked();
    void on_stat8_clicked();
    void on_task8_clicked();
    void on_tools8_clicked();
    void on_ON_clicked();
    void on_OFF_clicked();
 /// **************** Mariem ****************

    void on_pushButton_6_clicked();
    void on_pushButton_4_clicked();
    void on_supprimer_2_clicked();
    void on_supprimer_facture_clicked();
    void on_rechercher_clicked();
    void on_pdf_clicked();
    void on_statistique_clicked();
    void on_rechercher_2_textEdited(const QString &arg1);
    void on_Trie_btn_clicked();
    void on_Ajouter_facture_clicked();
    void on_Modifier_facture_clicked();
    void on_recherche_facture_textEdited(const QString &arg1);
    void on_Trie_facture_clicked();
    void on_pdf_facture_clicked();
    void on_mail_clicked();
    void on_load_clicked();
    void on_ravitaillement_clicked();
    void on_modifier_enf_clicked();
    void on_load_facture_2_clicked();

/// **************** Toujani ****************


    void on_ajout_2_clicked();
    void on_delet_botton_clicked();
    void on_pushButton_update_clicked();
    void on_ajout_3_clicked();
    void on_pushButtonTouja_clicked();
    void on_ajout_4_clicked();
    void on_view_stat_clicked();
    void on_lineEdit_ID_rechercher_textChanged(const QString &arg1);
    void on_comboBoxmed_tri_currentIndexChanged(const QString &arg1);
    void update_label2();

// ********************* Haithem *********************************
    void on_Ajouter_benv_clicked();
    void on_Modification_benv_clicked();
    void on_Supprimer_benv_clicked();
    void on_PDF_clicked();
    void on_PDF_exp_clicked();
    void on_Recherche_benv_clicked();
    void on_recherche_zone_textEdited(const QString &arg1);
    void on_pushButton_5_clicked();///&*
    void on_lineEdit_textEdited(const QString &arg1);
    void on_Trie_btn_particip_clicked();
    void on_certificat_clicked();
    void on_ben_tab_2_activated(const QModelIndex &index);
    void on_PDF_2_clicked();
    void on_pushButton_7_clicked();
    void on_Trie_ben_btn_2_clicked();
    void on_load_2_clicked();
    void on_Trie_ben_btn_clicked();


private:
    Ui::MainWindow *ui;

    etudiant e;
    evenement E;
    enfant ef;
    facture f;
    int id_decaler=0;
//********************* Achref *****************
    persone P;
    task T;
    bool test;
    QString login;
    QString name;
    QTimer* timer;
    QString imagePath; // Declare a global variable to store the selected image path
    QByteArray imageBytes;
    QByteArray imgg;
    QStandardItemModel* m_originalModel;
    QButtonGroup *buttonGroup = new QButtonGroup(this);
    QByteArray data; // variable contenant les données reçues
    Dialog d;
    QString str;
    Arduino A; // objet temporair
    //condition arduino
    int ca=0;
 //********************* Touja *****************
    medecin M;
    medicamant ME;
    consultation CN;
    bpm B;

   ///QByteArray data;

//********************* Haithem *****************
    benevole execb;
    QString msg;
    participent exepar;
    PopUp *popUp;
    ///QByteArray data; // donnees recues
    Arduino Ar; // objet temporaire


};
#endif // MAINWINDOW_H
