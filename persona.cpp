#include "persona.h"

// Costruttore di default
Persona::Persona() : Id("#000000"), Nome("Mario"), Cognome("Rossi") {}

// Costruttore
Persona::Persona(string i, string n, string c, const Data& d) :
  Id(i), Nome(n), Cognome(c), DataNascita(d) {}

// Costruttore di copia
Persona::Persona(const Persona& p) {
  Id = p.Id;
  Nome = p.Nome;
  Cognome = p.Cognome;
  DataNascita = p.DataNascita;
}

// Operatore di assegnazione
Persona& Persona::operator=(const Persona & p) {
  if(this != &p) {
  	Id = p.Id;
    Nome = p.Nome;
    Cognome = p.Cognome;
    DataNascita = p.DataNascita;
  }
  return *this;
} 
