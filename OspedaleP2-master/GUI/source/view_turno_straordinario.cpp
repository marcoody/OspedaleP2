#include "../header/view_turno_straordinario.h"

view_turno_straordinario::~view_turno_straordinario(){}


void view_turno_straordinario::edit() const{
    view_turno_regolare::edit();
    edit_only_libero();
    Turno_straordinario* ts = dynamic_cast<Turno_straordinario*>(t);

    std::string p = paga_straordinario->text().toStdString();
    double paga = std::stod(p);
    ts->setPagaStraordinario(paga);

    bool v;
    if(volontariato->currentText()=="Sì"){ v=1; }
    else { v=0; }
    ts->setVolontariato(v);
}


void view_turno_straordinario::build_field(){
    view_turno_regolare::build_field();
    build_field_only_libero();

    oraInizio->setDisabled(false);
    oraFine->setDisabled(false);
    permesso->setDisabled(true);

    Turno_straordinario* ts = dynamic_cast<Turno_straordinario*>(t); 
    paga_straordinario = new QLineEdit();
    paga_straordinario->setText(QString::fromStdString(std::to_string(ts->getPagaStraordinario())));
    volontariato = new QComboBox();
    volontariato->addItem("Sì");
    volontariato->addItem("No");
    volontariato->currentData(ts->getVolontariato());
    layout->addRow(new QLabel("volontariato: "), volontariato);
    layout->addRow(new QLabel("Retribuzione oraria: "), paga_straordinario);

}

bool view_turno_straordinario::check() const{
    double check = std::stoul(paga_straordinario->text().toStdString());
    if( check < 0){
        QMessageBox msgErr;
        msgErr.setWindowTitle("Errore!");
        msgErr.setWindowIcon(QIcon(QPixmap(":/warning")));
        msgErr.setText("Retribuzione negativa non valida");
        msgErr.exec();
        return false;
    }
    return true;

}
