#ifndef INFERMIERE_H
#define INFERMIERE_H
#include <string>
#include "persona.h"
#include "queueturni.h"
using std::string;

class Infermiere: public Persona{

public:
    Infermiere(string, string, string = "", string ="", const Data& = Data(), const gender& = gender::altro, const QueueTurni& = QueueTurni());


    //permessi
    virtual bool isResponsabile() const;
    virtual bool canAddTurni() const;
    virtual bool canEditTurni() const;

    //virtual
    virtual Infermiere* clone() const;
    virtual string getTag() const;
    //stpendio ereditata
    //infoPersona ereditato da Persona
    //impoertXmlData e exportXml ereditati da Persona

    static Persona* importXml(QXmlStreamReader&);
};


#endif // INFERMIERE_H
