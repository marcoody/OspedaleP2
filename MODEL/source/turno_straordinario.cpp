#include "../header/turno_straordinario.h"

//costruttore
Turno_straordinario::Turno_straordinario(giorni d, u_int o, string r, bool p , bool v, double pa): Turno(d,o), Turno_regolare(d,o,r), Turno_libero(d,p), volontariato(v), paga_straordinario(pa){};

//metodi get
bool Turno_straordinario::getVolontariato() const {return volontariato; }
double Turno_straordinario::getPagaStraordinario() const { return paga_straordinario; }

//metodi set
void Turno_straordinario::setVolontariato(bool v) { volontariato=v; }
void Turno_straordinario::setPagaStraordinario(double p) { paga_straordinario=p; }

//metodi export
void Turno_straordinario::exportXmlData(QXmlStreamWriter& out) const {
    //radice
    Turno::exportXmlData(out);
    //regolare
    out.writeTextElement("reparto", QString::fromStdString(getReparto()));
    //libero
    out.writeTextElement("permesso", QString::fromStdString(std::to_string(getPermesso())));
    //propri
    out.writeTextElement("volontariato", QString::fromStdString(std::to_string(getVolontariato())));
    out.writeTextElement("paga_straordinario", QString::fromStdString(std::to_string(getPagaStraordinario())));

}

//metodi import
void Turno_straordinario::importXmlData(QXmlStreamReader& in, bool& volontariato, double& paga_straordinario){
    string vString, pString;
    importTagXml(in, "volontariato", vString);
    importTagXml(in, "paga_straordinario", pString);
    volontariato = stod(vString);
    paga_straordinario = stod(pString);
}
Turno* Turno_straordinario::importXml(QXmlStreamReader& in){
    giorni giorniTurno;
    u_int nOre;
    string reparto;
    bool permesso;
    bool volontariato;
    double paga_straordinario;
    //legge dal file i tag e li memorizza in dataTurno e nOre
    Turno::importXmlData(in, giorniTurno, nOre);
    Turno_regolare::importXmlData(in, reparto);
    Turno_libero::importXmlData(in, permesso);
    Turno_straordinario::importXmlData(in, volontariato, paga_straordinario);
    return new Turno_straordinario(giorniTurno, nOre, reparto, permesso, volontariato, paga_straordinario);
}

//metodi virtual
Turno* Turno_straordinario::clone() const { return new Turno_straordinario(*this);}
double Turno_straordinario::paga() const { return getNOre()*paga_straordinario*(!volontariato); }
string Turno_straordinario::infoTurno() const {
    string s= Turno_regolare::infoTurno();
    s+= "\nPermesso: " + std::to_string(getPermesso());
    s+= "\nVolontariato: " + std::to_string(getVolontariato());
    s+= "\nPaga straordinario: " + std::to_string(getPagaStraordinario());
    return s;
}

const Colore Turno_straordinario::getColor() const { return Colore(r,g,b); }
string Turno_straordinario::getTag() const { return "STRAORDINARIO"; }
