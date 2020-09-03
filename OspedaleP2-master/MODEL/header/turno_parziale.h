#ifndef TURNO_PARZIALE_H
#define TURNO_PARZIALE_H
#include "turno_regolare.h"
#include <string>
using std::string;

class Turno_parziale: public Turno_regolare{
private:
    double paga_parziale;
    static const int r = 255, g = 102, b = 0;

public:
    Turno_parziale(giorni, QTime=QTime(0,0), QTime=QTime(0,0),  string = "", double= 14.0);

    //metodi get
    double getPagaParziale() const;

    //metodi set
    void setPagaParziale(double);

    //metodi export
    virtual void exportXmlData(QXmlStreamWriter&) const;

    //metodi import
    static void importXmlData(QXmlStreamReader&, double&);
    static Turno* importXml(QXmlStreamReader&);

    //metodi virtual
    virtual Turno* clone() const;
    virtual double paga() const;
    virtual string infoTurno() const;
    virtual const Colore getColor() const;
    virtual string getTag() const;
};
