#ifndef MAIN_DIALOG_H
#define MAIN_DIALOG_H

#include <QMainWindow>
#include <QStatusBar>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QString>
#include <QMessageBox>
#include <QString>

#include "../../MODEL/header/queuepersone.h"
#include "../../GUI/header/main_widget.h"
#include "../../GUI/header/status_bar.h"
#include <string>

class Main_dialog: public QMainWindow{
    Q_OBJECT
public:
    Main_dialog(QueuePersone& users, Persona* loginUser, bool& reloginRef, QWidget* parent = 0);

private:
    Status_bar* statoBarra;
    Main_widget* mainWidget;
    QMenuBar* menubar;
    QMenu* mbFile;
    QMenu* mbTools;
    QMenu* mbInfo;
    QAction* mbLogOut;
    QAction* mbEsci;

    QueuePersone& utenti;
    Persona* chiamante;
    bool& relogin;
    void setUser();
    void setMenuBar();

public slots:
    void reloginSlot();

};

#endif // MAIN_DIALOG_H
