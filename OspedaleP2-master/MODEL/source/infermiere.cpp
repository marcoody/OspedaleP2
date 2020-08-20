#include "../header/infermiere.h"

string Infermiere::getTag() const {return "INFERMIERE"; }


Infermiere::Infermiere(string user, string pw, string no, string co, const Data& d, const gender& g, const QueueTurni& t):Persona(user, pw, no, co, d, g, t){}


//permessi
bool Infermiere::isResponsabile() const {return false;}
bool Infermiere::canAddTurni() const {return false;}
bool Infermiere::canEditTurni() const {return false;}

Infermiere* Infermiere::clone() const {return new Infermiere(*this);}

//infoPersona impoertXmlData e exportXml ereditati da Persona



Persona* Infermiere::importXml(QXmlStreamReader& in){
    string username, password, nome, cognome;
    Data dataNascita;
    gender genere;
    QueueTurni turni;

    Persona::importXmlData(in, username,password, nome, cognome, dataNascita, genere, turni);
    return new Infermiere(username, password, nome, cognome, dataNascita, genere, turni);
}
