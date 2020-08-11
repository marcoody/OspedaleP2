#include "../header/login.h"

void Login::setLayoutLogin(){
    layoutLogin = new QVBoxLayout();
    userLabel = new QLabel();
    pwLabel = new QLabel();
    iconLogin = new QLabel();
    userText = new QLineEdit();
    pwText = new QLineEdit();

    //set label
    userLabel->setText("Username:");
    pwLabel->setText("Password:");

    //set icona
    QPixmap icon;
    icon.load(":/IMAGES/icona.png");
    iconLogin->setPixmap(icon.scaled(80,80));

    //setPassword
    pwText->setEchoMode(QLineEdit::Password);

    //assemblaggio
    layoutLogin->addWidget(iconLogin);
    layoutLogin->addWidget(userLabel);
    layoutLogin->addWidget(userText);
    layoutLogin->addWidget(pwLabel);
    layoutLogin->addWidget(pwText);

    setLoginButton();
    setFixedSize(280, 200);
}

void Login::setLoginButton() {
    submitLogin = new QPushButton();
    submitLogin->setText("Login");
    layoutLogin->addWidget(submitLogin);
    connect(submitLogin, SIGNAL(clicked()), this, SLOT(provaAccesso()));
}

Login::Login(QueuePersone& _utenti, Persona** _loginUser, QWidget* parent ): QDialog(parent), utenti(_utenti), loginUser(_loginUser){
    setWindowTitle("Gestionale Ospedale - Login");
    setWindowIcon(QIcon(QPixmap(":/IMAGES/icona")));

    setLayoutLogin();
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutLogin);
    setLayout(mainLayout);
}

void Login::reset() {
    userText->clear();
    pwText->clear();
    userText->setFocus();
}

void Login::provaAccesso(){
    if(utenti.checkPassword(utenti.search(userText->text().toStdString()), (pwText->text().toStdString()))){
        //send(utenti.search(userText->text().toStdString()))
        *loginUser = utenti.search(userText->text().toStdString());
        this->close();
    }
    else {
        QMessageBox error;
        if(utenti.search(userText->text().toStdString())){
            error.setText("Password errata");
            error.setWindowIcon(QIcon(QPixmap(":/IMAGES/error")));
        }
        else
        {
            error.setText("Utente non trovato");
            error.setWindowIcon(QIcon(QPixmap(":/IMAGES/warning")));
        }
        error.exec();
    }
}
