#ifndef TURNO_H
#define TURNO_H
#include "data.h"
#define u_int unsigned short
enum Errori{Err_turno=0};

class Turno{
private:
    bool turni[7];
public:
    Turno();
    Turno(bool*);
    Turno(const Turno&);
    Turno& operator=(const Turno& );
    ~Turno();

    bool inturno(const giorni&) const;
    u_int giornilavoro()const;
    void switchturno (const giorni&, const giorni&);
    void addTurno(const giorni&);
    void delTurno(const giorni&);

    bool operator==(const Turno&);
    bool operator!=(const Turno&);
};

#endif // TURNO_H
