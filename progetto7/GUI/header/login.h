#ifndef LOGIN
#define LOGIN

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QPicture>
#include <QMessageBox>

#include "../../MODEL/header/persona.h"
#include "../../MODEL/header/queuepersone.h"

class Login : public QDialog {
    Q_OBJECT

public:
    // costruttore
    Login(QueuePersone& lista_utenti, Persona**loginUtentiRef, QWidget* parent=0);
    void clean();

public slots:
    // lista degli slot
    void tryLogin();

signals:
    void send(Persona*);

private:
    void createLayoutLogin();
    void createLoginButton();

    const QueuePersone& listaUtenti;
    Persona**loginUtenti;

    QGridLayout* layoutLogin;
    QLabel* lname;
    QLabel* lpass;
    QLabel* lImgLogin;
    QLineEdit* tname;
    QLineEdit* tpass;
    QPushButton* blogin;
};

#endif
