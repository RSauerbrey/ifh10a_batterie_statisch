#include "zustand.h"
#include "ladegeraet.h"
#include <iostream>
using namespace std;

NichtLadend* NichtLadend::nichtLadend = nullptr;
NormalLadend* NormalLadend::normalLadend = nullptr;
SchnellLadend* SchnellLadend::schnellLadend = nullptr;

NichtLadend::NichtLadend()
{
    cout << "Zustand Nichtladend erzeugt" << endl;
}

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
    {
        ladegeraet->setZustand( NormalLadend::getNormalLadend() );
        cout << "Zustand Normalladend gesetzt" << endl;
    }
    //else
    // ladestand < 20 -> Akku defekt, bleibt in Nichtladend
    // ladestand == 100 -> Akku voll, bleibt in Nichtladend (wenn beim Start schon voll)
}

NormalLadend::NormalLadend()
{
    cout << "Zustand Normalladend erzeugt" << endl;
}

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
    {
        ladegeraet->setZustand( SchnellLadend::getSchnellLadend() );
        cout << "Zustand Schnellladend gesetzt" << endl;
    }
    else if( ladestand == 100 )
    {
        ladegeraet->setZustand( NichtLadend::getNichtLadend() );
        cout << "Zustand Nichtladend gesetzt" << endl;
    }
}

SchnellLadend::SchnellLadend()
{
    cout << "Zustand Schnellladend erzeugt" << endl;
}

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
    {
        ladegeraet->setZustand( NormalLadend::getNormalLadend() );
        cout << "Zustand Normalladend gesetzt" << endl;
    }
}
