// queue.cpp -- implementacje metod klas Queue i Customer
#include "queue.h"
#include <cstdlib>   // (albo stdlib.h) -- funkcja rand()

// metody klasy Queue
Queue::Queue(int qs) : qsize(qs)
{
    front = rear = NULL;      // albo nullptr
    items = 0;
}

Queue::~Queue()
{
    Node * temp;
    while (front != NULL)     // do wyczerpania kolejki
    {
        temp = front;         // zachowanie adresu elementu bieżącego
        front = front->next;  // przesunięcie wskaźnika do elementu następnego
        delete temp;          // zwolnienie elementu spod zapamiętanego adresu
    }
}

bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}

int Queue::queuecount() const
{
    return items;
}

// dodaje element do kolejki
bool Queue::enqueue(const Item & item)
{
    if (isfull())
        return false;
    Node * add = new Node;     // utworzenie węzła
    // w przypadku niepowodzenia przydziału new zrzuci wyjątek std::bad_alloc
    add->item = item;          // ustawienie wskaźników węzłów
    add->next = NULL;          // albo nullptr;
    items++;
    if (front == NULL)         // jeśli kolejka jest pusta,
        front = add;           // umieść element na czele listy
    else
        rear->next = add;      // w przeciwnym przypadku dołącz do końca
    rear = add;                // rear wskazuje teraz nowy węzeł
    return true;
}

// kopiuje element czołowy kolejki do argumentu wywołania i  usuwa go z kolejki
bool Queue::dequeue(Item & item)
{
    if (front == NULL)
        return false;
    item = front->item;    // skopiowanie do item pierwszego elementu z kolejki
    items--;
    Node * temp = front;   // zachowanie położenia pierwszego elementu
    front = front->next;   // przestawienie wskaźnika front na następny element
    delete temp;           // usunięcie dotychczasowego pierwszego elementu
    if (items == 0)
        rear = NULL;
    return true;
}

// metody klasy Customer

// kiedy klient trafia do kolejki, zapamiętywany jest bieżący
// czas systemowy, losowany jest też czas obsługi klienta
// (z zakresu od 1 do 3)
void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}

