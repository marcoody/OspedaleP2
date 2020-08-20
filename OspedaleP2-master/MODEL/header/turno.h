#ifndef TURNO_H
#define TURNO_H
#include "data.h"
#include "colore.h"
#include <string>
#include <QXmlStreamWriter>
#include "metodifreq.h"
#include <QTime>


using std::string;

class Turno{
private:
    giorni giornoTurno;
    QTime inizio;
    QTime fine;

public:
    Turno(giorni, QTime=QTime(0,0), QTime=QTime(0,0));

    //metodi get
    giorni getGiornoTurno() const;
    QTime getInizio() const;
    QTime getFine() const;

    string inizioStringa() const;
    string fineStringa() const;

    //metodi set
    void setGiornoTurno(giorni&);
    void setInizio(QTime);
    void setFine(QTime);



    //metodi export
    void exportXml(QXmlStreamWriter&) const;
    virtual void exportXmlData(QXmlStreamWriter&) const;

    //metodi import
    static void importXmlData(QXmlStreamReader&, giorni&, QTime&, QTime&);

    //metodi virtuali
    virtual double TotOre() const;
    virtual Turno* clone() const = 0;
    virtual ~Turno() {};
    virtual double paga() const = 0;
    virtual string infoTurno() const;
    virtual const Colore getColor() const = 0;
    virtual string getTag() const;


};

#endif // TURNO_H
