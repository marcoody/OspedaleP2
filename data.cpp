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

Data::Data(u_int g, u_int m, u_int a){
  if(checkData(g,m,a)) {
    _giorno = g; _mese = m; _anno = a;
  }
}

Data::Data(const Data& d) {
  //qui non faccio il controllo perchè è già stato fatto durante la creazione di data
  _giorno = d._giorno;
  _mese = d._mese;
  _anno = d._anno;
}

Data& Data::operator=(const Data& d){
  if(&d != this){
    _giorno = d._giorno;
    _mese = d._mese;
    _anno = d._anno;
  }
  return *this;
}

unsigned short Data::getGiorno() const { return _giorno; }
unsigned short Data::getMese() const { return _mese; }
unsigned short Data::getAnno() const { return _anno; }

bool Data::isBisestile() const {
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

void Data::avanzaUnGiorno(){
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
Data& Data::operator++() {
  this->avanzaUnGiorno();
  return *this;
}

// Operatore di incremento postfisso
Data Data::operator++(int) {
  Data temp = *this;
  this->avanzaUnGiorno();
  return temp;
}
 
Data Data::operator+(int x) const{
  Data tmp=*this;
  for(u_int i = 0; i < x; ++i) { tmp.avanzaUnGiorno(); }
  return tmp;
}

bool Data::operator==(const Data& d) const{
  return (d.getGiorno() == _giorno) && (d.getMese() == _mese) 
    && (d.getAnno() == _anno);
}

ostream &operator<<(ostream &os, const Data& d){
  return os << d._giorno << "/" << d._mese << "/" << d._anno;
}
