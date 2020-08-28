#include "../header/metodifreq.h"
#include <iostream>


void importTagXml(QXmlStreamReader & in, const std::string nome, std::string & cont) {
    while(in.readNextStartElement()) {
        if(in.name() == QString::fromStdString(nome)) {
            cont = (in.readElementText()).toStdString();
            return;
        }
        else in.skipCurrentElement();
    }
}
