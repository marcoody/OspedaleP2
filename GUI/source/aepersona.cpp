#include "../header/aepersona.h"

AEPersona::AEPersona(QueuePersone& lista, Persona* toEdit, QWidget* parent) : QDialog(parent), utenti(lista), p(toEdit){
    if(p->getUsername() == "")
        setWindowTitle("Creazione nuovo utente");
    else
        setWindowTitle("Modifica utente");
    setWindowIcon(QIcon(QPixmap(":/dialog")));

    layout = new QFormLayout(this);
    if(view_persona* vp = view_UserBuilder::build(utenti, p))
    {
        vp->buildGUI();
        layout->addWidget(vp);

        connect(vp, SIGNAL(accept()), this, SLOT(accept()));
        connect(vp, SIGNAL(reject()), this, SLOT(reject()));
    }
    else
    {
        //in caso di nullprt
        layout->addRow(new QLabel("L'oggetto passato è invalido, impossibile proseguire"));
        setWindowIcon(QIcon(QPixmap(":/error")));
    }
}

