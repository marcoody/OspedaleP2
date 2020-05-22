#include "persona.h"
//PERSONA:

/* Costruttore di Persona
* param id: Identificativo
* param n:  Nome
* param c:  Cognome
* param d:  Data di Nascita
* param g:  Genere
*/
Persona::Persona(unsigned short id, string n, string c, const data& d, const gender& g) : 
  idPersona(id), nomePersona(n), cognPersona(c), dataNascita(d), genere(g) {}

// Costruttore di copia di Persona
Persona::Persona(const Persona& p){
    idPersona = p.idPersona;
    nomePersona = p.nomePersona;
    cognPersona = p.cognPersona;
    dataNascita = p.dataNascita;
    genere = p.genere;
}

// Metodi di Get
unsigned short Persona::getIdPersona() const { return idPersona; }
string Persona::getNomePersona() const { return nomePersona; }
string Persona::getCognPersona() const { return cognPersona; }
data Persona::getDataNascita() const { return dataNascita; }
gender Persona::getGenere() const { return genere; }

// Metodi di Set
void Persona::cambiaNome(string& s) { nomePersona = s; }
void Persona::cambiaCogn(string& s) { cognPersona = s; }
void Persona::cambiaDataNascita(const data& d) { dataNascita = d; }
void Persona::cambiaGenere(gender g) { genere = g; }

//DIPENDENTE:

/* Costruttore di Dipendente
* param id: Identificativo
* param n:  Nome
* param c:  Cognome
* param d:  Data di Nascita
* param g:  Genere
* param t:  Array booleano
*/
Dipendente::Dipendente(unsigned short id, string n, string c, const data& d, const gender& g, bool* t) :Persona(id, n, c, d, g) {
  for(u_int i = 0; i < 7; i++){
    giorniTurno[i] = t[i];
  }
}

// Costruttore di Copia di Dipendente
Dipendente::Dipendente(const Dipendente& d) : Persona(d) {
  for(u_int i = 0; i < 7; ++i) { giorniTurno[i] = d.giorniTurno[i]; }
}

// Metodi di Get
unsigned short Dipendente::numGiorniLavoro() const {
    u_int tot = 0;
    for(u_int i = 0; i < 7; ++i) { tot += giorniTurno[i]; }
    return tot;
}
// param g: Riferimento costante ad enumerazione
bool Dipendente::inTurno(const giorni& g) const { return giorniTurno[g]; }
void Dipendente::prendiPermesso(const giorni& g) { if(inTurno(g)) giorniTurno[g] = 0; }

//MEDICO:

/* Costruttore di Medico
* param id: Identificativo
* param n:  Nome
* param c:  Cognome
* param d:  Data di Nascita
* param g:  Genere
* param t:  Array booleano
* param p:  Vettore di puntatori ad oggetti di tipo Paziente 
*/
Medico::Medico(unsigned short id, string n, string c, const data& d, const gender& g, bool * t, vector<const Paziente*> p) :
  Dipendente(id, n, c, d, g, t), pazienti(p) {}

// Costruttore di Copia di Medico
Medico::Medico(const Medico &m) : Dipendente(m), pazienti(m.pazienti) {}

Medico* Medico::clone() const { return new Medico(*this); }

double Medico::stipendio() const { return pagaPerOraMedico * numGiorniLavoro(); }

vector<const Paziente*>& Medico::getPazienti() const { return pazienti; }

void Medico::aggiungiPaziente(const Paziente* p) { pazienti.push_back(p); }

void Medico::togliPaziente(const Paziente* p) {
  vector<const Paziente*>::iterator it;
  for(it = pazienti.begin(); it != pazienti.end(); ++it) {
    if(*it == p) { pazienti.erase(it); }
  }
}

//INFERMIERE:

/* Costruttore di Infermiere
* param id: Identificativo
* param n:  Nome
* param c:  Cognome
* param d:  Data di Nascita
* param g:  Genere
* param t:  Array booleano
* param p:  Vettore di puntatori ad oggetti di tipo Paziente 
* param r:  Valore Booleano, se true => responsabile
*/
Infermiere::Infermiere(unsigned short id, string n, string c, const data& d, const gender& g, bool* t, bool r) :
   Dipendente(id, n, c, d, g, t), responsabile(r) {}

// Costruttore di Copia di Infermiere
Infermiere::Infermiere(const Infermiere& i) : Dipendente(i), responsabile(i.responsabile) {}

Infermiere* Infermiere::clone() const { return new Infermiere(*this); }

double Infermiere::stipendio() const { return pagaPerOraInf * numGiorniLavoro(); }
bool Infermiere::isResponsabile() const { return responsabile; }
void Infermiere::cambiaResponsabile(bool x) { responsabile = x; }

//CHIRURGIA:

/* Costruttore di Chirurgia
* param idm: Identificativo Medico
* param nm:  Nome Medico
* param cm:  Cognome Medico
* param dm:  Data di Nascita
* param gm:  Genere del Medico
* param tm:  Array booleano
* param pm:  Vettore di puntatori ad oggetti di tipo Paziente 
* param idi: Identificativo Infermiere
* param ni:  Nome Infermiere
* param ci:  Cognome Infermiere
* param di:  Data di Nascita
* param gi:  Genere
* param ti:  Array booleano
* param ri:  Valore Booleano, se true => responsabile
* param paz:   Vettore di puntatori ad oggetti di tipo Paziente
*/
Chirurgia::Chirurgia(
  // Medico
  unsigned short idm, string nm, string cm, const data& dm, const gender& gm, bool* tm, vector<const Paziente*> pm,
  // Infermiere
  unsigned short idi, string ni, string ci, const data& di, const gender& gi, bool* ti, bool ri, 
  // Paziente
  vector<const Paziente*> paz) :
  medChirurgia(new Medico(idm, nm, cm, dm, gm, tm, pm)), 
  infChirurgia(new Infermiere(idi, ni, ci, di, gi, ti, ri)),
  daOperare(paz) {}

//PAZIENTE:

/* Costruttore di paziente
* param id: Identificativo
* param n:  Nome
* param c:  Cognome
* param d:  Data di Nascita
* param g:  Genere
* param ir: Inizio Ricovero
* param fr: Fine Ricovero
* param dec: Booleano
* param m: Puntatore ad oggetto di tipo Medico
*/
Paziente::Paziente(unsigned short id, string n, string c, const data& d, const gender& g, const data& ir, const data& fr, bool dec, Medico* m) :
  Persona(id, n, c, d, g), inizioRicovero(ir), fineRicovero(fr), deceduto(dec), medicoAssegnato(m) {}

// Costruttore di Copia di Paziente
Paziente::Paziente(const Paziente& p) : Persona(p), inizioRicovero(p.inizioRicovero), fineRicovero(p.fineRicovero), deceduto(p.deceduto), medicoAssegnato(p.medicoAssegnato) {};

Paziente* Paziente::clone() const { return new Paziente(*this); }

data Paziente::getInizioRic() const { return inizioRicovero; }
data Paziente::getFineRic() const { return fineRicovero; }
bool Paziente::isDeceduto() const { return deceduto; }
Medico* Paziente::getMedicoAssegnato() const { return medicoAssegnato; }

void Paziente::modFineRicovero(const data& d) { fineRicovero = d; }
void Paziente::modDeceduto(bool x){ if(x != deceduto) deceduto = x; }
void Paziente::modMedicoAssegnato(Medico* m) { medicoAssegnato = m; }
