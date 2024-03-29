#include "../header/data.h"

//costruttori
Data::Data(u_int g, u_int m, u_int a){
  if(checkData(g,m,a)) {
    _giorno = g; _mese = m;
    if(contaCifre(a)==2){a+=1900;}
    _anno=a;
  }
  else{ throw err_data_nonvalida();}
}
Data::Data(const Data& d): _giorno(d._giorno), _mese(d._mese), _anno(d._anno) {
  //qui non faccio il controllo della legittimità di d perchè è già stato fatto durante la creazione di data
}

//assegnazione e distruzione
Data& Data::operator=(const Data& d){
  if(&d != this){
    _giorno = d._giorno;
    _mese = d._mese;
    _anno = d._anno;
  }
  return *this;
}
Data::~Data(){}

//metodi di get
u_int Data::getGiorno() const { return _giorno; }
u_int Data::getMese() const { return _mese; }
u_int Data::getAnno() const { return _anno; }
std::string Data::getGiornoString() const {
    std::string s;
    u_int g=getGiorno();
    if(g < 10){ s= "0"+std::to_string(g); }
    else { s= std::to_string(g); }
    return s;
}
std::string Data::getMeseString() const {
    std::string s;
    u_int m=getMese();
    if(m < 10){ s= "0"+std::to_string(m); }
    else { s= std::to_string(m); }
    return s;
}
std::string Data::getAnnoString() const {
    std::string s;
    s=std::to_string(getAnno());
    return s;
}

//manipolazione Data
void Data::avanzaUnGiorno(){
    if((_mese == 4 || _mese == 6 || _mese == 9 || _mese == 11) && (_giorno == 30)) { ++_mese; _giorno = 1; }
    //qui non faccio controllo sul mese perchè se l'ogg data esiste, significa che è corretto(vedi costruttore)
    //quindi tutte le date corrette che hanno _giorno==31 avranno _mese==(mesi da 31 giorni)
    else if(_giorno == 31) {_giorno = 1; ++_mese;}
    else if(_mese == 2 && _giorno == 28 && !isBisestile(_anno)){ _giorno = 1; _mese = 3; }
    else if(_mese == 2 && _giorno == 28 && isBisestile(_anno)) { ++_giorno; }
    //il fatto se sia bisestile è un controllo in più che faccio per sicurezza
    else if(_mese == 2 && _giorno == 29 && isBisestile(_anno)) { _giorno = 1; _mese = 3; }
    else if(_mese == 12 && _giorno == 31) { ++_anno; _mese = 1; _giorno = 1; }
    else{ _giorno++; }
}

std::string Data::dataToString() const{
    return getGiornoString()+"/"+getMeseString()+"/"+getAnnoString();
}

Data stringToData(std::string s){
    int g,m,a;
    const char* c= s.c_str();
    sscanf(c,"%2d/%2d/%4d", &g, &m, &a);
    Data ris=Data(g,m,a);
    return ris;
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
  return (d.getGiorno() == _giorno) && (d.getMese() == _mese) && (d.getAnno() == _anno);
}

//funzioni ausiliarie (LE METTO PRIVATE)
int Data::giorniDaInizioAnno() const{
    int tot=0;
    for(u_int i=1; i<_mese; ++i){
        tot+=giorniNelMese(i,_anno);
    }
    tot+=_giorno;
    return tot;
}

int Data::giorniDal1Gen1900() const{
    int bis=((_anno-1900-1)/4);
    int tot= bis*(366)+giorniDaInizioAnno();
    if((_anno-1900) != 0){tot+=(_anno-1900-bis)*365;}
    return tot-1; //conto da zero
}

//PUBLIC
giorni Data::giornoSettimana() const{ return giorni(giorniDal1Gen1900()%7);}


