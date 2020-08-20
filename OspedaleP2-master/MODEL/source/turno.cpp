#include "../header/turno.h"
#include <QString>

Turno::Turno(giorni g, QTime i, QTime f): giornoTurno(g), inizio(i), fine(f) {}

//metodi get
giorni Turno::getGiornoTurno() const { return giornoTurno; }
QTime Turno::getInizio() const { return inizio;}
QTime Turno::getFine() const { return fine; }

std::string Turno::inizioStringa() const
{
    return std::to_string(inizio.hour())+":"+std::to_string(inizio.minute());
}

std::string Turno::fineStringa() const
{
    return std::to_string(fine.hour())+":"+std::to_string(fine.minute());
}

//metodi set
void Turno::setGiornoTurno(giorni& g) { giornoTurno=g; }
void Turno::setInizio(QTime i) { inizio=i;}
void Turno::setFine(QTime f){ fine=f;}



double Turno::TotOre() const
{
    if(fine<inizio) {
        int secInizio=(inizio.hour()*3600.0f+inizio.minute()*60.0f+inizio.second());
        int secFine=(fine.hour()*3600.0f+fine.minute()*60.0f+fine.second())+24.f*3600.0f;
        return (secFine-secInizio)/3600.0f;
    }
    else {
        int secInizio=(inizio.hour()*3600.0f+inizio.minute()*60.0f+inizio.second());
        int secFine=(fine.hour()*3600.0f+fine.minute()*60.0f+fine.second());
        return (secFine-secInizio)/3600.0f;
    }

}

//metodi export
void Turno::exportXml(QXmlStreamWriter& out) const{
    out.writeStartElement(QString::fromStdString(getTag()));
    exportXmlData(out);
    out.writeEndElement();
}
void Turno::exportXmlData(QXmlStreamWriter& out) const{
    string g = giornoToString(getGiornoTurno());
    out.writeTextElement("giornoTurno", QString::fromStdString(g));

    out.writeTextElement("OraInizio", QString::fromStdString(inizioStringa()));
    out.writeTextElement("OraFine", QString::fromStdString(fineStringa()));



}

//metodi import
void Turno::importXmlData(QXmlStreamReader& in, giorni& giornoTurno, QTime& OraInizio, QTime& OraFine){
    string giornoStringa;
    string inizioStringa;
    string fineStringa;
    importTagXml(in, "giornoTurno", giornoStringa);
    importTagXml(in, "OraInizio", inizioStringa);
    importTagXml(in, "OraFine", fineStringa);

    giornoTurno= stringToGiorni(giornoStringa);


    OraInizio= QTime::fromString(QString::fromStdString(inizioStringa));
    OraFine= QTime::fromString(QString::fromStdString(fineStringa));
}


string Turno::infoTurno() const{
    return "Tipo Turno: " + getTag() + "\nGiorno: " + (giornoToString(getGiornoTurno())) + "\nNumero di Ore: " + std::to_string(TotOre());
}

string Turno::getTag() const { return "TURNO"; }

