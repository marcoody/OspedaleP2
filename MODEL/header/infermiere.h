#ifndef INFERMIERE_H
#define INFERMIERE_H
#include <string>
#include "persona.h"
#include "queueturni.h"
using std::string;

class Infermiere: public Persona{
private:
    QueueTurni turni;

public:
    Infermiere(string, string, string = "", string ="", const Data& = Data(), const gender& = gender::altro, const QueueTurni& = QueueTurni());

    //metodi get
    QueueTurni getTurni() const;

    //metodi set
    void setTurni(giorni, Turno*);
    //permessi
    virtual bool isResponsabile() const;
    virtual bool canAddTurni() const;
    virtual bool canEditTurni() const;

    //virtual
    virtual Infermiere* clone() const;
    virtual string getTag() const;
    virtual double stipendio() const;
    //infoPersona ereditato da Persona

    virtual void exportXml(QXmlStreamWriter &) const;
    static void importXmlData(QXmlStreamReader&, QueueTurni&);
    static Persona* importXml(QXmlStreamReader&);
};


#endif // INFERMIERE_H
