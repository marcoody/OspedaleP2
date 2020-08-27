#include "../../GUI/header/view_userbuilder.h"

view_persona* view_UserBuilder::build(QueuePersone& lista, Persona* p, bool ed){

    if(dynamic_cast<Medico*>(p))
        return new view_medico(lista,p, ed);
    if(dynamic_cast<Infermiere*>(p))
        return new view_infermiere(lista, p, ed);
    if(dynamic_cast<Responsabile*>(p))
        return new view_responsabile(lista, p, ed);

    return nullptr;
}

view_turno* view_UserBuilder::buildT(Turno* t){


    if(dynamic_cast<Turno_parziale*>(t)){
        return new view_turno_parziale(t);
    }

    if(dynamic_cast<Turno_intero*>(t)){
        return new view_turno_intero(t);
    }

    if(dynamic_cast<Turno_straordinario*>(t)){
        return new view_turno_straordinario(t);
    }


    if(dynamic_cast<Turno_libero*>(t)){
        return new view_turno_libero(t);
    }

    return nullptr;
}

view_UserBuilder:: ~view_UserBuilder() {}

