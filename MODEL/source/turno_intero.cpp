#include "../header/turno_intero.h"
//costruttore
Turno_intero::Turno_intero(Data& d, u_int o, string r, double p): Turno(d,o), Turno_regolare(d,o,r), paga_intero(p){};

//metodi get
double Turno_intero::getPagaIntero() const { return paga_intero; }

//metodi set
void Turno_intero::setPagaIntero(double p) { paga_intero=p; }

//metodi export
void Turno_intero::exportXmlData(QXmlStreamWriter& out) const{
    Turno_regolare::exportXmlData(out);
    out.writeTextElement("paga_intero", QString::fromStdString(std::to_string(getPagaIntero())));
}

//metodi import
void Turno_intero::importXmlData(QXmlStreamReader& in, double& paga_intero){
    string pagaString;
    importTagXml(in, "paga_intero", pagaString);
    paga_intero = std::stod(pagaString);
}

Turno* Turno_intero::importXml(QXmlStreamReader& in){
    Data dataTurno;
    u_int nOre;
    string reparto;
    double paga_intero;
    //legge dal file i tag e li memorizza in dataTurno e nOre
    Turno::importXmlData(in ,dataTurno, nOre);
    Turno_regolare::importXmlData(in, reparto);
    Turno_intero::importXmlData(in, paga_intero);
    return new Turno_intero(dataTurno, nOre, reparto, paga_intero);

}

//metodi virtual
Turno* Turno_intero::clone() const {return new Turno_intero(*this);}

double Turno_intero::paga() const { return getNOre()*paga_intero; }

string Turno_intero::infoTurno() const {
    string s=Turno_regolare::infoTurno();
    s+= "\nPaga intero: " + std::to_string(getPagaIntero());
    return s;
}

const Colore Turno_intero::getColor() const { return Colore(r,g,b); }
string Turno_intero::getTag() const { return "INTERO"; }
