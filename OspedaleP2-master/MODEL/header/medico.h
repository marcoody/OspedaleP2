#ifndef MEDICO_H
#define MEDICO_H
#include <string>
#include <QXmlStreamWriter>
#include "persona.h"
#include "queueturni.h"
using std::string;

class Medico: public Persona{
private:
    string specializzazione;
    bool chirurgo;


public:
    Medico(string, string, string = "", string ="", const Data& = Data(), const gender& = gender::altro, const QueueTurni& = QueueTurni(), string spec = "", bool chir = false);

    //get
    string getSpecializzazione() const;
    bool isChirurgo() const;

    //set
    void setSpecializzazione(string&);
    void setChirurgo(bool);

    //permessi
    virtual bool isResponsabile() const;
    virtual bool canAddTurni() const;
    virtual bool canEditTurni() const;

    //virtual
    virtual Medico* clone() const;
    virtual string infoPersona() const;
    virtual string getTag() const;
    //stipendio ereditata

    //Import export
    virtual void exportXml(QXmlStreamWriter&) const;
    static void importXmlData(QXmlStreamReader&, string&, bool&);
    static Persona* importXml(QXmlStreamReader&);
};

#endif // MEDICO_H
