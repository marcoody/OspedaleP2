#ifndef DATA_H
#define DATA_H
#include <iostream>

using std::ostream;
// Opzionali, se servono basta decommentare
//using std::cout;
//using std::endl;

#define u_int unsigned short
enum giorni {lunedi=0, martedi=1, mercoledi=2, giovedi=3, venerdi=4, sabato=5, domenica=6};

class Data {
    friend ostream& operator<<(ostream&, const Data&);
private:
    u_int _giorno;
    u_int _mese;
    u_int _anno;

    //servono per calcolare il giorno della settimana in base alla data//
    int giorniDaInizioAnno() const;
    int giorniDal1Gen1900() const;
public:
    Data(u_int = 1, u_int = 1, u_int = 1970); //DEFAULT?
    Data(const Data& d);
    Data& operator=(const Data& d);
    ~Data();

    u_int getGiorno() const;
    u_int getMese() const;
    u_int getAnno() const;
    void avanzaUnGiorno();

    // Operatore di incremento prefisso
    Data& operator++();
    // Operatore di incremento postfisso
    Data operator++(int);
    // Operatore di somma
    Data operator+(int) const;
    // Operatore di uguaglianza
    bool operator==(const Data&) const;
    // Calcola il giorno della settimana in base alla data di invocazione
    giorni giornoSettimana()const;

};
//li metto fuori perchè non mi serve l'ogg di invocazione
bool isBisestile(u_int a);
int giorniNelMese(u_int m, u_int a);
//la metto fuori perchè non voglio che abbia un ogg di invocazione
int contaCifre(int a);
bool checkData(u_int g, u_int m, u_int a);
ostream& operator<<(ostream&, const Data&);
ostream& operator<<(ostream&, const giorni&);
#endif // DATA_H
