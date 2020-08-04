#include "../header/view_medico.h"


view_medico::~view_medico(){}

void view_medico::edit() const {
    view_persona::edit();
    Medico* m = static_cast<Medico*>(p);
    string r = reparto->text().toStdString();
    bool c;
    if(chirurgia->currentText() == "Sì") {c = 1;}
    else { c = 0; }
    m->setReparto(r);
    m->setChirurgo(c);

}


void view_medico::build_field(){
    view_persona::build_field();
    Medico* m = static_cast<Medico*>(p);
    reparto = new QLineEdit();
    chirurgia = new QComboBox();

    chirurgia->addItem("Sì");
    chirurgia->addItem("No");

    reparto->setText(QString::fromStdString(m->getReparto()));
    chirurgia->currentData(m->isChirurgo());

    layout->addRow(new QLabel("Reparto: "), reparto);
    layout->addRow( new QLabel("Chirurgo: "), chirurgia);
}
