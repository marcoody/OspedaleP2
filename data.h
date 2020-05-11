#ifndef DATA_H
#define DATA_H
#include <iostream>

//<Elia: Per convenienza, così ci si risparmia di dover scrivere ogni volta std::>
using std::ostream;
// Opzionali, se servono basta decommentare
//using std::cout;
//using std::endl;

// <Elia: E' sempre meglio passare un riferimento costante, così ci risparmiamo
// chiamate inutili al costruttore di copia, dopo se sbaglio correggetemi,
// ma almeno rifacendomi al libro di P2, la maggior parte dei 'valori', sono 
// passati così>

#define u_int unsigned short
class data {
private:
    u_int _giorno;
    u_int _mese;
    u_int _anno;
public:
    //mettiamo un qualcosa di defalut?
    data(u_int = 1, u_int = 1, u_int = 1970);
    data(const data& d);
    data& operator=(const data& d);
    ~data();

    u_int getGiorno() const;
    u_int getMese() const;
    u_int getAnno() const;
    bool isBisestile() const;
    //è meglio che ritorni un'altra data al posto di modif l'ogg di invocazione? (e renderla const)
    // <Elia: Io direi che è meglio lasciarla cosi, perché se invoco avanzaUnGiorno(), mi
    // aspetto che modifichi l'ogg d'invocazione avanzando di un giorno.>
    void avanzaUnGiorno();
    
    // Operatore di incremento prefisso
    data& operator++();
    // Operatore di incremento postfisso
    data operator++(int);
    // Operatore di somma
    data operator+(int) const;
    // Operatore di uguaglianza
    bool operator==(const data&) const;

};

ostream& operator<<(ostream&, const data&);
//la metto fuori perchè non voglio che abbia un ogg di invocazione
//oppure è meglio mettela dentro, creare un ogg temporaneo con i dati di costruzione e poi eliminarlo?
bool checkData(u_int g, u_int m, u_int a);
#endif // DATA_H
