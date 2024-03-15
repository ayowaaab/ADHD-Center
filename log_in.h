#ifndef LOG_IN_H
#define LOG_IN_H
#include "finger.h"
#include <QDialog>

namespace Ui {
class Log_in;
}

class Log_in : public QDialog
{
    Q_OBJECT

public:
    explicit Log_in(QWidget *parent = nullptr);
    ~Log_in();

private slots:
    void on_signin_clicked();
    void update_label4();

private:
    Ui::Log_in *ui;
    finger f;
    QByteArray data;
};

#endif // LOG_IN_H
