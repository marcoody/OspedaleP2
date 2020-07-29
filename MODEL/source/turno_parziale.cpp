#include "../header/turno_parziale.h"
//costruttore
Turno_parziale::Turno_parziale(Data& d, u_int o, string r, bool c, double p): Turno(d,o), Turno_regolare(d,o,r), daContratto(c), paga_parziale(p){};

//metodi get
bool Turno_parziale::getDaContratto() const {return daContratto; }
double Turno_parziale::getPagaParziale() const { return paga_parziale; }

//metodi set
void Turno_parziale::setDaContratto(bool c) { daContratto=c; }
void Turno_parziale::setPagaParziale(double p) { paga_parziale=p; }

//metodi export
void Turno_parziale::exportXmlData(QXmlStreamWriter& out) const{
    Turno_regolare::exportXmlData(out);
    out.writeTextElement("daContratto", QString::fromStdString(std::to_string( getDaContratto())));
    out.writeTextElement("paga_parziale", QString::fromStdString(std::to_string(getPagaParziale())));
}

//metodi import
void Turno_parziale::importXmlData(QXmlStreamReader& in, bool& c, double& paga_parziale){
    string pagaString;
    string cString;
    importTagXml(in, "daContratto", cString);
    importTagXml(in, "paga_parziale", pagaString);
    c = std::stod(cString);
    paga_parziale = std::stod(pagaString);
}

Turno* Turno_parziale::importXml(QXmlStreamReader& in){
    Data dataTurno;
    u_int nOre;
    string reparto;
    bool daContratto;
    double paga_parziale;
    //legge dal file i tag e li memorizza in dataTurno e nOre
    Turno::importXmlData(in ,dataTurno, nOre);
    Turno_regolare::importXmlData(in, reparto);
    Turno_parziale::importXmlData(in, daContratto, paga_parziale);
    return new Turno_parziale(dataTurno, nOre, reparto, daContratto, paga_parziale);

}

//metodi virtual
Turno* Turno_parziale::clone() const {return new Turno_parziale(*this);}

double Turno_parziale::paga() const { return getNOre()*paga_parziale; }

string Turno_parziale::infoTurno() const {
    string s=Turno_regolare::infoTurno();
    s+= "\nPaga intero: " + std::to_string(getPagaParziale());
    return s;
}

const Colore Turno_parziale::getColor() const { return Colore(r,g,b); }
string Turno_parziale::getTag() const { return "PARZIALE"; }
