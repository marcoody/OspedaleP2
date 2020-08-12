#include "../header/eturno.h"

ETurno::ETurno(Turno* toEdit, QWidget* parent) : QDialog(parent), t(toEdit){
    setWindowTitle("Modifica turno");
    setWindowIcon(QIcon(QPixmap(":/dialog")));

    layout = new QFormLayout(this);

    if(view_turno* vt = view_UserBuilder::buildT(t))
    {
        vt->buildGUI();
        layout->addWidget(vt);

        connect(vt, SIGNAL(accept()), this, SLOT(accept()));
        connect(vt, SIGNAL(reject()), this, SLOT(reject()));
    }
    else
    {
        //in caso di nullprt
        layout->addRow(new QLabel("L'oggetto passato è invalido, impossibile proseguire"));
        setWindowIcon(QIcon(QPixmap(":/error")));
    }

}

