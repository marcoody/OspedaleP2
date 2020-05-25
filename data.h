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
enum giorni {lunedi=0, martedi=1, mercoledi=2, giovedi=3, venerdi=4, sabato=5, domenica=6};
class Data {
    friend ostream& operator<<(ostream&, const Data&);
private:
    u_int _giorno;
    u_int _mese;
    u_int _anno;
public:
    //mettiamo un qualcosa di defalut?
    Data(u_int = 1, u_int = 1, u_int = 1970);
    Data(const Data& d);
    Data& operator=(const Data& d);
    ~Data();

    u_int getGiorno() const;
    u_int getMese() const;
    u_int getAnno() const;
    //è meglio che ritorni un'altra data al posto di modif l'ogg di invocazione? (e renderla const)
    // <Elia: Io direi che è meglio lasciarla cosi, perché se invoco avanzaUnGiorno(), mi
    // aspetto che modifichi l'ogg d'invocazione avanzando di un giorno.>
    void avanzaUnGiorno();
    
    // Operatore di incremento prefisso
    Data& operator++();
    // Operatore di incremento postfisso
    Data operator++(int);
    // Operatore di somma
    Data operator+(int) const;
    // Operatore di uguaglianza
    bool operator==(const Data&) const;
    //servono per calcolare il giorno della settimana in base alla data//
    int giorniDaInizioAnno() const;
    int giorniDal1Gen1900() const;
    giorni giornoSettimana()const;
    
};
//li metto fuori perchè non mi serve l'ogg di invocazione
bool isBisestile(u_int a);
int giorniNelMese(u_int m, u_int a);
//la metto fuori perchè non voglio che abbia un ogg di invocazione
//oppure è meglio mettela dentro, creare un ogg temporaneo con i dati di costruzione e poi eliminarlo?
bool checkData(u_int g, u_int m, u_int a);
#endif // DATA_H
