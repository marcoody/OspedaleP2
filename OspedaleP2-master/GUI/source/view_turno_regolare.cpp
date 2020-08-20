#include "../header/view_turno_regolare.h"

view_turno_regolare::~view_turno_regolare(){}

void view_turno_regolare::edit() const{
    view_turno::edit();
    Turno_regolare* tr = dynamic_cast<Turno_regolare*>(t);

    std::string r = reparto->text().toStdString();
    tr->setReparto(r);
}

void view_turno_regolare::build_field(){
    view_turno:: build_field();
    Turno_regolare* tr = dynamic_cast<Turno_regolare*>(t);

    reparto = new QLineEdit();
    reparto->setText(QString::fromStdString(tr->getReparto()));

    layout->addRow(new QLabel("Reparto:"), reparto);
}
