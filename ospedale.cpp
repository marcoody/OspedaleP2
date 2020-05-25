#include "ospedale.h"

Ospedale::Ospedale(vector<Dipendente *> d, vector<Paziente *> p): pazientiOsp(p), dipendentiOsp(d){} //QUI FUNZIONA LA COSTR DI COPIA????

Ospedale::Ospedale(const Ospedale & o){
    for(vector<Dipendente*>::const_iterator i= o.dipendentiOsp.begin(); i!=o.dipendentiOsp.end(); ++i){
        Dipendente* tmp=*i;
        dipendentiOsp.push_back(tmp);
    }
    for(vector<Paziente*>::const_iterator i= o.pazientiOsp.begin(); i!=o.pazientiOsp.end(); ++i){
        Paziente* tmp=*i;
        pazientiOsp.push_back(tmp);
    }
}

Ospedale &Ospedale::operator=(const Ospedale & o){
    if(&o!=this){
        for(vector<Dipendente*>::const_iterator i= o.dipendentiOsp.begin(); i!=o.dipendentiOsp.end(); ++i){
            Dipendente* tmp=*i;
            dipendentiOsp.push_back(tmp);
        }
        for(vector<Paziente*>::const_iterator i= o.pazientiOsp.begin(); i!=o.pazientiOsp.end(); ++i){
            Paziente* tmp=*i;
            pazientiOsp.push_back(tmp);
        }

    }
    return *this;
}

Ospedale::~Ospedale(){
    pazientiOsp.clear();
    dipendentiOsp.clear();

}

//metodi get

vector<Paziente*>& Ospedale::getPazientiOsp(){return pazientiOsp;}
vector<Dipendente*>& Ospedale::getDipendentiOsp(){return dipendentiOsp;}


//altri metodi

u_int Ospedale::numPazienti() const{
    u_int tot=0;
    for(vector<Paziente*>::const_iterator i=pazientiOsp.begin(); i!=pazientiOsp.end(); ++i){++tot;}
    return tot;
}
u_int Ospedale::numDipendenti() const{
    u_int tot=0;
    for(vector<Dipendente*>::const_iterator i=dipendentiOsp.begin(); i!=dipendentiOsp.end(); ++i){++tot;}
    return tot;
}

u_int Ospedale::numOperazioniGiorno(const data & d) const{
    u_int tot=0;
    for(vector<Paziente*>::const_iterator it=pazientiOsp.begin(); it!=pazientiOsp.end(); ++it){
        PazienteChir* tmp= dynamic_cast<PazienteChir*>(*it);
        if(tmp && tmp->getDataOp()==d ){++tot;}
    }
    return tot;
}

u_int Ospedale::numPazientiChirurgici() const{
    u_int tot=0;
    for(vector<Paziente*>::const_iterator i=pazientiOsp.begin(); i!=pazientiOsp.end(); ++i){
        if(dynamic_cast<PazienteChir*>(*i)){++tot;}
    }
    return tot;
}

u_int Ospedale::numOperazioniSuccesso() const{
    u_int tot=0;
    for(vector<Paziente*>::const_iterator it=pazientiOsp.begin(); it!=pazientiOsp.end(); ++it){
        PazienteChir* tmp= dynamic_cast<PazienteChir*>(*it);
        if(tmp && tmp->getConSuccesso()==1 ){++tot;}
    }
    return tot;
}

vector<Paziente*>::iterator Ospedale::cercaPazienteOsp(const Paziente& p){
    for(vector<Paziente*>::iterator i=pazientiOsp.begin(); i!=pazientiOsp.end(); ++i){
        Paziente& tmp=**i;
        if(tmp==p){return i;}
    }
    return pazientiOsp.end(); //QUI CI VA UNA SIGNAL
}

vector<Dipendente*>::iterator Ospedale::cercaDipendenteOsp(const Dipendente& d){
    for(vector<Dipendente*>::iterator i=dipendentiOsp.begin(); i!=dipendentiOsp.end(); ++i){
        Dipendente& tmp=**i;
        if(tmp==d){return i;}
    }
    return dipendentiOsp.end(); //QUI CI VA UNA SIGNAL
}


