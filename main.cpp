#include "ladegeraet.h"
#include "zustand.h"

#include <iostream>
using namespace std;

int main()
{
    Ladegeraet* ladegeraet = new Ladegeraet();
    int ladestand = 10;
    while( ladestand < 100 )
    {
        cout << "Ladestand: " << ladestand << endl;
        ladegeraet->setLadestand( ladestand );
        ladegeraet->ausloesen();
        ladestand = ladestand + 10;
    }


    return 0;
}
