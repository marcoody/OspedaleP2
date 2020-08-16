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
    if(p) return p->getPassword() == pw;
    return 0;
}

void QueuePersone::changePassword(Persona* p, string nuova) {
    p->setPassword(nuova);
}

void QueuePersone::exportXml()
{
    QFile file(getDefaultFile());
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlOutput(&file);
    xmlOutput.setAutoFormatting(true);
    xmlOutput.writeStartDocument();

    xmlOutput.writeStartElement(getStartTagXml());
    for(auto ci = begin(); ci != end(); ++ci)
        (*ci)->exportXml(xmlOutput);
    xmlOutput.writeEndElement();
    xmlOutput.writeEndDocument();
    file.close();
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

                    try {
                        Persona* p = 0;
                        switch(classname) {
                            case "MEDICO": 
                                p = Medico::importXml(xmlInput);
                                break;
                            case "INFERMIERE":
                                p = Infermiere::importXml(xmlInput);
                                break;
                            case "RESPONSABILE":
                                p = Responsabile::importXml(xmlInput);
                                break;
                        }

                        if(p) {
                            push_back(p->clone());
                            delete p;
                            ok = true;
                        }
                        //porta il puntatore all'elemento successivo
                        //xmlInput.skipCurrentElement();
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
    Responsabile r("admin", "admin", "admin", "admin");
    push_back(r.clone());
}

unsigned short QueuePersone::nPersoneQueue() const{
   u_int tot = 0;
   for(QueuePersone::const_iterator it = begin(); it!=end(); ++it){
       ++tot;
   }
   return tot;
}

void QueuePersone::sortByName(){
    int i, j;
    Persona* key =0;
    for (i= 1; i != nPersoneQueue(); i++){
        key = *indexToIter(i);
        j = i-1;
        while (j >= 0 && ((*indexToIter(j))->getCognome() > key->getCognome())){
            *indexToIter(j + 1) = *indexToIter(j);
            j = j - 1;
        }

        *indexToIter(j + 1) = key;
    }
}
