#ifndef RESPONSABILE_H
#define RESPONSABILE_H
#include <string>
#include "persona.h"
using std::string;

class Responsabile: public Persona{
private:

    virtual string getTag() const;
public:
    Responsabile(string, string, string = "", string ="", const Data& = Data(), const gender& = gender::altro, const QueueTurni& = QueueTurni());

    //permessi
    virtual bool isResponsabile() const;
    virtual bool canAddTurni() const;
    virtual bool canEditTurni() const;
    virtual Responsabile* clone() const;

    //import export
    //export ereditato da Persona
    static Persona* importXml(QXmlStreamReader&);
};

#endif // RESPONSABILE_H
