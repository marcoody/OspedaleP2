#include "../header/aepersona.h"

AEPersona::AEPersona(QueuePersone& lista, Persona* toEdit, QWidget* parent) : QDialog(parent), utenti(lista), p(toEdit){
    bool ed = 0;
    if(p->getUsername() == ""){
        setWindowTitle("Creazione nuovo utente");
        ed = false;
    }
    else{
        setWindowTitle("Modifica utente");
        ed = true;
     }

    setWindowIcon(QIcon(QPixmap(":/IMG/dialog")));

    layout = new QFormLayout(this);
    if(view_persona* vp = view_UserBuilder::build(utenti, p, ed))
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
        setWindowIcon(QIcon(QPixmap(":/IMG/error")));
    }
}

