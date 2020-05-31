#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include "data.h"
#include <vector>
#include "turno.h"
#include "eccezioni.h"

enum gender{maschio=0, femmina=1, altro=2};
std::istream& operator>>(std::istream&, gender&);
enum ErroriPersone{Err_med=0, Err_persona};


#define u_int unsigned short

using std::string;
using std::vector;

class Persona{
private:
    int idPersona;
    string nomePersona;
    string cognPersona;
    Data dataNascita;
    gender genere;
public:
    virtual ~Persona(){};
    virtual Persona* clone() const = 0;
    virtual bool operator==(const Persona&) const;
    virtual bool operator!=(const Persona&) const;

    //metodi get per i campi privati (da valutare se mettere protected)

    u_int getIdPersona();
    string getNomePersona();
    string getCognPersona();
    Data getDataNascita();
    gender getGenere();

    //metodi per cambiare i campi privati (tutti tranne idPersona)
    void cambiaNome(string&);
    void cambiaCogn(string&);
    void cambiaDataNascita(const Data&);
    void cambiaGenere(gender);

     Persona& operator=(const Persona&);
protected:
    Persona(u_int, string, string, const Data& = Data(), const gender& =altro);
    Persona(const Persona&);


};

////////////////////////////////////////////////////////////

class Dipendente: public Persona{
private:
    Turno giorniTurno;
public:
    virtual Dipendente* clone() const=0;
    virtual double stipendio()const=0;

    bool inTurno(const giorni& g) const; //controlla se il giono g il dipendente è di turno, ritorna bool
    u_int numGiorniLavoro() const; //ritorna il numero di giorni alla sett in cui il dipendente lavora
    void cambiaTurno(const giorni&, const giorni&); //mette il giorno g in false, non lavorerà quel giorno

    void aggiungiTurno(const giorni&);
    void eliminaTurno(const giorni&);
protected:
    Dipendente(u_int, string, string, const Data& = Data(), const gender& =altro, const Turno& = Turno());
    Dipendente(const Dipendente&);
    Dipendente& operator=(const Dipendente&);

};

//////////////////////////////////////////////////////////////////////////

//PAZIENTE:
class Medico;
class Paziente: public Persona{
    friend Medico;
private:
    Data inizioRicovero;
    Data fineRicovero;
    bool deceduto;
    Medico* medicoAssegnato;
public:
    Paziente(u_int, string, string, Medico*, const Data& =Data(), const gender& =altro, const Data& =Data(), const Data& =Data(), bool=0);

    virtual Paziente* clone() const;
    virtual ~Paziente();

    //metodi get:
    Data getInizioRic()const;
    Data getFineRic() const;
    bool isDeceduto() const;
    Medico* getMedicoAssegnato() const;


    void modFineRicovero(const Data&); //modifica la data di fine ricovero
    void modDeceduto(bool);
    //NON PERMETTO DI MODIFICARE IL MEDICO ASSEGANTO PERCHè LO SPOSTAMENTO è DI COMPETENZA DEI MEDICI
protected:
    Paziente(const Paziente&);
    Paziente& operator=(const Paziente&);


};
/////////////////////////////////////////////////////////////////////////
//MEDICO:
class Medico: public Dipendente{
private:
    static double pagaPerOraMedico;
    vector<Paziente*> pazienti; //QUI VA CONST OPPURE NO??
public:
    Medico(u_int, string, string, const Data& = Data(), const gender& =altro, const Turno& = Turno(), std::vector<Paziente*> = std::vector<Paziente*>());
    friend Paziente::Paziente(u_int, string, string, Medico*, const Data&, const gender&, const Data&, const Data& , bool);
    virtual ~Medico(); //SERVE RIDEFINIRLO?
    virtual Medico* clone() const;
    virtual double stipendio() const;

    //metodi get
    vector< Paziente*>& getPazienti();
    vector<Paziente*>::iterator pazienteInLista(Paziente*);

    //modifiche campi privati
    void cediPaziente(Paziente*, Medico*);
    void aggiungiPaziente(Paziente*);
    void eliminaPaziente(Paziente*); //elimina definitivamente un paziente
protected:
    Medico(const Medico&);
    Medico& operator=(const Medico&);
};


////////////////////////////////////////////////////////////////////////

//INFERMIERE:

class Infermiere: public Dipendente{
private:
    bool responsabile;
    static double pagaPerOraInf;
public:
    Infermiere(u_int, string, string, const Data& = Data(), const gender& =altro, const Turno& = Turno(), bool =0);

    virtual Infermiere* clone() const;
    virtual double stipendio() const;

    bool isResponsabile() const;
    void cambiaResponsabile(bool); //cambia lo status dell'infermiere da responsabile a "normale" e viceversa
protected:

    Infermiere(const Infermiere&);
    Infermiere& operator=(const Infermiere&);


};


///////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////

//OPERAZIONE:
class Operazione{
private:
    Data dataOp;
    Medico* medOp;
    Infermiere* infOp;
public:
    Operazione(const Data&, Medico*, Infermiere*);

    Data getDataOp() const;
    Medico* getMedOp() const;
    Infermiere* getInfOp() const;

    void modDataOp(const Data&);
    void modMedOp(Medico*);
    void modInfOp(Infermiere*);

    bool operator==(const Operazione&) const;
protected:
    Operazione(const Operazione&);
    Operazione& operator=(const Operazione&);
};

////////////////////////////////////////////////////////////////////

//PAZIENTE CHIRURGICO:

class PazienteChir: public Paziente, public Operazione{
private:
    bool conSuccesso;
    Persona& parente;
public:

    PazienteChir(u_int, string, string, Medico*, const Data&, Medico*, Infermiere*, Persona*,  const Data& =Data(), const gender& =altro, const Data& =Data(), const Data& =Data(), bool=0, bool=1);

    virtual PazienteChir* clone() const;

    //metodi get
    bool getConSuccesso() const;
    Persona& getParente() const;

    //metodi modifica
    void modConSuccesso(bool);
    void modParente(const Persona&);
protected:
    PazienteChir(const PazienteChir&);
    PazienteChir& operator=(const PazienteChir&);

};


#endif // PERSONA_H
