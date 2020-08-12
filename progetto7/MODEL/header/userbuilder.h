#ifndef USERBUILDER_H
#define USERBUILDER_H
#include "../../MODEL/header/persona.h"
#include "../../MODEL/header/turno.h"
#include <string>
#include <QString>
#include <QXmlStreamReader>

#include "../../MODEL/header/medico.h"
#include "../../MODEL/header/infermiere.h"
#include "../../MODEL/header/responsabile.h"

#include "../../MODEL/header/turno_intero.h"
#include "../../MODEL/header/turno_libero.h"
#include "../../MODEL/header/turno_parziale.h"
#include "../../MODEL/header/turno_straordinario.h"



class UserBuilder{
public:
    static Persona* build(const QString&);
    static Turno* buildT(const QString&, Turno *prec);
    static Persona* buildWithXmlTag(const std::string&, QXmlStreamReader&);
    virtual ~UserBuilder() = 0;
};

#endif // USERBUILDER_H
