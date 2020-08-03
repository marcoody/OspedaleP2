#ifndef MEDICO_H
#define MEDICO_H
#include <string>
#include <QXmlStreamWriter>
#include "persona.h"
using std::string;

class Medico: public Persona{
private:
    string reparto;
    bool chirurgo;

    virtual string getTag() const;
public:
    Medico(string, string, string = "", string ="", const Data& = Data(), const gender& = gender::altro, string rep = "", bool chir = false, const  QueueTurni& = QueueTurni());

    //get
    string getReparto() const;
    bool isChirurgo() const;

    //set
    void setReparto(string&);
    void setChirurgo(bool);

    //permessi
    virtual bool isResponsabile() const;
    virtual bool canAddTurni() const;
    virtual bool canEditTurni() const;
    //virtual
    virtual Medico* clone() const;

    //Import export
    virtual void exportXml(QXmlStreamWriter&) const;
    static void importXmlData(QXmlStreamReader&, string&, bool&, QueueTurni&);
    static Persona* importXml(QXmlStreamReader&);
};

#endif // MEDICO_H
