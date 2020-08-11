#include "../header/colore.h"

Colore::Colore(unsigned short int re, unsigned short int gr, unsigned short int bl): r(re), g(gr), b(bl) {};

unsigned short int Colore::getR() const { return r; }
unsigned short int Colore::getG() const { return g; }
unsigned short int Colore::getB() const { return b; }
