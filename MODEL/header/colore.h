#ifndef COLORE_H
#define COLORE_H


class Colore{
private:
    unsigned short int r,g,b;

public:
    Colore(unsigned short int, unsigned short int, unsigned short int);

    unsigned short int getR() const;
    unsigned short int getG() const;
    unsigned short int getB() const;

};

#endif // COLORE_H
