// workmi.cpp -- dziedziczenie wielokrotne
// kompilacja z plikiem workermi.cpp
#include <iostream>
#include <cstring>
#include "workermi.h"
const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    QueueTp<Worker*> queue;

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Podaj kategorię pracownika:\n"
            << "k: kelner  p:piosenkarz  "
            << "s: śpiewający kelner  w:wyjście\n";
        cin >> choice;
        while (strchr("kpsw", choice) == NULL)
        {
            cout << "Wpisz k, p, s lub w: ";
            cin >> choice;
        }
        if (choice == 'w')
            break;

        Worker * pt;
        switch(choice)
        {
            case 'k': pt = new Waiter;
                      break;
            case 'p': pt = new Singer;
                      break;
            case 's': pt = new SingingWaiter;
                      break;
        }
        cin.get();
        pt->Set();
        queue.enqueue(pt);
    }


    cout << "\nLista pracowników:\n";
    int i; Worker * pnt;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        queue.dequeue(pnt);
        pnt->Show();
    }
    //for (i = 0; i < ct; i++)
    //    delete lolas[i];
    cout << "Koniec.\n";

    return 0;
}
