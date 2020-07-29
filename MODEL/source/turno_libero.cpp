#include "../header/turno_libero.h"

//costruttore
Turno_libero::Turno_libero(Data& d, u_int no, bool p):Turno(d,no), permesso(p){};

//metodi get
bool Turno_libero::getPermesso() const { return permesso; }

//metodi set
void Turno_libero::setPermesso(bool p) { permesso=p; }

//export
void Turno_libero::exportXmlData(QXmlStreamWriter& out) const {
    Turno::exportXmlData(out);
    out.writeTextElement("permesso", QString::fromStdString(std::to_string(getPermesso())));
}

//import
void Turno_libero::importXmlData(QXmlStreamReader& in, bool& permesso){
    string pString;
    importTagXml(in, "permesso", pString);
    permesso = stod(pString);
}

Turno* Turno_libero::importXml(QXmlStreamReader& in){
    Data dataTurno;
    u_int nOre;
    bool permesso;
    //legge dal file i tag e li memorizza in dataTurno e nOre
    Turno::importXmlData(in, dataTurno, nOre);
    Turno_libero::importXmlData(in,permesso);
    return new Turno_libero(dataTurno, nOre, permesso);

}

//virtuali
Turno* Turno_libero::clone() const { return new Turno_libero(*this);}

double Turno_libero::paga() const { return getNOre()*0; }

string Turno_libero::infoTurno() const {
    string s=Turno::infoTurno();
    s+= "\nPermesso: " + std::to_string(getPermesso());
    return s;
}

const Colore Turno_libero::getColor() const { return Colore(r,g,b); }

string Turno_libero::getTag() const { return "LIBERO"; }
