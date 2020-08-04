#ifndef TURNO_INTERO_H
#define TURNO_INTERO_H
#include "turno_regolare.h"
#include <string>
using std::string;

class Turno_intero: public Turno_regolare {
private:
    double paga_intero;
    static const int r = 51, g = 153, b = 255;
public:
    Turno_intero(giorni, u_int , string, double = 15.0);

    //metodi get
    double getPagaIntero() const;

    //metodi set
    void setPagaIntero(double);

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

#endif // TURNO_INTERO_H
