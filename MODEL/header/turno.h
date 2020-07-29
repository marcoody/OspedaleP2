#ifndef TURNO_H
#define TURNO_H
#include "data.h"
#include "colore.h"
#include <string>
#include <QXmlStreamWriter>
#include "metodifreq.h"

using std::string;

class Turno{
private:
    Data dataTurno;
    u_int nOre;

public:
    Turno(Data& , u_int);

    //metodi get
    Data getDataTurno() const;
    u_int getNOre() const;

    //metodi set
    void setDataTurno(Data&);
    void setNOre(u_int);

    //metodi export
    void exportXml(QXmlStreamWriter&) const;
    virtual void exportXmlData(QXmlStreamWriter&) const;

    //metodi import
    static void importXmlData(QXmlStreamReader&, Data&, u_int&);

    //metodi virtuali
    virtual Turno* clone() const = 0;
    virtual ~Turno() {};
    virtual double paga() const = 0;
    virtual string infoTurno() const;
    virtual const Colore getColor() const = 0;
    virtual string getTag() const;


};

#endif // TURNO_H
