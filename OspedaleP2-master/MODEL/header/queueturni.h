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
    QueueTurni(): Queue(){
        giorni g = giorni::lunedi;
        for(int i=0; i<6; ++i){
            Turno_intero* tmp = new Turno_intero(g);
            push_back(tmp->clone());
            delete tmp;
            avanzaGiorni(g);
        }
        Turno_libero* tmp = new Turno_libero(giorni::domenica);
        push_back(tmp->clone());
        delete tmp;
    };


    bool importXml(QXmlStreamReader&);
    double stipendioTurni() const;

};

#endif // QUEUETURNI_H
