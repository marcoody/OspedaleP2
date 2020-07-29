#ifndef TURNO_PARZIALE_H
#define TURNO_PARZIALE_H
#include "turno_regolare.h"
#include <string>
using std::string;

class Turno_parziale: public Turno_regolare{
private:
    bool daContratto;
    double paga_parziale;
    static const int r = 255, g = 102, b = 0;

public:
    Turno_parziale(Data&, u_int, string, bool=true, double= 14.0);

    //metodi get
    bool getDaContratto() const;
    double getPagaParziale() const;

    //metodi set
    void setDaContratto(bool);
    void setPagaParziale(double);

    //metodi export
    virtual void exportXmlData(QXmlStreamWriter&) const;

    //metodi import
    static void importXmlData(QXmlStreamReader&, bool&, double&);
    static Turno* importXml(QXmlStreamReader&);

    //metodi virtual
    virtual Turno* clone() const;
    virtual double paga() const;
    virtual string infoTurno() const;
    virtual const Colore getColor() const;
    virtual string getTag() const;
};

#endif // TURNO_PARZIALE_H
