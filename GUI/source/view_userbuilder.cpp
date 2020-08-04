#include "../../GUI/header/view_userbuilder.h"

view_persona* view_UserBuilder::build(QueuePersone& lista, Persona* p){

    if(dynamic_cast<Medico*>(p))
        return new view_medico(lista,p);
    if(dynamic_cast<Infermiere*>(p))
        return new view_infermiere(lista, p);
    if(dynamic_cast<Responsabile*>(p))
        return new view_responsabile(lista, p);

    return nullptr;
}

view_UserBuilder:: ~view_UserBuilder() {}

