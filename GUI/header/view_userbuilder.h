#ifndef VIEW_USERBUILDER_H
#define VIEW_USERBUILDER_H
#include <string>
#include <QString>
#include <iostream>
#include "../../MODEL/header/persona.h"
#include "../../MODEL/header/medico.h"
#include "../../MODEL/header/infermiere.h"
#include "../../MODEL/header/responsabile.h"
#include "../../MODEL/header/queuepersone.h"
#include "../../MODEL/header/turno.h"
#include "../../MODEL/header/turno_intero.h"
#include "../../MODEL/header/turno_libero.h"
#include "../../MODEL/header/turno_parziale.h"
#include "../../MODEL/header/turno_straordinario.h"
#include "view_persona.h"
#include "view_medico.h"
#include "view_infermiere.h"
#include "view_responsabile.h"
#include "view_turno.h"
#include "view_turno_intero.h"
#include "view_turno_parziale.h"
#include "view_turno_libero.h"
#include "view_turno_straordinario.h"

class view_UserBuilder{
public:
    static view_persona* build(QueuePersone&, Persona*);
    static view_turno* buildT(Turno*);
    virtual ~view_UserBuilder() = 0;
};

#endif // VIEW_USERBUILDER_H
