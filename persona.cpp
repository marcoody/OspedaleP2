#include "persona.h"
//PERSONA:

//operatori
bool Persona::operator==(const Persona & p) const{ return idPersona==p.idPersona;}
bool Persona::operator!=(const Persona & p) const{ return idPersona!=p.idPersona;}

//metodi di get
u_int Persona::getIdPersona(){ return idPersona;}
string Persona::getNomePersona(){return nomePersona;}
string Persona::getCognPersona(){return cognPersona;}
Data Persona::getDataNascita(){ return dataNascita;}
gender Persona::getGenere(){ return genere;}

// Metodi di Set (NON SI PUò CAMBIARE ID_PERSONA)
void Persona::cambiaNome(string& s){nomePersona=s;}
void Persona::cambiaCogn(string& s){cognPersona=s;}
void Persona::cambiaDataNascita(const Data& d){dataNascita=d;}
void Persona::cambiaGenere(gender g){genere=g;}

//PROTECTED: (li metto solo per poter creare costruttori e operatori vari nelle sottoclassi)

/* Costruttore di Persona
* param id: Identificativo
* param n:  Nome
* param c:  Cognome
* param d:  Data di Nascita
* param g:  Genere
*/
Persona::Persona(u_int id, string n, string c, const Data& d, const gender& g): idPersona(id), nomePersona(n), cognPersona(c), dataNascita(d), genere(g){};

// Costruttore di copia di Persona
Persona::Persona(const Persona& p):idPersona(p.idPersona),nomePersona(p.nomePersona), cognPersona(p.cognPersona), dataNascita(p.dataNascita), genere(p.genere){}


Persona& Persona::operator=(const Persona& p){
   if(&p!= this){
       idPersona=p.idPersona;
       nomePersona=p.nomePersona;
       cognPersona=p.cognPersona;
       dataNascita=p.dataNascita;
       genere=p.genere;
   }
   return *this;
}

/////////////////////////////////////////////////////////////////////////////////////

//DIPENDENTE:

//metodi di get
bool Dipendente::inTurno(const giorni &g) const{ return giorniTurno.inturno(g);}
u_int Dipendente::numGiorniLavoro() const{ return giorniTurno.giornilavoro(); }
void Dipendente::cambiaTurno(const giorni& g1, const giorni& g2){ return giorniTurno.switchturno(g1,g2);}

void Dipendente::aggiungiTurno(const giorni &g){
    try{giorniTurno.addTurno(g);}
    catch(Errori){ std::cerr<<"Errore: turno già esistente. Riprovare.";}
}
void Dipendente::eliminaTurno(const giorni &g){
    try{giorniTurno.delTurno(g);}
    catch(Errori){ std::cerr<<"Errore: turno già libero. Riprovare";}
}

//protected:

/* Costruttore di Dipendente
* param id: Identificativo
* param n:  Nome
* param c:  Cognome
* param d:  Data di Nascita
* param g:  Genere
* param t:  Array booleano
*/
Dipendente::Dipendente(u_int id, string n, string c, const Data & d, const gender & g, const Turno& t):Persona(id,n,c,d,g), giorniTurno(t){}

// Costruttore di Copia di Dipendente
Dipendente::Dipendente(const Dipendente& d):Persona(d), giorniTurno(d.giorniTurno){}

Dipendente &Dipendente::operator=(const Dipendente & d){
    if(&d!=this){
        this->Persona::operator=(d);
        giorniTurno=d.giorniTurno;
    }
    return *this;
}


/////////////////////////////////////////////////////////////////////////////////////

//MEDICO:
double Medico::pagaPerOraMedico=25.0;

/* Costruttore di Medico
* param id: Identificativo
* param n:  Nome
* param c:  Cognome
* param d:  Data di Nascita
* param g:  Genere
* param t:  Array booleano
* param p:  Vettore di puntatori ad oggetti di tipo Paziente
*/
Medico::Medico(u_int id, string n, string c, const Data & d, const gender & g, const Turno& t, vector<Paziente *> p):Dipendente(id,n,c,d,g,t){
    if(p.empty()){pazienti=p;}
    else{
        for(auto it=p.begin(); it!=p.end(); ++it){
            if((*it)->getMedicoAssegnato()!=this){throw std::runtime_error("Pazienti non assegnati a tale medico");}
        }
        pazienti=p;
    }
}
Medico::~Medico(){ pazienti.clear();}
Medico *Medico::clone() const{ return new Medico(*this);}
// Costruttore di Copia di Medico
Medico::Medico(const Medico &m):Dipendente(m), pazienti(m.pazienti){}

Medico &Medico::operator=(const Medico& m){
    if(&m!=this){
        this->Dipendente::operator=(m);
        pazienti.clear();
        pazienti=m.pazienti;
    }
    return *this;
}

double Medico::stipendio() const{ return pagaPerOraMedico*numGiorniLavoro()*8;}

vector<Paziente *>& Medico::getPazienti(){ return pazienti;}

vector<Paziente*>::iterator Medico::pazienteInLista(Paziente *p){
    for(auto it=pazienti.begin(); it!=pazienti.end(); ++it){
        if(*it==p){ return it;}
    }
    return pazienti.end();
}

void Medico::aggiungiPaziente(Paziente *p){
    (p->getMedicoAssegnato())->cediPaziente(p,this);
}

