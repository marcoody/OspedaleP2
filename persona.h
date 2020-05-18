#ifndef PERSONA_H
#define PERSONA_H
#include "data.h"

using std::string;

class Persona {
  private:
  	string Id;
  	string Nome;
  	string Cognome;
  	Data DataNascita;
  public:
  	Persona();
  	Persona(string, string, string, const Data&);
  	Persona(const Persona&);
  	~Persona();
  	Persona& operator=(const Persona&);
	
};

#endif
