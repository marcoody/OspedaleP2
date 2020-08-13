#ifndef TURNO_LIBERO_H
#define TURNO_LIBERO_H
#include "data.h"
#include "colore.h"
#include "turno.h"
#include <string>
using std::string;

class Turno_libero :public virtual Turno{
private:
    bool permesso;
    static const int r = 0, g = 153, b = 0;
public:
    Turno_libero(giorni , bool = true);

    //metodi get
    bool getPermesso() const;

    //metodi set
    void setPermesso(bool);

    //metodi export
    virtual void exportXmlData(QXmlStreamWriter&) const;

    //metodi import
    static void importXmlData(QXmlStreamReader&, bool&);
    static Turno* importXml(QXmlStreamReader&);

    //metodi virtual
    virtual Turno* clone() const;
    virtual double paga() const;
    virtual string infoTurno() const;
    virtual const Colore getColor() const;
    virtual string getTag() const;
};

#endif // TURNO_LIBERO_H
