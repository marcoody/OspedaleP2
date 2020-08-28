#include "../header/view_medico.h"


view_medico::~view_medico(){}

void view_medico::edit() const {
    view_persona::edit();
    Medico* m = static_cast<Medico*>(p);
    string s = specializzazione->text().toStdString();
    bool c;
    if(chirurgia->currentText() == "Sì") {c = 1;}
    else { c = 0; }
    m->setSpecializzazione(s);
    m->setChirurgo(c);

}


void view_medico::build_field(){
    view_persona::build_field();
    Medico* m = static_cast<Medico*>(p);
    specializzazione = new QLineEdit();
    chirurgia = new QComboBox();

    chirurgia->addItem("Sì");
    chirurgia->addItem("No");

    specializzazione->setText(QString::fromStdString(m->getSpecializzazione()));
    chirurgia->currentData(!m->isChirurgo());

    layout->addRow(new QLabel("Specializzazione: "), specializzazione);
    layout->addRow( new QLabel("Chirurgo: "), chirurgia);
}
