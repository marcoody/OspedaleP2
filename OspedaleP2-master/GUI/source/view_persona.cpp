#include "../../GUI/header/view_persona.h"


void view_persona::buildGUI(){
    build_field();
    buildButt();
}

view_persona::~view_persona() {};

void view_persona::build_field(){
    layout = new QFormLayout(this);
    username = new QLineEdit();
    password = new QLineEdit();
    nome = new QLineEdit();
    cognome = new QLineEdit();
    dataNascita = new QDateEdit();
    genere = new QComboBox();

    username->setText(QString::fromStdString(p->getUsername()));
    password->setText(QString::fromStdString(p->getPassword()));
    nome->setText(QString::fromStdString(p->getNome()));
    cognome->setText(QString::fromStdString(p->getCognome()));
    int g,m,a;
    Data d = p->getDataNascita();
    g=d.getGiorno();
    m=d.getMese();
    a=d.getAnno();
    dataNascita->setDate(QDate(a,m,g));
    genere->addItem("Maschio",0);
    genere->addItem("Femmina",1);
    genere->addItem("Altro");
    genere->currentData(p->getGenere());

    layout->addRow(new QLabel("*Username:"), username);
    layout->addRow(new QLabel("*Password:"), password);
    layout->addRow(new QLabel("*Nome:"), nome);
    layout->addRow(new QLabel("*Cognome:"), cognome);
    layout->addRow(new QLabel("*Data di nascita:"), dataNascita);
    layout->addRow(new QLabel("*Genere:"), genere);

    if(mod){ username->setDisabled(true);}

}

void view_persona::buildButt()
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

bool view_persona::check() const{
    //controllo campi obbligatori
    if( username->text() == "" || password->text() == "" || nome->text() == "" || cognome->text() == ""){
        QMessageBox msgErr;
        msgErr.setWindowTitle("Errore!");
        msgErr.setWindowIcon(QIcon(QPixmap(":/warning")));
        msgErr.setText("Controlla di aver inserito tutti i campi obbligatori");
        msgErr.exec();
        return false;
    }

    //controllo duplicati username (nome e cognome possono essere anche uguali)

    if(utenti.search(username->text().toStdString()) && !mod){
        QMessageBox avviso;
        avviso.setWindowIcon(QIcon(QPixmap(":/warning")));
        avviso.setText("Impossibile aggiungere l'utente, è già presente nel sistema");
        avviso.exec();
        return false;
    }

    return true;

}

void view_persona::edit() const{
    string u = username->text().toStdString();
    string pw = password->text().toStdString();
    string no = nome->text().toStdString();
    string co = cognome->text().toStdString();
    QDate date = dataNascita->date();
    int giorno, mese, anno;
    date.getDate(&anno, &mese, &giorno);
    string gString = genere->currentText().toStdString();
    gender g;
    if(gString == "Maschio") { g = gender::maschio; }
    else if(gString == "Femmina") { g = gender::femmina; }
    else { g = gender::altro; }
    p->setUsername(u);
    p->setPassword(pw);
    p->setNome(no);
    p->setCognome(co);
    p->setDataNascita(Data(giorno, mese, anno));
    p->setGenere(g);
}

void view_persona::checkAndEdit(){
    if(check())
    {
        edit();

        emit accept();
    }
    else
    {
        QMessageBox msgErr;
        msgErr.setWindowTitle("Errore!");
        msgErr.setWindowIcon(QIcon(QPixmap(":/error")));
        msgErr.setText("Dati invaliti!");
    }
}

void view_persona::rejectedits(){
    emit reject();
}
