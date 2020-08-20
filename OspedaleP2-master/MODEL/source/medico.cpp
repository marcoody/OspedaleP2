#include "../header/medico.h"

string Medico::getTag() const {return "MEDICO";}


Medico::Medico(string user, string pw, string no, string co, const Data& d, const gender& g, const QueueTurni& t, string rep, bool chir): Persona(user, pw, no, co, d, g, t), reparto(rep), chirurgo(chir){}

//get
string Medico::getReparto() const {return reparto; }
bool Medico::isChirurgo() const { return chirurgo; }


//set
void Medico::setReparto(string& r) { reparto=r; }
void Medico::setChirurgo(bool c) { chirurgo=c;}



//permessi
bool Medico::isResponsabile() const { return false; }
bool Medico::canAddTurni() const {return false;}
bool Medico::canEditTurni() const { return true; }

Medico* Medico::clone() const { return new Medico(*this); }

string Medico::infoPersona() const {
    string s=Persona::infoPersona();
    s+= "\n\nReparto: " + getReparto() + "\n\nChirurgo: ";
    if(isChirurgo()){ s += "Sì";}
    else { s += "No"; }
    return s;
}

void Medico::exportXml(QXmlStreamWriter & out) const{
    Persona::exportXml(out);
    out.writeTextElement("reparto", QString::fromStdString(getReparto()));
    out.writeTextElement("chirurgo", QString::fromStdString(isChirurgo()==0 ? "0" : "1"));
}

void Medico::importXmlData(QXmlStreamReader& in, string& reparto, bool& chirurgo){
    importTagXml(in, "reparto", reparto);
    string chirurgoString;
    importTagXml(in, "chirurgo", chirurgoString);
    chirurgo = chirurgoString=="0" ? 0:1;
}

Persona* Medico::importXml(QXmlStreamReader& in){
    string username, password, nome, cognome, reparto;
    Data dataNascita;
    gender genere;
    bool chirurgo;
    QueueTurni turni;

    Persona::importXmlData(in, username,password, nome, cognome, dataNascita, genere, turni);
    Medico::importXmlData(in, reparto, chirurgo);
    return new Medico(username, password, nome, cognome, dataNascita, genere, turni, reparto, chirurgo);
}
