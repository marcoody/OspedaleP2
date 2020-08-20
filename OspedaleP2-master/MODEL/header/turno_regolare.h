#ifndef TURNO_REGOLARE_H
#define TURNO_REGOLARE_H
#include "turno.h"
#include "data.h"
#include <string>
#include <QTime>
using std::string;

class Turno_regolare: public virtual Turno {
private:
    string reparto;

public:
    Turno_regolare(giorni, QTime=QTime(0,0), QTime=QTime(0,0), string = "");

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
