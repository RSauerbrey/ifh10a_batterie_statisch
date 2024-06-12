#include "ladegeraet.h"

Ladegeraet::Ladegeraet()
{
    zustand = NichtLadend::getNichtLadend();
}

void Ladegeraet::setZustand( Zustand *zustand)
{
    this->zustand=zustand;
}

int Ladegeraet::getLadestand()
{
    return ladestand;
}

void Ladegeraet::ausloesen()
{
    zustand->bearbeiten(this);
}

void Ladegeraet::setLadestand(int ladestand )
{
    this->ladestand = ladestand;
}
