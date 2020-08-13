#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QScrollArea>
#include <QListWidget>
#include <QRadioButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QSignalMapper>
#include "../../MODEL/header/queuepersone.h"
#include "../../MODEL/header/persona.h"
#include "../../GUI/header/aepersona.h"
#include "../../MODEL/header/userbuilder.h"
#include "../../GUI/header/turniwidget.h"
#include "../../GUI/header/eturno.h"
#include <iostream>

class Main_widget: public QWidget {
    Q_OBJECT
public:
    Main_widget (QueuePersone& _utenti, Persona* utenteAttuale, QWidget* parent=0);

private:
    QueuePersone& utenti;
    QGridLayout* grid;
    Persona* chiamante;
    QPushButton* addButt, *editButt, *deleteButt;
    QPushButton* stipendioButt, *sortName;
    QListWidget*  elenco;
    turniWidget* turniwidget;
    QLabel* info;
    QScrollArea* infoView;

    QLineEdit* search;
    QHBoxLayout* radioLayout;
    QRadioButton* radioMedico;
    QRadioButton* radioInfermiere;
    QRadioButton* radioResponsabile;
    QRadioButton* radioTutti;
    QLabel* cercaLabel;


    void refreshElenco();
    void showInfoElement();
    void createSearch();
    void refreshInfo();
    void clearSelection();

signals:
    void changeStatus(QString state);
    void reloginSlot();

private slots:
    void showInfoPersona();
    void refreshTurniWidget();
    void refreshDelete();
    void refreshEdit();
    void refreshAdd();
    void refreshStipendio();
    void deleteSelected();
    void calculateStipendio();
    void editPersona();
    void addPersona();
    void filtra();
    void sortByName();
    void editTurno(int);
    void lunclicked();
    void marclicked();
    void merclicked();
    void gioclicked();
    void venclicked();
    void sabclicked();
    void domclicked();


};
#endif // MAIN_WIDGET_H
