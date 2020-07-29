#include "../header/responsabile.h"

string Responsabile::getTag() const { return "RESPONSABILE"; }

Responsabile::Responsabile(string user, string pw, string no, string co, const Data& d, const gender& g): Persona(user, pw, no, co, d, g){}

//permessi
bool Responsabile::isResponsabile() const {return true;}
bool Responsabile::canAddTurni() const {return true;}
bool Responsabile::canEditTurni() const { return true;}

Responsabile* Responsabile::clone() const {return new Responsabile(*this);}


Persona* Responsabile::importXml(QXmlStreamReader&in){
    string username, password, nome, cognome;
    Data dataNascita;
    gender genere;

    Persona::importXmlData(in, username, password, nome, cognome, dataNascita, genere);
    return new Responsabile(username, password, nome, cognome, dataNascita, genere);
}
