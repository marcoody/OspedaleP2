#include "persona.h"
//PERSONA:
//metodi di get
unsigned short Persona::getIdPersona(){ return idPersona;}
std::string Persona::getNomePersona(){return nomePersona;}
std::string Persona::getCognPersona(){return cognPersona;}
data Persona::getDataNascita(){ return dataNascita;}
gender Persona::getGenere(){ return genere;}

//metodi per cambiare i campi modificabili
void Persona::cambiaNome(std::string& s){nomePersona=s;}
void Persona::cambiaCogn(std::string& s){cognPersona=s;}
void Persona::cambiaDataNascita(const data& d){dataNascita=d;}
void Persona::cambiaGenere(gender g){genere=g;}

Persona::Persona(unsigned short id, std::string n, std::string c, const data & d, const gender & g): idPersona(id), nomePersona(n), cognPersona(c), dataNascita(d), genere(g){}
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

Dipendente::Dipendente(unsigned short id, std::string n, std::string c, const data & d, const gender & g, bool *t):Persona(id, n,c,d,g){
    for(u_int i=0; i<7; i++){
        giorniTurno[i]=t[i];
    }
}

Dipendente::Dipendente(const Dipendente& d):Persona(d){
    for(u_int i=0; i<7; ++i){giorniTurno[i]=d.giorniTurno[i];}

}

//MEDICO:

Medico::Medico(unsigned short id, std::string n, std::string c, const data & d, const gender & g, bool * t, std::vector<const Paziente *> p):Dipendente(id,n,c,d,g,t), pazienti(p){}

Medico *Medico::clone() const{ return new Medico(*this);}

Medico::Medico(const Medico &m):Dipendente(m), pazienti(m.pazienti){}



double Medico::stipendio() const{ return pagaPerOraMedico*numGiorniLavoro();}

std::vector<const Paziente *>& Medico::getPazienti(){ return pazienti;}

void Medico::aggiungiPaziente(const Paziente *p){
    pazienti.push_back(p);
}
void Medico::togliPaziente(const Paziente *p){
    for(auto it=pazienti.begin(); it!=pazienti.end(); ++it){ if(*it==p){pazienti.erase(it);}}
}


//INFERMIERE:
Infermiere::Infermiere(unsigned short id, std::string n, std::string c, const data & d, const gender & g, bool * t, bool r):Dipendente(id,n,c,d,g,t),responsabile(r) {}

Infermiere *Infermiere::clone() const{ return new Infermiere(*this);}

double Infermiere::stipendio() const{ return pagaPerOraInf*numGiorniLavoro();}
bool Infermiere::isResponsabile() const{ return responsabile;}
void Infermiere::cambiaResponsabile(bool x){responsabile=x;}

Infermiere::Infermiere(const Infermiere& i):Dipendente(i), responsabile(i.responsabile){}



//CHIRURGIA:
Chirurgia::Chirurgia(unsigned short idm, std::string nm, std::string cm, unsigned short idi, std::string ni, std::string ci, const data & dm, const gender & gm, bool * tm, std::vector<const Paziente *> pm, const data & di, const gender & gi, bool * ti, bool ri, std::vector<const Paziente *> paz): medChirurgia( new Medico(idm,nm,cm,dm,gm,tm,pm)), infChirurgia(new Infermiere(idi,ni,ci,di,gi,ti,ri)), daOperare(paz){}


//PAZIENTE:
Paziente *Paziente::clone() const{ new Paziente(*this);}

Paziente::Paziente(unsigned short id, std::string n, std::string c, Medico* m, const data & dn, const gender & g, const data & ir, const data & fr, bool dec): Persona(id,n,c,dn,g),inizioRicovero(ir),fineRicovero(fr), deceduto(dec), medicoAssegnato(m) {}


data Paziente::getInizioRic()const{ return inizioRicovero;}
data Paziente::getFineRic() const {return fineRicovero;}
bool Paziente::isDeceduto() const {return deceduto;}
Medico* Paziente::getMedicoAssegnato() const {return medicoAssegnato;}

void Paziente::modFineRicovero(const data &d){ fineRicovero=d;}
void Paziente::modDeceduto(bool x){if(x!=deceduto)deceduto=x;}
void Paziente::modMedicoAssegnato(Medico *m){medicoAssegnato=m;}


Paziente::Paziente(const Paziente &p):Persona(p), inizioRicovero(p.inizioRicovero), fineRicovero(p.fineRicovero), deceduto(p.deceduto), medicoAssegnato(p.medicoAssegnato){};
