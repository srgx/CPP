// workmi.cpp -- dziedziczenie wielokrotne
// kompilacja z plikiem workermi.cpp
#include <iostream>
#include <cstring>
#include "person.h"
const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    BadDude bd("Darth","Vader",1,2);
    auto crd = bd.PokerPlayer::Draw();

    bd.Show();
    crd.Show();

    Person * lolas[SIZE];
    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Podaj kategorię pracownika:\n"
            << "c: czlowiek  p:pokerzysta  "
            << "s: strzelec  b:bandyta  w:wyjście\n";
        cin >> choice;
        while (strchr("cpsbw", choice) == NULL)
        {
            cout << "Wpisz c, p, s, b lub w: ";
            cin >> choice;
        }
        if (choice == 'w')
            break;
        switch(choice)
        {
            case 'c': lolas[ct] = new Person;
                      break;
            case 'p': lolas[ct] = new PokerPlayer;
                      break;
            case 's': lolas[ct] = new Gunslinger;
                      break;
            case 'b': lolas[ct] = new BadDude;
                      break;
        }
        cin.get();
        lolas[ct]->Set();
    }

    cout << "\nLista osób:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas[i]->Show();
    }
    for (i = 0; i < ct; i++)
        delete lolas[i];
    cout << "Koniec.\n";
    return 0;
}
