#include "../header/turno.h"

Turno::Turno(giorni g, u_int o): giornoTurno(g), nOre(o){}

//metodi get
giorni Turno::getGiornoTurno() const { return giornoTurno; }
u_int Turno::getNOre() const { return nOre; }

//metodi set
void Turno::setGiornoTurno(giorni& g) { giornoTurno=g; }
void Turno::setNOre(u_int o) { nOre=o; }

//metodi export
void Turno::exportXml(QXmlStreamWriter& out) const{
    out.writeStartElement(QString::fromStdString(getTag()));
    exportXmlData(out);
    out.writeEndElement();
}
void Turno::exportXmlData(QXmlStreamWriter& out) const{
    string g = giornoToString(getGiornoTurno());
    out.writeTextElement("giornoTurno", QString::fromStdString(g));
    out.writeTextElement("nOre", QString::number(getNOre()));
}

//metodi import
void Turno::importXmlData(QXmlStreamReader& in, giorni& giornoTurno, u_int& nOre){
    string oreStringa;
    string giornoStringa;
    importTagXml(in, "giornoTurno", giornoStringa);
    importTagXml(in, "nOre", oreStringa);
    giornoTurno= stringToGiorni(giornoStringa);
    nOre= stoull(oreStringa);
}


string Turno::infoTurno() const{
    return "Tipo Turno: " + getTag() + "\nGiorno: " + (giornoToString(getGiornoTurno())) + "\nNumero di Ore: " + std::to_string(getNOre());
}

string Turno::getTag() const { return "TURNO"; }




string Turno::infoTurno() const{
    return "Tipo Turno: " + getTag() + "\nData: " + (getDataTurno().dataToString()) + "\nNumero di Ore: " + std::to_string(getNOre());
}

string Turno::getTag() const { return "TURNO"; }

