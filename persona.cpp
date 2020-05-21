#include "persona.h"
//PERSONA:
//metodi di get
unsigned short Persona::getIdPersona(){ return idPersona;}
string Persona::getNomePersona(){return nomePersona;}
string Persona::getCognPersona(){return cognPersona;}
data Persona::getDataNascita(){ return dataNascita;}
gender Persona::getGenere(){ return genere;}

//metodi per cambiare i campi modificabili
void Persona::setNome(string& s){nomePersona=s;}
void Persona::setCogn(string& s){cognPersona=s;}
void Persona::setdataNascita(const data& d){dataNascita=d;}
void Persona::setGenere(gender g){genere=g;}

Persona::Persona(unsigned short id, string n, string c, const data & d, const gender & g): idPersona(id), nomePersona(n), cognPersona(c), dataNascita(d), genere(g){}
Persona::Persona(const Persona & p){
    idPersona=p.idPersona;
    nomePersona=p.nomePersona;
    cognPersona=p.cognPersona;
    dataNascita=p.dataNascita;
    genere=p.genere;
}

//DIPENDENTE:
//metodi di get
bool Dipendente::inTurno(const giorni &g) const{ return giorniTurno[g]; }
unsigned short Dipendente::numGiorniLavoro() const{
    u_int tot=0;
    for(u_int i=0; i<7; ++i){tot+=giorniTurno[i];}
    return tot;
}
void Dipendente::prendiPermesso(const giorni &g){ if(inTurno(g))giorniTurno[g]=0;}

Dipendente::Dipendente(unsigned short id, string n, string c, const data & d, const gender & g, bool *t):Persona(id, n,c,d,g){
    for(u_int i=0; i<7; i++){
        giorniTurno[i]=t[i];
    }
}

Dipendente::Dipendente(const Dipendente& d) : Persona(d) {
    for(u_int i=0; i<7; ++i){giorniTurno[i]=d.giorniTurno[i];}
}

//MEDICO:

Medico::Medico(unsigned short id, string n, string c, const data & d, const gender & g, bool * t, vector<const Paziente *> p):Dipendente(id,n,c,d,g,t), pazienti(p){}


double Medico::stipendio() const{ return pagaPerOraMedico*numGiorniLavoro();}

vector<const Paziente *>& Medico::getPazienti(){ return pazienti;}

void Medico::aggiungiPaziente(const Paziente *p){
    pazienti.push_back(p);
}
void Medico::togliPaziente(const Paziente *p){
    for(auto it=pazienti.begin(); it!=pazienti.end(); ++it){ if(*it==p){pazienti.erase(it);}}
}


//INFERMIERE:
Infermiere::Infermiere(unsigned short id, string n, string c, const data & d, const gender & g, bool * t, bool r):Dipendente(id,n,c,d,g,t),responsabile(r) {}

double Infermiere::stipendio() const{ return pagaPerOraInf*numGiorniLavoro();}
bool Infermiere::isResponsabile() const{ return responsabile;}
void Infermiere::cambiaResponsabile(bool x){responsabile=x;}

//CHIRURGIA:



//CHIRURGIA:
Paziente::Paziente(unsigned short id, string n, string c, const Medico * m, const data & dn, const gender & g, const data & ir, const data & fr, bool dec) :
  Persona(id,n,c,dn,g), medicoAssegnato(m), inizioRicovero(ir),fineRicovero(fr), deceduto(dec) {};

