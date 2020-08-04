#ifndef MEDICO_H
#define MEDICO_H
#include <string>
#include <QXmlStreamWriter>
#include "persona.h"
#include "queueturni.h"
using std::string;

class Medico: public Persona{
private:
    string reparto;
    bool chirurgo;
    QueueTurni turni;


public:
    Medico(string, string, string = "", string ="", const Data& = Data(), const gender& = gender::altro, string rep = "", bool chir = false, const  QueueTurni& = QueueTurni());

    //get
    string getReparto() const;
    bool isChirurgo() const;
    QueueTurni getTurni() const;

    //set
    void setReparto(string&);
    void setChirurgo(bool);
    void setTurno(giorni, Turno*);

    //permessi
    virtual bool isResponsabile() const;
    virtual bool canAddTurni() const;
    virtual bool canEditTurni() const;

    //virtual
    virtual Medico* clone() const;
    virtual string infoPersona() const;
    virtual string getTag() const;
    virtual double stipendio() const;

    //Import export
    virtual void exportXml(QXmlStreamWriter&) const;
    static void importXmlData(QXmlStreamReader&, string&, bool&, QueueTurni&);
    static Persona* importXml(QXmlStreamReader&);
};

#endif // MEDICO_H
