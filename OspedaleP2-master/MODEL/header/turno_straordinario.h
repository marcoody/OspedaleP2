#ifndef TURNO_STRAORDINARIO_H
#define TURNO_STRAORDINARIO_H
#include "turno_regolare.h"
#include "turno_libero.h"
#include <QTime>


class Turno_straordinario : public Turno_regolare, public Turno_libero{
private:
    bool volontariato;
    double paga_straordinario;
    static const int r = 204, g = 51, b = 255;
public:
    Turno_straordinario(giorni, QTime=QTime(0,0), QTime=QTime(0,0),  string = "", bool = false , bool =  false , double=16.0 );

    //metodi get
    bool getVolontariato() const;
    double getPagaStraordinario() const;

    //metodi set
    void setVolontariato(bool);
    void setPagaStraordinario(double);

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

#endif // TURNO_STRAORDINARIO_H
