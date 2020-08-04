#ifndef USERBUILDER_H
#define USERBUILDER_H
#include "../../MODEL/header/persona.h"
#include <string>
#include <QString>
#include <QXmlStreamReader>
#include "../../MODEL/header/medico.h"
#include "../../MODEL/header/infermiere.h"
#include "../../MODEL/header/responsabile.h"



class UserBuilder{
public:
    static Persona* build(const QString&);
    static Persona* buildWithXmlTag(const std::string&, QXmlStreamReader&);
    virtual ~UserBuilder() = 0;
};

#endif // USERBUILDER_H
