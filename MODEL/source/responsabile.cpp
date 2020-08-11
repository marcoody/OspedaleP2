#include "../header/responsabile.h"

string Responsabile::getTag() const { return "RESPONSABILE"; }


Responsabile::Responsabile(string user, string pw, string no, string co, const Data& d, const gender& g, const QueueTurni& t): Persona(user, pw, no, co, d, g, t){}

//permessi
bool Responsabile::isResponsabile() const {return true;}
bool Responsabile::canAddTurni() const {return true;}
bool Responsabile::canEditTurni() const { return true;}

Responsabile* Responsabile::clone() const {return new Responsabile(*this);}


Persona* Responsabile::importXml(QXmlStreamReader&in){
    string username, password, nome, cognome;
    Data dataNascita;
    gender genere;
    QueueTurni turni;

    Persona::importXmlData(in, username, password, nome, cognome, dataNascita, genere, turni);
    return new Responsabile(username, password, nome, cognome, dataNascita, genere, turni);
}
