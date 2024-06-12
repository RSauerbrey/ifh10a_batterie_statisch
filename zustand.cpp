#include "zustand.h"
#include "ladegeraet.h"

NichtLadend* NichtLadend::nichtLadend = nullptr;
NormalLadend* NormalLadend::normalLadend = nullptr;
SchnellLadend* SchnellLadend::schnellLadend = nullptr;

NichtLadend::NichtLadend()
{}

NichtLadend* NichtLadend::getNichtLadend()
{
    if( nichtLadend == nullptr )
        nichtLadend = new NichtLadend;
    return nichtLadend;
}

void NichtLadend::bearbeiten( Ladegeraet *ladegeraet)
{
    int ladestand = ladegeraet->getLadestand();
    if( ladestand >= 20 && ladestand < 100 )
        ladegeraet->setZustand( NormalLadend::getNormalLadend() );
    //else
    // ladestand < 20 -> Akku defekt, bleibt in Nichtladend
    // ladestand == 100 -> Akku voll, bleibt in Nichtladend (wenn beim Start schon voll)
}

NormalLadend::NormalLadend()
{}

NormalLadend* NormalLadend::getNormalLadend()
{
    if( normalLadend == nullptr )
        normalLadend = new NormalLadend;
    return normalLadend;
}

void NormalLadend::bearbeiten( Ladegeraet *ladegeraet)
{
    int ladestand = ladegeraet->getLadestand();
    if( ladestand < 80 )
        ladegeraet->setZustand( SchnellLadend::getSchnellLadend() );
    else if( ladestand == 100 )
        ladegeraet->setZustand( NichtLadend::getNichtLadend() );
}

SchnellLadend::SchnellLadend()
{}

SchnellLadend* SchnellLadend::getSchnellLadend()
{
    if( schnellLadend == nullptr )
        schnellLadend = new SchnellLadend;
    return schnellLadend;
}

void SchnellLadend::bearbeiten( Ladegeraet *ladegeraet)
{
    int ladestand = ladegeraet->getLadestand();
    if( ladestand >= 80 )
        ladegeraet->setZustand( NormalLadend::getNormalLadend() );
}