//METODI ESTERNI
bool isBisestile(u_int a){
  bool bisestile = false;
  if(a % 4 == 0) {
    bisestile = true;
    if(a % 100 == 0) {
      bisestile = false;
      if(a % 400 == 0) { bisestile = true; }
    }
  }
  return bisestile;
}
int giorniNelMese(u_int m, u_int a){
    if(m==2 && isBisestile(a)){return 29;}
    else if(m==2 && !isBisestile(a)){return 28;}
    else if(m==4 || m==6 || m==9 || m==11){return 30;}
    else{return 31;}
}
//checkdata esterna alla classe perchè volevo assicurarmi che un oggetto data costruito fosse SEMPRE legittimo
//-> se avessi messo la funz all'interno, avrebbe dovuro avere un ogg di invocazione di tipo data e non voglio che vengano creati data non legittimi
int contaCifre(int a){
    bool end=false; int cifre=1;
    while(!end){
        a/=10;
        if(a!=0){++cifre;}
        else{ end=true;}
    }
    return cifre;
}
bool checkData(u_int g, u_int m, u_int a){
  if(m > 12 || g > 31) { return false; }
  //controllo che gli anni siano scritti nella maniera corretta cioè AAAA
  int cifre=contaCifre(a);
  if(cifre==3 || cifre==1 || cifre>4){return false;}
  bool bisestile = isBisestile(a);

  if((m ==4 ||m == 6|| m == 9 || m == 11 ) && g > 30) { return false; }
  if(m == 2 && g > 29) { return false; }
  if(m == 2 && bisestile == false && g > 28) { return false; }
  return true;
}

ostream &operator<<(ostream &os, const Data& d){
  return os << d._giorno << "/" << d._mese << "/" << d._anno;
}

ostream &operator<<(ostream &os, const giorni &g) {
    switch(g) {
      case 0:
        return os << "lunedi";
        break;
      case 1:
        return os << "martedi";
        break;
      case 2:
        return os << "mercoledi";
        break;
      case 3:
        return os << "giovedi";
        break;
      case 4:
        return os << "venerdi";
        break;
      case 5:
        return os << "sabato";
        break;
      case 6:
        return os << "domenica";
        break;
      default:
        return os;
        break;
    }
}

std::istream& operator >>(std::istream& is, Data& d){
    int day, month, year;
    char ch1, ch2;
    if(is >> day >> ch1 >> month >> ch2 >> year){
        if (ch1 == '/' && ch2 == '/')
            d=Data(day, month, year);
        else
            is.setstate(std::ios::failbit);
    }
    return is;
}


std::string giornoToString(const giorni g) {
    switch(g) {
      case 0:
        return "lunedi";
        break;
      case 1:
        return "martedi";
        break;
      case 2:
        return "mercoledi";
        break;
      case 3:
        return "giovedi";
        break;
      case 4:
        return "venerdi";
        break;
      case 5:
        return "sabato";
        break;
      case 6:
        return "domenica";
        break;
    }
}

giorni stringToGiorni(const std::string s){
    if(s=="lunedì") { return giorni::lunedi; }
    if(s=="martedì") { return giorni::martedi; }
    if(s=="mercoledì") { return giorni::mercoledi; }
    if(s=="giovedì") { return giorni::giovedi; }
    if(s=="venerdì") { return giorni::venerdi; }
    if(s=="sabato") { return giorni::sabato; }
    if(s == "domenica") { return giorni::domenica; }
}

void avanzaGiorni(giorni & g){
    switch(g) {
      case 0:
        g = giorni::martedi;
        break;
      case 1:
        g = giorni::mercoledi;
        break;
      case 2:
        g = giorni::giovedi;
        break;
      case 3:
        g = giorni::venerdi;
        break;
      case 4:
        g = giorni::sabato;
        break;
      case 5:
        g = giorni::domenica;
        break;
      default:
        g = giorni::lunedi;
        break;
    }
}

int giornoToInt(giorni g){
    if(g == lunedi){ return 0;}
    else if (g == martedi) { return 1; }
    else if (g == mercoledi) { return 2; }
    else if (g == giovedi) { return 3; }
    else if (g == venerdi) { return 4; }
    else if (g == sabato) { return 5; }
    else { return 6; }
}

giorni intToGiorni(int g){
    if(g == 0){ return lunedi;}
    else if (g == 1) { return martedi; }
    else if (g == 2) { return mercoledi; }
    else if (g == 3) { return giovedi; }
    else if (g == 4) { return venerdi; }
    else if (g == 5) { return sabato; }
    else { return domenica; }
}
