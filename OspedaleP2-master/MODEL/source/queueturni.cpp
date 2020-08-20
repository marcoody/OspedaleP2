#include "../header/queueturni.h"

QString QueueTurni::startTag = "TURNI";
QString QueueTurni::defaultFile = "turnidata.xml";

QString QueueTurni::getStartTagXml() const{ return startTag; }
QString QueueTurni::getDefaultFile() const {return defaultFile; }


bool QueueTurni::importXml(QXmlStreamReader& in){
    clear();
    bool ok = false;
        while(in.readNextStartElement()) {
            if(in.name() == getStartTagXml()){
                while(in.readNextStartElement())
                {
                    //legge il nome della classe
                    string classname = (in.name().toString()).toStdString();

                    //poco estendibile
                    Turno* t = 0;
                    try
                    {
                        if (classname == "LIBERO"){ t = Turno_libero::importXml(in); }
                        else if (classname == "INTERO") { t = Turno_intero::importXml(in); }
                        else if (classname == "PARZIALE") { t = Turno_parziale::importXml(in); }
                        else if (classname == "STRAORDINARIO") { t = Turno_straordinario::importXml(in); }
                        else {t = nullptr;}

                        if(t)
                        {
                            push_back(t->clone());
                            delete t;
                            ok = true;
                        }
                        //porta il puntatore all'elemento successivo
                        in.skipCurrentElement();
                    }
                    catch(errore_tag e)
                    {
                        //salta al prossimo elemento
                        while (!in.isEndElement() || in.name() != QString::fromStdString(classname))
                            in.readNext();
                    }
               }
            }
        }
        return ok;
}




double QueueTurni::stipendioTurni() const {
    double stipendio = 0;
    for(auto it=begin(); it!=end(); ++it ){
        stipendio += (*it)->paga();
    }
    return stipendio;
}

