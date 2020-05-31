#include "model.h"

void Model::popolaDipendenti(){
    std::ifstream file(":/dipendentiOs.txt");
    string s;
    u_int id; string n,c,t; Data dn; gender g; bool resp;
    while(getline(file,s)){
         std::stringstream ss(s);
         if(ss>>id>>n>>c>>dn>>g>>t){
             bool tmp[7];
             for(u_int i=0; i<7; ++i){tmp[i]=t[i];}
             Medico* m= new Medico(id,n,c,dn,g,tmp);
             dipendentiOs.push_back(m->clone());
         }
         else if(ss>>id>>n>>c>>dn>>g>>t>>resp){
             bool tmp[7];
             for(u_int i=0; i<7; ++i){tmp[i]=t[i];}
             Infermiere* i= new Infermiere(id,n,c,dn,g,tmp);
             dipendentiOs.push_back(i->clone());
         }
         else{ throw Err_file_input();}
    }
}

void Model::popolaPazienti(){
    std::ifstream file(":/pazientiOs.txt");
    string s;
    u_int id, med;
    string n,c;
    Data dn,ir,fr, dOp;
    gender g;
    bool dec;
    while(getline(file,s)){
        std::stringstream ss(s);
        if(ss>>id>>n>>c>>dn>>g>>ir>>fr>>dec>> med){
            Medico* m=idToMedico(med);
            if(m!=nullptr){
                Paziente* paz= new Paziente(id,n,c,m,dn,g,ir,fr,dec);
                pazientiOs.push_back(paz);
            }
        }
        else{throw Err_file_input();}
    }

}

Model::Model(){
    popolaDipendenti();
    popolaPazienti();
}
//////////////////////////////////////////////////////////////////

//METODI PAZIENTI:
void Model::nuovoPaziente(Paziente *p){
    if(pazientePresente(p)==pazientiOs.end()){
        pazientiOs.push_back(p);
    }
    else {throw Err_paziente_presente();}
}

void Model::resetTutto(){
    dipendentiOs.clear();
    pazientiOs.clear();
}

void Model::dimettiPaziente(Paziente *p){
    Queue<Paziente*>::iterator it=pazientePresente(p);
    if(it!=pazientiOs.end()){
        Paziente* p=*it;
        pazientiOs.erase(it);
        (p->getMedicoAssegnato())->eliminaPaziente(p);
        delete p;
    }
}

u_int Model::numPazientiOs() const{
    u_int tot=0;
    for(auto it=pazientiOs.begin(); it!=pazientiOs.end(); ++it){++tot;}
    return tot;
}
////////////////////////////////////////////////////////////////////

//METODI DI RICERCA
Queue<Paziente*>::iterator Model::pazientePresente(Paziente *p) const{
    for(auto it=pazientiOs.begin(); it!=pazientiOs.end(); ++it){
        if(p->getIdPersona()==(*it)->getIdPersona()){return it;}
    }
    return pazientiOs.end();
}

Queue<Dipendente*>::iterator Model::dipendentePresente(Dipendente *d) const{
    for(auto it=dipendentiOs.begin(); it!=dipendentiOs.end(); ++it){
        if(d->getIdPersona()==(*it)->getIdPersona()){return it;}
    }
    return dipendentiOs.end();
}

Medico* Model::idToMedico(u_int id) const{
    for(auto it=dipendentiOs.begin(); it!=dipendentiOs.end(); ++it){
        if ((*it)->getIdPersona()==id){return static_cast<Medico*>(*it);}
    }
    return nullptr;
}

Infermiere* Model::idToInfermiere(u_int id) const{
    for(auto it=dipendentiOs.begin(); it!=dipendentiOs.end(); ++it){
        if ((*it)->getIdPersona()==id){return static_cast<Infermiere*>(*it);}
    }
    return nullptr;
}

u_int Model::numDipendentiOs() const{
    u_int tot=0;
    for(auto it=dipendentiOs.begin(); it!=dipendentiOs.end(); ++it){++tot;}
    return tot;
}

//metodi di output
void Model::stampaDipendenti() const{
    for(auto it=dipendentiOs.begin(); it!=dipendentiOs.end(); ++it){
        std::cout<<(*it)->getIdPersona()<<" "<<(*it)->getNomePersona()<<" "<<(*it)->getCognPersona()<<" "<<(*it)->getDataNascita()<<std::endl;
    }
}
