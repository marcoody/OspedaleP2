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

Turno *UserBuilder::buildT(const QString & tipoTurno, Turno *prec){
    Turno_intero* ti= dynamic_cast<Turno_intero*>(prec);
    Turno_parziale* tp = dynamic_cast<Turno_parziale*>(prec);
    Turno_libero* tl = dynamic_cast<Turno_libero*>(prec);
    Turno_straordinario* ts = dynamic_cast<Turno_straordinario*>(prec);


    if(ts && tipoTurno == "Straordinario")
        return new Turno_straordinario(ts->getGiornoTurno(), ts->getInizio(), ts->getFine(), ts->getReparto(), ts->getPermesso(), ts->getVolontariato(), ts->getPagaStraordinario());

    if(tl && (tipoTurno=="Straordinario"))
        return new Turno_straordinario(prec->getGiornoTurno());



    if(tl && tipoTurno == "Libero")
       return new Turno_libero(tl->getGiornoTurno(), tl->getInizio(), tl->getFine(), tl->getPermesso());


    if(ti && tipoTurno =="Intero")
        return new Turno_intero(ti->getGiornoTurno(), ti->getInizio(), ti->getFine(), ti->getReparto(), ti->getPagaIntero());

    if(tp && tipoTurno == "Parziale")
        return new Turno_parziale(tp->getGiornoTurno(), tp->getInizio(), tp->getFine(), tp->getReparto(), tp->getPagaParziale());

    if(tipoTurno == "Intero")
        return new Turno_intero(prec->getGiornoTurno());

    if(tipoTurno == "Parziale")
        return new Turno_parziale(prec->getGiornoTurno());

    if(tipoTurno == "Libero"){
        return new Turno_libero(prec->getGiornoTurno());
    }

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
