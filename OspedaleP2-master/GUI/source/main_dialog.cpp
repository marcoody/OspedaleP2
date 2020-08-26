#include "../../GUI/header/main_dialog.h"

Main_dialog::Main_dialog(QueuePersone& users, Persona* loginUser, bool& reloginRef, QWidget* parent)
    : QMainWindow(parent), utenti(users), chiamante(loginUser), relogin(reloginRef)
{
    setWindowTitle("Gestionale Ospedale");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowIcon(QIcon(QPixmap(":/IMG/ospedale")));
    setUser();
    setMenuBar();
}


void Main_dialog::setUser(){
    statoBarra = new Status_bar(QString::fromStdString(chiamante->getUsername()));
    setStatusBar(statoBarra);

    mainWidget = new Main_widget(utenti, chiamante);
    setCentralWidget(mainWidget);
    connect(mainWidget, SIGNAL(changeStatus(QString)), statoBarra, SLOT(changeStatus(QString)));
    connect(mainWidget,SIGNAL(reloginSlot()),this, SLOT(reloginSlot()));
}


void Main_dialog::setMenuBar()
{
    menubar = menuBar();
    //parent senza valore di default su alcune versioni di QT
    mbFile = new QMenu("File", nullptr);
    mbLogOut = new QAction("Cambia utente / LogOut", nullptr);
    mbEsci = new QAction("Esci", nullptr);
    mbFile->addAction(mbLogOut);
    mbFile->addSeparator();
    mbFile->addAction(mbEsci);
    menubar->addMenu(mbFile);


    connect(mbLogOut, SIGNAL(triggered(bool)), this, SLOT(reloginSlot()));
    connect(mbLogOut, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(mbEsci, SIGNAL(triggered(bool)), this, SLOT(close()));

}

void Main_dialog::reloginSlot(){
    relogin = true;
}

