#include "../header/userbuilder.h"

Persona* UserBuilder::build(const QString& impiego){

    if(impiego == "Medico")
        return new Medico("", "");
    if(impiego == "Infermiere")
        return new Infermiere("","");
    if(impiego == "Responsabile")
        return new Responsabile("","");
    return nullptr;
}

Persona* UserBuilder::buildWithXmlTag(const std::string& classname, QXmlStreamReader& xmlInput)
{
    if (classname == "MEDICO")
        return Medico::importXml(xmlInput);
    if (classname == "INFERMIERE")
        return Infermiere::importXml(xmlInput);
    if (classname == "RESPONSABILE")
        return Responsabile::importXml(xmlInput);
    return nullptr;
}

UserBuilder::~UserBuilder() {}
