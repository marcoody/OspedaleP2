#include "data.h"

bool checkData(u_int g, u_int m, u_int a){
  if(m > 12 || g > 31) { return false; }
  bool bisestile = false;
  if(a % 4 == 0){
    bisestile = true;
    if(a % 100 == 0){
      bisestile = false;
      if(a % 400 == 0) { bisestile = true; }
    }
  }
  if((m ==4 ||m == 6|| m == 9 || m == 11 ) && g > 30) { return false; }
  if(m == 2 && g > 29) { return false; }
  if(m == 2 && bisestile == false && g > 28) { return false; }
  return true;
}

data::data(u_int g, u_int m, u_int a){
  if(checkData(g,m,a)) {
    _giorno = g; _mese = m; _anno = a;
  }
}

data::data(const data& d) {
  //qui non faccio il controllo perchè è già stato fatto durante la creazione di data
  _giorno = d._giorno;
  _mese = d._mese;
  _anno = d._anno;
}

data& data::operator=(const data& d){
  if(&d != this){
    _giorno = d._giorno;
    _mese = d._mese;
    _anno = d._anno;
  }
  return *this;
}

unsigned short data::getGiorno() const { return _giorno; }
unsigned short data::getMese() const { return _mese; }
unsigned short data::getAnno() const { return _anno; }

bool data::isBisestile() const {
  bool bisestile = false;
  u_int a = getAnno();
  if(a % 4 == 0) {
    bisestile = true;
    if(a % 100 == 0) {
      bisestile = false;
      if(a % 400 == 0) { bisestile = true; }
    }
  }
  return bisestile;
}

void data::avanzaUnGiorno(){
    if((_mese == 4 || _mese == 6 || _mese == 9 || _mese == 11) && (_giorno == 30)) { ++_mese; _giorno = 1; }
    //qui non faccio controllo sul mese perchè se l'ogg data esiste, significa che è corretto(vedi costruttore)
    //quindi tutte le date corrette che hanno _giorno==31 avranno _mese==(mesi da 31 giorni)
    else if(_giorno == 31) {
      _giorno = 1;
      ++_mese;
    }
    else if(_mese == 2 && _giorno == 28 && !isBisestile()){ _giorno = 1; _mese = 3; }
    else if(_mese == 2 && _giorno == 28 && isBisestile()) { ++_giorno; }
    //il fatto se sia bisestile è un controllo in più che faccio per sicurezza
    else if(_mese == 2 && _giorno == 29 && isBisestile()) { _giorno = 1; _mese = 3; }
    else if(_mese == 12 && _giorno == 31) { ++_anno; _mese = 1; _giorno = 1; }
    else{ _giorno++; }
}

// Operatore di incremento prefisso
data& data::operator++() {
  this->avanzaUnGiorno();
  return *this;
}

// Operatore di incremento postfisso
data data::operator++(int) {
  data temp = *this;
  this->avanzaUnGiorno();
  return temp;
}
 
data data::operator+(int x) const{
  data tmp=*this;
  for(u_int i = 0; i < x; ++i) { tmp.avanzaUnGiorno(); }
  return tmp;
}

bool data::operator==(const data& d) const{
  return (d.getGiorno() == _giorno) && (d.getMese() == _mese) 
    && (d.getAnno() == _anno);
}


std::ostream &operator<<(std::ostream &os, const data& d){
  return os << d.getGiorno() << "/" << d.getMese() << "/" << d.getAnno();
}

