#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include <QXmlStreamWriter>
#include "data.h"

enum gender{maschio=0, femmina=1, altro=2};

#define u_int unsigned short

using std::string;

class Persona{
private:
    string username;
    string password;
    string nome;
    string cognome;
    Data dataNascita;
    gender genere;

public:

    Persona(string, string, string = "", string ="", const Data& = Data(), const gender& = gender::altro);

    //metodi get per i campi privati (da valutare se mettere protected)

    string getUsername() const;
    string getPassword() const;
    string getNome() const;
    string getCognome() const;
    Data getDataNascita() const;
    gender getGenere() const;

    //metodi per cambiare i campi privati (tutti tranne username)
    void setUsername(string&);
    void setPassword(string&);
    void setNome(string&);
    void setCognome(string&);
    void setDataNascita(const Data&);
    void setGenere(gender);

    //permessi
    virtual bool isResponsabile() const=0;
    virtual bool canAddTurni() const=0;
    virtual bool canEditTurni() const=0;

    //virtuali
    virtual ~Persona(){};
    virtual Persona* clone() const = 0;
    virtual string getTag() const = 0;
    virtual string infoPersona() const;
    virtual double stipendio() const = 0;

    //Import export
    virtual void exportXml(QXmlStreamWriter&) const;
    //metodi import
    static void importXmlData(QXmlStreamReader&, string&, string&, string&, string&, Data&, gender&);




    bool operator==(const Persona&) const;
    bool operator!=(const Persona&) const;

};

#endif // PERSONA_H
