#ifndef OSPEDALE_H
#define OSPEDALE_H
#include <iostream>
#include <vector>
#include <string>
#include "data.h"
#include "persona.h"

using std::vector;
using std::string;


class Ospedale{
private:
    vector<Paziente*> pazientiOsp;
    vector<Dipendente*> dipendentiOsp;
public:
    //HO MESSO COSì I DIPENDENTI >=1, MENTRE I PAZIENTI POSSONO ANCHE NON ESSERCI//
    Ospedale( vector<Dipendente*>, vector<Paziente*> = vector<Paziente*>());
    Ospedale(const Ospedale&);
    Ospedale& operator=(const Ospedale&);
    ~Ospedale();

    //metodi  get
    vector<Paziente*>& getPazientiOsp(); //LI RITORNO PER RIF ?-->MODIFICABILI
    vector<Dipendente*>& getDipendentiOsp();

    //altri metodi

    u_int numPazienti() const;
    u_int numDipendenti() const;
    u_int numOperazioniGiorno(const data&) const;
    u_int numPazientiChirurgici() const;
    u_int numOperazioniSuccesso() const;

    vector<Paziente*>::iterator cercaPazienteOsp(const Paziente&);
    vector<Dipendente*>::iterator cercaDipendenteOsp(const Dipendente&);

    void addPazienteOsp(const Paziente&);
    void delPazienteOsp(const Paziente&);
    void addDipendenteOsp(const Dipendente&);
    void delDipendenteOsp(const Dipendente&);

    void rimuoviDeceduti();
    void rimuoviDimessiData(const data&);
    vector<Paziente*>& pazientiDimessiData(const data&);
    vector<Paziente*>& pazientiRicoveratiData(const data&);
    vector<Medico*>& mediciInTurno(const data&);
    vector<Infermiere*>& infermieriInTurno(const data&);
    vector<Paziente*>& pazientiAssegnatiA(Medico*);
    vector<PazienteChir*>& pazientiOperatiDa(Medico*);



    double totaleStipendi() const;



};

#endif // OSPEDALE_H
