#ifndef INFERMIERE_H
#define INFERMIERE_H
#include <string>
#include "persona.h"
#include "queueturni.h"
using std::string;

class Infermiere: public Persona{
private:
    QueueTurni turni;
    virtual string getTag() const;
public:
    Infermiere(string, string, string = "", string ="", const Data& = Data(), const gender& = gender::altro, const QueueTurni& = QueueTurni());

    //metodi get
    QueueTurni getTurni() const;
    //permessi
    virtual bool isResponsabile() const;
    virtual bool canAddTurni() const;
    virtual bool canEditTurni() const;
    virtual Infermiere* clone() const;

    virtual void exportXml(QXmlStreamWriter &) const;
    static void importXmlData(QXmlStreamReader&, QueueTurni&);
    static Persona* importXml(QXmlStreamReader&);
};


#endif // INFERMIERE_H
