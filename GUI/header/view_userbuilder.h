#ifndef VIEW_USERBUILDER_H
#define VIEW_USERBUILDER_H
#include <string>
#include <QString>
#include "../../MODEL/header/persona.h"
#include "../../MODEL/header/medico.h"
#include "../../MODEL/header/infermiere.h"
#include "../../MODEL/header/responsabile.h"
#include "../../MODEL/header/queuepersone.h"
#include "view_persona.h"
#include "view_medico.h"
#include "view_infermiere.h"
#include "view_responsabile.h"

class view_UserBuilder{
public:
    static view_persona* build(QueuePersone&, Persona*);
    virtual ~view_UserBuilder() = 0;
};

#endif // VIEW_USERBUILDER_H
