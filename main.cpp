#include "mainwindow.h"
#include "log_in.h"
#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Log_in l;
    l.show();





    return a.exec();
}
