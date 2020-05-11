#ifndef DATA_H
#define DATA_H
#include <iostream>

#define u_int unsigned short
class data{
private:
    u_int _giorno;
    u_int _mese;
    u_int _anno;
public:
    //mettiamo un qualcosa di defalut?
    data(u_int g, u_int m, u_int a);
    data(const data& d);
    data& operator=(const data& d);
    ~data(){};

    u_int getGiorno() const;
    u_int getMese()const;
    u_int getAnno()const;
    bool isBisestile()const;
    //è meglio che ritorni un'altra data al posto di modif l'ogg di invocazione? (e renderla const)
    void avanzaUnGiorno();

    data& operator++();
    data operator++(int);
    data operator+(int) const;
    bool operator==(data) const;

};

std::ostream& operator<<(std::ostream&, data);
//la metto fuori perchè non voglio che abbia un ogg di invocazione
//oppure è meglio mettela dentro, creare un ogg temporaneo con i dati di costruzione e poi eliminarlo?
bool checkData(u_int g, u_int m, u_int a);
#endif // DATA_H
