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
#include "../../MODEL/header/queuepersone.h"
#include "../../MODEL/header/persona.h"
#include "../../GUI/header/aepersona.h"
#include "../../MODEL/header/userbuilder.h"

class Main_widget: public QWidget {
    Q_OBJECT
public:
    Main_widget (QueuePersone& _utenti, Persona* utenteAttuale, QWidget* parent=0);

private:
    QueuePersone& utenti;
    QGridLayout* grid;
    Persona* chiamante;
    QPushButton* addButt, *editButt, *deleteButt, *turnoButt;
    QPushButton* stipendioButt, *sortName;
    QListWidget*  elenco;
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
    void refreshDelete();
    void refreshStipendio();
    void refreshTurno(); //i responsabili non hanno turno, quindi se selez un responsabile, il suo bottone tueno non deve comparire
    void deleteSelected();
    void calculateStipendio();
    //void editTurno();
    void editPersona();
    void addPersona();
    void filtra();
    void sortByName();


};
#endif // MAIN_WIDGET_H
