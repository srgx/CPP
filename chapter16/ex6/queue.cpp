// queue.cpp -- implementacje metod klas Queue i Customer
#include "queue.h"
#include <cstdlib>   // (albo stdlib.h) -- funkcja rand()


// metody klasy Customer

// kiedy klient trafia do kolejki, zapamiętywany jest bieżący
// czas systemowy, losowany jest też czas obsługi klienta
// (z zakresu od 1 do 3)
void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}