void Ospedale::addPazienteOsp(const Paziente& p){
    vector<Paziente*>::iterator i=cercaPazienteOsp(p);
    if(i==pazientiOsp.end()){pazientiOsp.push_back(&(const_cast<Paziente&>(p)));}
}
void Ospedale::delPazienteOsp(const Paziente& p){
    vector<Paziente*>::iterator i=cercaPazienteOsp(p);
    if(i!=pazientiOsp.end()) {pazientiOsp.erase(i);}
}
void Ospedale::addDipendenteOsp(const Dipendente& d){
    vector<Dipendente*>::iterator i=cercaDipendenteOsp(d);
    if(i==dipendentiOsp.end()){dipendentiOsp.push_back(&(const_cast<Dipendente&>(d)));}
}
void Ospedale::delDipendenteOsp(const Dipendente& d){
    vector<Dipendente*>::iterator i=cercaDipendenteOsp(d);
    if(i!=dipendentiOsp.end()) {dipendentiOsp.erase(i);}
}


void Ospedale::rimuoviDeceduti(){
    for(vector<Paziente*>::iterator it=pazientiOsp.begin(); it!=pazientiOsp.end(); ++it){
        Paziente* tmp=*it;
        if(tmp->isDeceduto()){ pazientiOsp.erase(it); --it;}
    }
}

void Ospedale::rimuoviDimessiData(const data& d){
    for(vector<Paziente*>::iterator i=pazientiOsp.begin(); i!=pazientiOsp.end(); ++i){
        if((*i)->getFineRic()==d){pazientiOsp.erase(i); --i;}
    }
}
vector<Paziente*>& Ospedale::pazientiDimessiData(const data& d){
    vector<Paziente*> ris;
    for(vector<Paziente*>::iterator i=pazientiOsp.begin(); i!=pazientiOsp.end(); ++i){
        if((*i)->getFineRic()==d){ris.push_back(*i);}
    }
    return ris;
}

vector<Paziente *> &Ospedale::pazientiRicoveratiData(const data & d){
    vector<Paziente*> ris;
    for(vector<Paziente*>::iterator i=pazientiOsp.begin(); i!=pazientiOsp.end(); ++i){
        if((*i)->getInizioRic()==d){ris.push_back(*i);}
    }
    return ris;
}

vector<Medico *>& Ospedale::mediciInTurno(const data & d){
    vector<Medico*> ris;
    for(vector<Dipendente*>::iterator i=dipendentiOsp.begin(); i!=dipendentiOsp.end(); ++i){
        Medico* tmp= dynamic_cast<Medico*>(*i);
        if(tmp&& tmp->inTurno(d.giornoSettimana())){ris.push_back(tmp);}
    }
    return ris;
}

vector<Infermiere *> &Ospedale::infermieriInTurno(const data &d){
    vector<Infermiere*> ris;
    for(vector<Dipendente*>::iterator i=dipendentiOsp.begin(); i!=dipendentiOsp.end(); ++i){
        Infermiere* tmp= dynamic_cast<Infermiere*>(*i);
        if(tmp&& tmp->inTurno(d.giornoSettimana())){ris.push_back(tmp);}
    }
    return ris;
}

vector<Paziente *> &Ospedale::pazientiAssegnatiA(Medico * m){
    vector<Paziente*> ris;
    for(vector<Paziente*>::iterator i=pazientiOsp.begin(); i!=pazientiOsp.end(); ++i){
        if((*i)->getMedicoAssegnato()== m){ris.push_back(*i);}
    }
    return ris;
}

vector<PazienteChir *>& Ospedale::pazientiOperatiDa(Medico *m){
    vector<PazienteChir*> ris;
    for(vector<Paziente*>::iterator i=pazientiOsp.begin(); i!=pazientiOsp.end(); ++i){
        PazienteChir* tmp= dynamic_cast<PazienteChir*>(*i);
        if(tmp && tmp->getMedOp()==m){ris.push_back(tmp);}
    }
    return ris;
}


double Ospedale::totaleStipendi() const{
    double tot=0;
    for(vector<Dipendente*>::const_iterator it=dipendentiOsp.begin(); it!=dipendentiOsp.end(); ++it){
        tot+=(*it)->stipendio();
    }
    return tot;
}
