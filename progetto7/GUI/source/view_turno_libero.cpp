#include "../header/view_turno_libero.h"

view_turno_libero::~view_turno_libero(){}

void view_turno_libero::edit() const {
    view_turno::edit();
    Turno_libero* tl = dynamic_cast<Turno_libero*>(t);

    bool p;
    if(permesso->currentText() == "Si") { p = 1; }
    else { p = 0; }

    tl->setPermesso(p);

}


void view_turno_libero::build_field(){
    view_turno::build_field();

    Turno_libero* tl = dynamic_cast<Turno_libero*>(t);
    nOre->setValue(24);
    nOre->setDisabled(true);

    permesso = new QComboBox();
    permesso->addItem("Sì");
    permesso->addItem("No");
    permesso->currentData(!tl->getPermesso());

    layout->addRow(new QLabel("Permesso:"), permesso);

}
