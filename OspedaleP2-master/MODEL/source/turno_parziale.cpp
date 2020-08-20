#include "../header/turno_parziale.h"
//costruttore
Turno_parziale::Turno_parziale(giorni d, QTime i, QTime f, string r, bool c, double p): Turno(d,i,f), Turno_regolare(d,i,f,r), daContratto(c), paga_parziale(p){};

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
    giorni giornoTurno;
    string reparto;
    QTime inizio;
    QTime fine;
    bool daContratto;
    double paga_parziale;
    //legge dal file i tag e li memorizza in dataTurno e nOre
    Turno::importXmlData(in ,giornoTurno, inizio, fine);
    Turno_regolare::importXmlData(in, reparto);
    Turno_parziale::importXmlData(in, daContratto, paga_parziale);
    return new Turno_parziale(giornoTurno, inizio, fine, reparto, daContratto, paga_parziale);

}

//metodi virtual
Turno* Turno_parziale::clone() const {return new Turno_parziale(*this);}

double Turno_parziale::paga() const { return TotOre()*paga_parziale; }

string Turno_parziale::infoTurno() const {
    string s=Turno_regolare::infoTurno();
    s+= "\nPaga intero: " + std::to_string(getPagaParziale());
    return s;
}

const Colore Turno_parziale::getColor() const { return Colore(r,g,b); }
string Turno_parziale::getTag() const { return "PARZIALE"; }
