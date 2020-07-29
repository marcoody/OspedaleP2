#ifndef QUEUETURNI_H
#define QUEUETURNI_H
#include "turno.h"
#include "turno_regolare.h"
#include "turno_intero.h"
#include "turno_parziale.h"
#include "turno_libero.h"
#include "turno_straordinario.h"
#include "queue.h"


class QueueTurni: public Queue<Turno*>{
private:
    static QString startTag;
    static QString defaultFile;
    QString getStartTagXml() const;
    QString getDefaultFile() const;
public:
    QueueTurni(): Queue(){};


    bool importXml(QXmlStreamReader&);
    double stipendioTurni() const;

};

#endif // QUEUETURNI_H
