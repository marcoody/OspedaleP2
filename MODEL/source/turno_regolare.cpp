#include "../header/turno_regolare.h"
//costruttore
Turno_regolare::Turno_regolare(Data& d, u_int o, string r): Turno(d,o), reparto(r) {};

//metodi get
string Turno_regolare::getReparto() const{ return reparto;}

//metodi set
void Turno_regolare::setReparto(string& r){ reparto=r; }

//metodi export
void Turno_regolare::exportXmlData(QXmlStreamWriter & out) const{
    Turno::exportXmlData(out);
    out.writeTextElement("reparto", QString::fromStdString(getReparto()));
}

//metodi import
void Turno_regolare::importXmlData(QXmlStreamReader& in, string& reparto){
    importTagXml(in, "reparto", reparto);
}


string Turno_regolare::infoTurno() const{
    string s=Turno::infoTurno();
    s+= "\nReparto: " + getReparto();
    return s;
}

string Turno_regolare::getTag() const{ return "REGOLARE"; }
