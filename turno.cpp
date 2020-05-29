#include "turno.h"

Turno::Turno(){for(u_int i=0; i<7; ++i){turni[i]=0;}}
Turno::Turno(bool* b){ for(u_int i=0; i<7; ++i){turni[i]=b[i];} }
Turno::Turno(const Turno& t){ for(u_int i=0; i<7; ++i){turni[i]=t.turni[i];}}
Turno& Turno::operator=(const Turno& t){
    if(&t!=this){
       for(u_int i=0; i<7; ++i){turni[i]=t.turni[i];}
    }
    return *this;
}
Turno::~Turno(){}

bool Turno::inturno(const giorni &g) const { return turni[g];}

unsigned short Turno::giornilavoro() const{
    u_int tot=0;
    for(u_int i=0; i<7; ++i){tot+=turni[i];}
    return tot;
}

void Turno::switchturno(const giorni &g1, const giorni &g2){
    if(inturno(g1) && !inturno(g2) && g1!=g2){ turni[g1]=0; turni[2]=1;}
    else{ throw std::runtime_error("Operazione non valida");}
}

void Turno::addTurno(const giorni& g){
    if(turni[g]==0){turni[g]=1; return;}
    else{ throw Err_turno;}
}
void Turno::delTurno(const giorni& g){
    if(turni[g]==1){turni[g]=0; return;}
    else{ throw Err_turno; }
}

bool Turno::operator==(const Turno& t){
    for(u_int i=0; i<7; ++i){
        if (turni[i]!=t.turni[i]){return false;}
    }
    return true;
}
bool Turno::operator!=(const Turno& t){
    for(u_int i=0; i<7; ++i){
        if (turni[i]==t.turni[i]){return false;}
    }
    return true;
}
