#include "../../GUI/header/view_turno.h"


void view_turno::buildGUI(){
    build_field();
    buildButt();
}

view_turno::~view_turno() {};


void view_turno::build_field(){
    layout = new QFormLayout(this);
    nOre = new QSpinBox();
    oraInizio= new QTimeEdit();
    oraFine= new QTimeEdit();

    nOre->setRange(0,12);
    nOre->setValue(t->TotOre());

    layout->addRow(new QLabel("*Numero di ore:"), nOre);
    layout->addRow(new QLabel("*Ore di Inizio:"), oraInizio);
    layout->addRow(new QLabel("*Ore di Fine:"), oraFine);
}

void view_turno::buildButt()
{
    annullaButt = new QPushButton();
    okButt = new QPushButton();
    annullaButt->setText("Annulla");
    annullaButt->setFixedWidth(200);
    okButt->setText("Ok");
    okButt->setFixedWidth(200);
    okButt->setFocus();
    layout->addRow(annullaButt, okButt);
    layout->addRow(new QLabel("I campi contraddistinti dall'asterisco (*) sono obbligatori"));

    connect(annullaButt, SIGNAL(clicked()), this, SLOT(rejectedits()));
    connect(okButt, SIGNAL(clicked()), this, SLOT(checkAndEdit()));
}

bool view_turno::check() const {
    return true;
}

void view_turno::edit() const {
    t->setInizio(oraInizio->time());
    t->setFine(oraFine->time());

}

void view_turno::checkAndEdit(){
    if(check()){
        edit();

        emit accept();
    }
    else {
        QMessageBox msgErr;
        msgErr.setWindowTitle("Errore!");
        msgErr.setWindowIcon(QIcon(QPixmap(":/error")));
        msgErr.setText("Dati invalidi!");
    }
}

void view_turno::rejectedits(){
    emit reject();
}

