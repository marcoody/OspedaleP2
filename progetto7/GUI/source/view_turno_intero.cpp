#include "../header/view_turno_intero.h"

view_turno_intero::~view_turno_intero(){}

void view_turno_intero::edit() const{
    Turno_intero* ti = dynamic_cast<Turno_intero*>(t);

    std::string p = paga_intero->text().toStdString();
    double paga = std::stod(p);

    ti->setPagaIntero(paga);
}


void view_turno_intero::build_field(){
    view_turno_regolare::build_field();
    Turno_intero* ti = dynamic_cast<Turno_intero*>(t);

    paga_intero = new QLineEdit();
    paga_intero->setText(QString::fromStdString(std::to_string(ti->getPagaIntero())));

    layout->addRow(new QLabel("Retribuzione oraria: "), paga_intero);

}

bool view_turno_intero::check() const{
    double check = (std::stoul(paga_intero->text().toStdString()));
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
