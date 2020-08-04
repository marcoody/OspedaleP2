#ifndef TURNO_REGOLARE_H
#define TURNO_REGOLARE_H
#include "turno.h"
#include "data.h"
#include <string>
using std::string;

class Turno_regolare: public virtual Turno {
private:
    string reparto;

public:
    Turno_regolare(giorni, u_int, string);

    //metodi get
    string getReparto() const;

    //metodi set
    void setReparto(string&);

    //metodi export
    virtual void exportXmlData(QXmlStreamWriter&) const;

    //metodi import
    static void importXmlData(QXmlStreamReader&, string&);

    //metodi virtual

    //clone ereditato
    //paga ereditato
    //getColor ereditato
    virtual string infoTurno() const;
    virtual string getTag() const;

};

#endif // TURNO_REGOLARE_H
