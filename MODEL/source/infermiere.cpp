#include "../header/infermiere.h"

string Infermiere::getTag() const {return "INFERMIERE"; }

double Infermiere::stipendio() const{
    double s = 0;
    for(auto it = turni.begin(); it!=turni.end(); ++it){
        s += (*it)->paga();
    }
    return s;
}


Infermiere::Infermiere(string user, string pw, string no, string co, const Data& d, const gender& g, const QueueTurni& t):Persona(user, pw, no, co, d, g), turni(t) {}


QueueTurni Infermiere::getTurni() const{ return turni; }

void Infermiere::setTurni(giorni g, Turno* t) {
    turni[g] = t;
}

//permessi
bool Infermiere::isResponsabile() const {return false;}
bool Infermiere::canAddTurni() const {return false;}
bool Infermiere::canEditTurni() const {return false;}

Infermiere* Infermiere::clone() const {return new Infermiere(*this);}

//infoPersona ereditata da Persona


void Infermiere::exportXml(QXmlStreamWriter &out) const {
    Persona::exportXml(out);
    getTurni().exportXmlData(out);

}
void Infermiere::importXmlData(QXmlStreamReader& in, QueueTurni& turni){
    turni.importXml(in);
}

Persona* Infermiere::importXml(QXmlStreamReader& in){
    string username, password, nome, cognome;
    Data dataNascita;
    gender genere;
    QueueTurni turni;

    Persona::importXmlData(in, username,password, nome, cognome, dataNascita, genere);
    Infermiere::importXmlData(in, turni);
    return new Infermiere(username, password, nome, cognome, dataNascita, genere, turni);
}
