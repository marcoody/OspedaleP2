#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include "data.h"
#include <vector>
enum giorni{lunedi=0, martedi=1, mercoledi=2, giovedi=3, venerdi=4, sabato=5, domenica=6};
enum gender{maschio=0, femmina=1, altro=3};
#define u_int unsigned short

using std::string;
using std::vector;

class Persona{
private:
    int idPersona;
    string nomePersona;
    string cognPersona;
    data dataNascita;
    gender genere;
public:
    virtual ~Persona(){};
    virtual Persona* clone() const = 0;

    //metodi get per i campi privati (da valutare se mettere protected)
    u_int getIdPersona();
    string getNomePersona();
    string getCognPersona();
    data getDataNascita();
    gender getGenere();

    //metodi per cambiare i campi privati (tutti tranne idPersona)
    void cambiaNome(string&);
    void cambiaCogn(string&);
    void cambiaDataNascita(const data&);
    void cambiaGenere(gender);


protected:
    Persona(u_int, string, string, const data& = data(), const gender& =altro);
    Persona(const Persona&);

};

class Dipendente: public Persona{
private:
    bool giorniTurno[7];
public:
    virtual Dipendente* clone() const=0;
    virtual double stipendio()const=0;

    bool inTurno(const giorni& g) const; //controlla se il giono g il dipendente è di turno, ritorna bool
    u_int numGiorniLavoro() const; //controlla il numero di giorni alla sett in cui il dipendente lavora
    void prendiPermesso(const giorni& g); //mette il giorno g in false, non lavorerà quel giorno
protected:
    Dipendente(u_int, string, string, const data& = data(), const gender& =altro, bool* =0);
    Dipendente(const Dipendente&); //??

};

class Paziente; //dich incompleta per poter implementare la classe Medico

class Medico: virtual public Dipendente{
private:
    static double pagaPerOraMedico;
    vector<const Paziente*> pazienti;
public:
    Medico(u_int, string, string, const data& = data(), const gender& =altro, bool* =0, std::vector<const Paziente*> = std::vector<const Paziente*>());
    virtual ~Medico(); //SERVE RIDEFINIRLO?
    virtual Medico* clone() const;
    virtual double stipendio() const;

    vector<const Paziente*>& getPazienti();

    void aggiungiPaziente(const Paziente*);
    void togliPaziente(const Paziente*);
protected:
    Medico(const Medico&);
};
double Medico::pagaPerOraMedico=25.0;

class Infermiere: virtual public Dipendente{
private:
    bool responsabile;
    static double pagaPerOraInf;
public:
    Infermiere(u_int, string, string, const data& = data(), const gender& =altro, bool* =0, bool=0);
    virtual Infermiere* clone() const;
    virtual double stipendio() const;

    bool isResponsabile() const;
    void cambiaResponsabile(bool); //cambia lo status dell'infermiere da responsabile a "normale" e viceversa

protected:
    Infermiere(const Infermiere&);
};
double Infermiere::pagaPerOraInf=20.0;

class Chirurgia: public Medico, public Infermiere{
private:
    //qui è meglio un array o un vector?
    Medico* medChirurgia;
    Infermiere* infChirurgia;
    vector<const Paziente*> daOperare;
public:
    Chirurgia( u_int, string, string, u_int, string, string, const data& = data(), const gender& =altro, bool* =0, vector<const Paziente*> = vector<const Paziente*>(),const data& = data(), const gender& =altro, bool* =0, bool=0, vector<const Paziente*> = vector<const Paziente*> ());

    void cambiaEquipe(const Medico* =0, const Infermiere* =0);
    void addPazienteDaOperare(const Paziente*);
    void delPazienteDaOperare(const Paziente*);
};

class Paziente: public Persona{
private:
    data inizioRicovero;
    data fineRicovero;
    bool deceduto;
    Medico* medicoAssegnato;
public:
    virtual Paziente* clone() const;

    Paziente(u_int, string, string, Medico*, const data& =data(), const gender& =altro, const data& =data(), const data& =data(), bool=0);
    data getInizioRic()const;
    data getFineRic() const;
    bool isDeceduto() const;
    Medico* getMedicoAssegnato() const;

    void modFineRicovero(const data&); //modifica la data di fine ricovero
    void modDeceduto(bool);
    void modMedicoAssegnato(Medico*);
protected:
    Paziente(const Paziente&);

};
#endif // PERSONA_H
