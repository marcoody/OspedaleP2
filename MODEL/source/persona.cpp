#include "../header/persona.h"




Persona::Persona(string user, string pw, string no, string co, const Data& d, const gender& g): username(user), password(pw), nome(no), cognome(co), dataNascita(d), genere(g){}

string Persona::getUsername() const { return username; }
string Persona::getPassword() const { return password; }
string Persona::getNome() const { return nome; }
string Persona::getCognome() const { return cognome; }
Data Persona::getDataNascita() const { return dataNascita; }
gender Persona::getGenere() const { return genere; }

void Persona::setPassword(string& pw) { password=pw; }
void Persona::setNome(string& n) { nome=n; }
void Persona::setCognome(string& c) { cognome=c; }
void Persona::setDataNascita(const Data& d) { dataNascita=d; }
void Persona::setGenere(gender g) { genere=g; }

void Persona::exportXml(QXmlStreamWriter& out) const{
    //getTag polimorfa
    out.writeStartElement(QString::fromStdString(getTag()));
    out.writeTextElement("username", QString::fromStdString(username));
    out.writeTextElement("password", QString::fromStdString(password));
    out.writeTextElement("nome", QString::fromStdString(nome));
    out.writeTextElement("cognome", QString::fromStdString(cognome));
    out.writeTextElement("dataNascita", QString::fromStdString(dataNascita.dataToString()));
    string g;
    gender gen = getGenere();
    if(gen==0){g="maschio";}
    else if(gen==1){g="femmina";}
    else {g="altro";}
    out.writeTextElement("genere", QString::fromStdString(g));
    out.writeEndElement();
}

void Persona::importXmlData(QXmlStreamReader & in, string & username, std::string & password, string & nome, string & cognome, Data & dataNascita, gender & genere){
    importTagXml(in, "username", username);
    importTagXml(in, "password", password);
    importTagXml(in, "nome", nome);
    importTagXml(in, "cognome", cognome);
    string dataString;
    importTagXml(in, "dataNascita", dataString);
    dataNascita = stringToData(dataString);
    string genereString;
    importTagXml(in, "genere", genereString);
    if(genereString=="maschio"){genere=gender::maschio;}
    else if (genereString=="femmina"){ genere=gender::femmina;}
    else{genere=gender::altro;}
}



bool Persona::operator==(const Persona& p) const { return username==p.username && password==p.password; }
bool Persona::operator!=(const Persona& p) const { return username!=p.username || password!=p.password; }
