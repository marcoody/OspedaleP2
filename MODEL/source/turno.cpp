#include "../header/turno.h"

Turno::Turno(Data& d, u_int o): dataTurno(d), nOre(o){}

//metodi get
Data Turno::getDataTurno() const { return dataTurno; }
u_int Turno::getNOre() const { return nOre; }

//metodi set
void Turno::setDataTurno( Data& d) { dataTurno=d; }
void Turno::setNOre(u_int o) { nOre=o; }

//metodi export
void Turno::exportXml(QXmlStreamWriter& out) const{
    out.writeStartElement(QString::fromStdString(getTag()));
    exportXmlData(out);
    out.writeEndElement();
}
void Turno::exportXmlData(QXmlStreamWriter& out) const{
    out.writeTextElement("dataTurno", QString::fromStdString(getDataTurno().dataToString()));
    out.writeTextElement("nOre", QString::number(getNOre()));
}

//metodi import
void Turno::importXmlData(QXmlStreamReader& in, Data& dataTurno, u_int& nOre){
    string oreStringa;
    string dataStringa;
    importTagXml(in, "dataTurno", dataStringa);
    importTagXml(in, "nOre", oreStringa);
    dataTurno= stringToData(dataStringa);
    nOre= stoull(oreStringa);
}


string Turno::infoTurno() const{
    return "Tipo Turno: " + getTag() + "\nData: " + (getDataTurno().dataToString()) + "\nNumero di Ore: " + std::to_string(getNOre());
}

string Turno::getTag() const { return "TURNO"; }

