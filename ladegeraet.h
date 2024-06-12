#ifndef LADEGERAET_H
#define LADEGERAET_H
#include "zustand.h"

class Ladegeraet
{
private:
    Zustand* zustand;
    int ladestand;

public:
    Ladegeraet();
    void setZustand( Zustand* );
    int getLadestand();
    void setLadestand(int); // nur zum Testen
    void ausloesen();
};

#endif // LADEGERAET_H
