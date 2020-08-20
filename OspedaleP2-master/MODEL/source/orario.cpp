#include "../header/orario.h"



orario::orario(int o, int m, int s)     //COSTRUTTORE A DUE PARAMENTRI
{
    if(o<0 || o>23 || m<0 || m>59 || s<0 || s>59)
        sec=0;
    else sec=o*3600+m*60+s;
}

int orario::Ore() const {return sec/3600;}      //RITORNA ORE
int orario::Minuti() const {return (sec/60)%60;}    //RITORNA MINUTI
int orario::Secondi() const {return sec%60;}        //RITORNA SECONDI

orario orario::operator+(orario o)      //OPERATORE +
{
    orario aux;
    aux.sec=(sec+o.sec)%86400;
    return aux;
}

orario orario::operator-(orario o)      //OPERATORE -
{
    orario aux;
    aux.sec=(sec-o.sec)%86400;
    return aux;
}

bool orario::operator==(const orario& o)    //OPRATORE ==
{
    if(sec==o.sec)
        return true;
    else
        return false;
}

bool orario::operator>(orario o)        //OPERATORE >
{
    if(sec>o.sec)
        return true;
    else
        return false;
}

bool orario::operator<(orario o)    //OPERATORE <
{
    if(sec<o.sec)
        return true;
    else
        return false;
}

ostream& operator<<(ostream& os, const orario& o)   //OPERTAORE <<
{
    return os<<o.Ore()<<':'<<o.Minuti()<<':'<<o.Secondi();
}
