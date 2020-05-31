#ifndef MODEL_H
#define MODEL_H
#include "data.h"
#include "persona.h"
#include "queue.h"
#include <istream>
#include <sstream>

using std::string;
using std::ifstream;

class Model{
private:
    Queue<Paziente*> pazientiOs;
    Queue<Dipendente*> dipendentiOs;

    void popolaDipendenti();
    void popolaPazienti();

public:
    Model();

    void resetTutto();

    //metodi per pazientiOs
    void nuovoPaziente(Paziente*p);
    void dimettiPaziente(Paziente*p);
    u_int numPazientiOs() const;


    //metodi per dipendentiOs


    //metodi di ricerca
    Queue<Paziente*>::iterator pazientePresente(Paziente*) const;
    Queue<Dipendente*>::iterator dipendentePresente(Dipendente*) const;
    Medico* idToMedico(u_int) const;
    Infermiere* idToInfermiere(u_int) const;
    u_int numDipendentiOs() const;

    //metodi di output
    void stampaDipendenti()const;

};
#endif // MODEL_H
