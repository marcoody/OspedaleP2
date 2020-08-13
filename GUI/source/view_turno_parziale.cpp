#include "../header/view_turno_parziale.h"

view_turno_parziale::~view_turno_parziale(){}

void view_turno_parziale::edit() const{
    view_turno::edit();
    view_turno_regolare::edit();
    Turno_parziale* tp = dynamic_cast<Turno_parziale*>(t);

    std::string p = paga_parziale->text().toStdString();
    double paga = std::stod(p);

    tp->setPagaParziale(paga);
}


void view_turno_parziale::build_field(){
    view_turno_regolare::build_field();
    Turno_parziale* tp = dynamic_cast<Turno_parziale*>(t);

    paga_parziale = new QLineEdit();
    paga_parziale->setText(QString::fromStdString(std::to_string(tp->getPagaParziale())));

    layout->addRow(new QLabel("Retribuzione oraria: "), paga_parziale);

}

bool view_turno_parziale::check() const{
    double check = std::stoul(paga_parziale->text().toStdString());
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
