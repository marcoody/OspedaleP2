#include "data.h"

bool checkData(unsigned short g, unsigned short m, unsigned short a){
    if(m>12 || g>31){return false;}
    bool bisestile=false;
    if(a%4==0){
        bisestile=true;
        if(a%100==0){
            bisestile=false;
            if(a%400==0){bisestile=true;}
        }
    }
    if((m==4||m==6||m==9||m==11)&& g>30){return false;}
    if(m==2 && g>29){return false;}
    if(m==2 && bisestile==false && g>28){return false;}
    return true;
}

data::data(unsigned short g, unsigned short m, unsigned short a){
    if(checkData(g,m,a)){
        _giorno=g; _mese=m; _anno=a;
    }
}

data::data(const data & d){
    //qui non faccio il controllo perchè è già stato fatto durante la creazione di data
    _giorno=d._giorno;
    _mese=d._mese;
    _anno=d._anno;
}

data &data::operator=(const data &d){
    if(&d!=this){
        _giorno=d._giorno;
        _mese=d._mese;
        _anno=d._anno;
    }
    return *this;
}

unsigned short data::getGiorno()const { return _giorno;}
unsigned short data::getMese()const {return _mese;}
unsigned short data::getAnno()const {return _anno;}



