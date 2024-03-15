QT       += core gui
QT       += core gui charts
QT += charts
QT += network
QT += printsupport
QT += printsupport
QT += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT       += core gui sql
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    benevole.cpp \
    bpm.cpp \
    connexion.cpp \
    consultation.cpp \
    dialog.cpp \
    enfant.cpp \
    etudiant.cpp \
    evenement.cpp \
    facture.cpp \
    finger.cpp \
    log_in.cpp \
    main.cpp \
    mainwindow.cpp \
    medecin.cpp \
    medicamant.cpp \
    persone.cpp \
    popup.cpp \
    smtp.cpp \
    task.cpp

HEADERS += \
    arduino.h \
    benevole.h \
    bpm.h \
    connexion.h \
    consultation.h \
    dialog.h \
    enfant.h \
    etudiant.h \
    evenement.h \
    facture.h \
    finger.h \
    log_in.h \
    mainwindow.h \
    medecin.h \
    medicamant.h \
    persone.h \
    popup.h \
    smtp.h \
    task.h

FORMS += \
    dialog.ui \
    log_in.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../Res_QT/RES.qrc \
    images.qrc
