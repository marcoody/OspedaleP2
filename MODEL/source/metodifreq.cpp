#include "../header/metodifreq.h"


void importTagXml(QXmlStreamReader& in, const std::string nome, std::string & cont){
    in.readNextStartElement();
    if (in.name() != QString::fromStdString(nome)){ throw errore_tag();}
    cont = (in.readElementText()).toStdString();

}
