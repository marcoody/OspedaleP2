#include "../header/persona.h"




Persona::Persona(string user, string pw, string no, string co, const Data& d, const gender& g): username(user), password(pw), nome(no), cognome(co), dataNascita(d), genere(g){}

string Persona::getUsername() const { return username; }
string Persona::getPassword() const { return password; }
string Persona::getNome() const { return nome; }
string Persona::getCognome() const { return cognome; }
Data Persona::getDataNascita() const { return dataNascita; }
gender Persona::getGenere() const { return genere; }

void Persona::setUsername(std::string & s){ username= s;}

void Persona::setPassword(string& pw) { password=pw; }
void Persona::setNome(string& n) { nome=n; }
void Persona::setCognome(string& c) { cognome=c; }
void Persona::setDataNascita(const Data& d) { dataNascita=d; }
void Persona::setGenere(gender g) { genere=g; }



string Persona::infoPersona() const{
    string s =  "Nome: " + getUsername() + "\nCognome: " + getCognome() + "\nImpiego: " + getTag() +"\nData di nascita: " + dataNascita.dataToString() + "\nGenere: ";
    if (genere==0){ s += "Maschio"; }
    else if (genere==1) { s += "Femmina"; }
    else { s+= "altro"; }
    return s;
}