void Medico::cediPaziente(Paziente *p, Medico* m){
    if(m!=this){
        vector<Paziente*>::iterator it=pazienteInLista(p);
        if(it!=pazienti.end()){
            (*p).medicoAssegnato=m;
            (*m).pazienti.push_back(p);
            pazienti.erase(it);
        }
        else{std::cerr<<"Impossibile effettuare l'operazione";}
    }
}

///////////////////////////////////////////////////////////////////////////

//INFERMIERE:
double Infermiere::pagaPerOraInf=20.0;


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
Infermiere::Infermiere(u_int id, string n, string c, const Data & d, const gender & g, const Turno& t, bool r):Dipendente(id,n,c,d,g,t),responsabile(r) {}
Infermiere *Infermiere::clone() const{ return new Infermiere(*this);}

double Infermiere::stipendio() const{ return pagaPerOraInf*numGiorniLavoro()*8;}
bool Infermiere::isResponsabile() const{ return responsabile;}
void Infermiere::cambiaResponsabile(bool x){responsabile=x;}

// Costruttore di Copia di Infermiere
Infermiere::Infermiere(const Infermiere& i):Dipendente(i), responsabile(i.responsabile){}

Infermiere &Infermiere::operator=(const Infermiere& i){
    if(&i!=this){
        this->Dipendente::operator=(i);
        responsabile=i.responsabile;
    }
    return *this;
}


//////////////////////////////////////////////////////////////////////////

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
Paziente::Paziente(u_int id, string n, string c, Medico* m, const Data & dn, const gender & g, const Data & ir, const Data & fr, bool dec): Persona(id,n,c,dn,g),inizioRicovero(ir),fineRicovero(fr), deceduto(dec){
    medicoAssegnato=m;
    m->pazienti.push_back(this);
}
Paziente::Paziente(const Paziente &p):Persona(p), inizioRicovero(p.inizioRicovero), fineRicovero(p.fineRicovero), deceduto(p.deceduto), medicoAssegnato(p.medicoAssegnato){}
Paziente &Paziente::operator=(const Paziente& p){
    if(&p!=this){
        this->Persona::operator=(p);
        inizioRicovero=p.inizioRicovero;
        fineRicovero=p.fineRicovero;
        deceduto=p.deceduto;
        medicoAssegnato->aggiungiPaziente(this);
    }
    return *this;
}


Paziente *Paziente::clone() const{ return new Paziente(*this);}

Paziente::~Paziente(){}


Data Paziente::getInizioRic()const{ return inizioRicovero;}
Data Paziente::getFineRic() const {return fineRicovero;}
bool Paziente::isDeceduto() const {return deceduto;}
Medico* Paziente::getMedicoAssegnato() const {return medicoAssegnato;}

void Paziente::modFineRicovero(const Data &d){ fineRicovero=d;}
void Paziente::modDeceduto(bool x){if(x!=deceduto)deceduto=x;}


//////////////////////////////////////////////////////////////////////////////////////////////////

//OPERAZIONE:
Operazione::Operazione(const Data& d, Medico* m, Infermiere* i):dataOp(d), medOp(m), infOp(i){}

//metodi get
Data Operazione::getDataOp() const{ return dataOp;}
Medico* Operazione::getMedOp() const { return medOp;}
Infermiere* Operazione::getInfOp() const {return infOp; }

//modifica campi
void Operazione::modDataOp(const Data& d){dataOp=d;}
void Operazione::modMedOp(Medico* m){medOp=m;}
void Operazione::modInfOp(Infermiere* i){infOp=i;}

bool Operazione::operator==(const Operazione &o) const{ return dataOp==o.dataOp && medOp==o.medOp && infOp==o.infOp;}

Operazione::Operazione(const Operazione& o){
    dataOp=o.dataOp;
    medOp=o.medOp;
    infOp=o.infOp;
}
Operazione& Operazione::operator=(const Operazione& o){
    if(this!=&o){
        dataOp=o.dataOp;
        medOp=o.medOp;
        infOp=o.infOp;
    }
    return *this;
}

////////////////////////////////////////////////////////////////

//PAZIENTE CHIRURGICO:


/* Costruttore di PazienteChir
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
PazienteChir::PazienteChir(unsigned short id, string name, string sur, Medico* med, const Data& dOp, Medico* mOp, Infermiere* iOp, Persona* par, const Data& nasc, const gender& g, const Data& iRic, const Data& fRic, bool dec, bool succ):Paziente(id, name, sur, med, nasc, g, iRic, fRic, dec), Operazione(dOp,mOp,iOp), conSuccesso(succ), parente(*par){}

//metodi get
bool PazienteChir::getConSuccesso() const { return conSuccesso;}
Persona& PazienteChir::getParente() const { return parente;}

PazienteChir *PazienteChir::clone() const{ return new PazienteChir(*this);}

//metodi modifica
void PazienteChir::modConSuccesso(bool x){ conSuccesso=x;}
void PazienteChir::modParente(const Persona& p){ parente=p;}

PazienteChir::PazienteChir(const PazienteChir& o):Paziente(o),Operazione(o),conSuccesso(o.conSuccesso), parente(o.parente){}
PazienteChir& PazienteChir::operator=(const PazienteChir& o){
    if(&o!=this){
        this->Paziente::operator=(o);
        this->Operazione::operator=(o);
        conSuccesso=o.conSuccesso;
        parente.Persona::operator=(o.parente);
    }
    return *this;
}

std::istream &operator>>(std::istream & is,gender & g){
    int x;
    is>>x;
    if(x==0){g=maschio;}
    if(x==1){g=femmina;}
    if(x==2){g=altro;}
    return is;
}
