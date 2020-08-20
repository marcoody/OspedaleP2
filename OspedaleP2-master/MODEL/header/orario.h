#ifndef ORARIO_H
#define ORARIO_H

#include <ostream>

using std::ostream;

class orario
{
    public:
        orario(int=0, int=0, int=0);


        int Ore() const;
        int Minuti() const;
        int Secondi() const;


        void StampaSecondi() const;

        orario operator+(orario);
        orario operator-(orario);
        bool operator==(const orario&);
        bool operator>(orario);
        bool operator<(orario);

    protected:
        int sec;
};

ostream& operator<<(ostream& os, const orario& o);


#endif // ORARIO_H
