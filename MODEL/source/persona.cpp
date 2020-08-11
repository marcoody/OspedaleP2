#include "../header/persona.h"

Persona::Persona(string user, string pw, string no, string co, const Data& d, const gender& g, const QueueTurni& t): username(user), password(pw), nome(no), cognome(co), dataNascita(d), genere(g), turni(t){}

string Persona::getUsername() const { return username; }
string Persona::getPassword() const { return password; }
string Persona::getNome() const { return nome; }
string Persona::getCognome() const { return cognome; }
Data Persona::getDataNascita() const { return dataNascita; }
gender Persona::getGenere() const { return genere; }
QueueTurni Persona::getTurni() const {return turni; }

void Persona::setUsername(std::string & s){ username= s;}
void Persona::setPassword(string& pw) { password=pw; }
void Persona::setNome(string& n) { nome=n; }
void Persona::setCognome(string& c) { cognome=c; }
void Persona::setDataNascita(const Data& d) { dataNascita=d; }
void Persona::setGenere(gender g) { genere=g; }
void Persona::setTurni(giorni g, Turno * t) { turni[g]=t; }



string Persona::infoPersona() const{
    string s =  "Nome: " + getNome() + "\n\nCognome: " + getCognome() + "\n\nImpiego: " + getTag() +"\n\nData di nascita: " + dataNascita.dataToString() + "\n\nGenere: ";
    if (genere==0){ s += "Maschio"; }
    else if (genere==1) { s += "Femmina"; }
    else { s+= "altro"; }
    return s;
}

double Persona::stipendio() const{
    double s = 0;
    for(auto it = getTurni().begin(); it!=getTurni().end(); ++it){
       s += (*it)->paga();
    }

    return s;
}



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
    getTurni().exportXmlData(out);
    out.writeEndElement();
}

void Persona::importXmlData(QXmlStreamReader & in, string & username, std::string & password, string & nome, string & cognome, Data & dataNascita, gender & genere, QueueTurni& turni){
    importTagXml(in, "username", username);
    importTagXml(in, "password", password);
    importTagXml(in, "nome", nome);
    importTagXml(in, "cognome", cognome);
    string dataString;
    importTagXml(in, "dataNascita", dataString);
    dataNascita = stringToData(dataString);
    string genereString;
    importTagXml(in, "genere", genereString);
    if(genereString=="maschio" || genereString=="Maschio"){genere=gender::maschio;}
    else if (genereString=="femmina" ||  genereString=="Femmina"){ genere=gender::femmina;}
    else{genere=gender::altro;}
    turni.importXml(in);
}



bool Persona::operator==(const Persona& p) const { return username==p.username && password==p.password; }
bool Persona::operator!=(const Persona& p) const { return username!=p.username || password!=p.password; }
