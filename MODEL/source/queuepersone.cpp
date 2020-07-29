#include "../header/queuepersone.h"

QString QueuePersone::startTag = "PERSONE";
QString QueuePersone::defaultFile = "personedata.xml";

QString QueuePersone::getStartTagXml() const { return startTag; }
QString QueuePersone::getDefaultFile() const { return defaultFile; }

Persona* QueuePersone::search(string username) const {
    for( auto it = begin(); it!=end(); ++it ){
        if(username == (*it)->getUsername()) { return *it; }
    }
    return 0;
}

bool QueuePersone::search(const Persona* p) const {
    if(p){
        for(auto it = begin(); it!= end(); ++it){
            if(*p == **it ){ return true; }
        }
    }
    return false;
}

bool QueuePersone::checkPassword(const Persona* p, string pw){
    if(p){
        return p->getPassword()== pw;
    }
    return 0;
}

void QueuePersone::changePassword(Persona* p, string nuova) {
    p->setPassword(nuova);
}

bool QueuePersone::importXml() {
    clean();
    bool ok = false;

    QFile file(getDefaultFile());
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        QXmlStreamReader xmlInput(&file);

        while(xmlInput.readNextStartElement()) {
            if(xmlInput.name() == getStartTagXml()){
                while(xmlInput.readNextStartElement())
                {
                    //legge il nome della classe (tag persona)
                    std::string classname = (xmlInput.name().toString()).toStdString();

                    try
                    {

                        Persona* p = 0;
                        if (classname == "MEDICO"){ p =Medico::importXml(xmlInput); }
                        if (classname == "INFERMIERE"){ p = Infermiere::importXml(xmlInput);}
                        if (classname == "RESPONSABILE"){ p = Responsabile::importXml(xmlInput);}

                        if(p)
                        {
                            push_back(p->clone());
                            delete p;
                            ok = true;
                        }
                        //porta il puntatore all'elemento successivo
                        xmlInput.skipCurrentElement();
                    }
                    catch(errore_tag e)
                    {
                        //salta al prossimo elemento
                        while (!xmlInput.isEndElement() || xmlInput.name() != QString::fromStdString(classname))
                            xmlInput.readNext();
                    }
               }
            }
        }
    }
    file.close();
    return ok;
}
void QueuePersone::defaultData() {
    clean();
    Responsabile r("admin", "admin");
    push_back(r.clone());
}