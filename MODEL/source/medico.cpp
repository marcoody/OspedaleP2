#include "../header/medico.h"

string Medico::getTag() const {return "MEDICO";}

double Medico::stipendio() const{
    double s = 0;
    for(auto it = turni.begin(); it!=turni.end(); ++it){
        s += (*it)->paga();
    }
    return s;
}

Medico::Medico(string user, string pw, string no, string co, const Data& d, const gender& g, string rep, bool chir,const QueueTurni& t): Persona(user, pw, no, co, d, g), reparto(rep), chirurgo(chir), turni(t) {}

//get
string Medico::getReparto() const {return reparto; }
bool Medico::isChirurgo() const { return chirurgo; }

QueueTurni Medico::getTurni() const{ return turni;}

//set
void Medico::setReparto(string& r) { reparto=r; }
void Medico::setChirurgo(bool c) { chirurgo=c;}

void Medico::setTurno(giorni g, Turno*change){
    turni[g] = change;
}


//permessi
bool Medico::isResponsabile() const { return false; }
bool Medico::canAddTurni() const {return false;}
bool Medico::canEditTurni() const { return true; }

Medico* Medico::clone() const { return new Medico(*this); }

string Medico::infoPersona() const {
    string s=Persona::infoPersona();
    s+= "\nReparto: " + getReparto() + "\nChirurgo: ";
    if(isChirurgo()){ s += "Sì";}
    else { s += "No"; }
    return s;
}

void Medico::exportXml(QXmlStreamWriter & out) const{
    Persona::exportXml(out);
    out.writeTextElement("reparto", QString::fromStdString(getReparto()));
    out.writeTextElement("chirurgo", QString::fromStdString(isChirurgo()==0 ? "0" : "1"));
    getTurni().exportXmlData(out);
}

void Medico::importXmlData(QXmlStreamReader& in, string& reparto, bool& chirurgo, QueueTurni& turni){
    importTagXml(in, "reparto", reparto);
    string chirurgoString;
    importTagXml(in, "chirurgo", chirurgoString);
    chirurgo = chirurgoString=="0" ? 0:1;
    turni.importXml(in);
}
Persona* Medico::importXml(QXmlStreamReader& in){
    string username, password, nome, cognome, reparto;
    Data dataNascita;
    gender genere;
    bool chirurgo;
    QueueTurni turni;

    Persona::importXmlData(in, username,password, nome, cognome, dataNascita, genere);
    Medico::importXmlData(in, reparto, chirurgo, turni);
    return new Medico(username, password, nome, cognome, dataNascita, genere, reparto, chirurgo, turni);
}
