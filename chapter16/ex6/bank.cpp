// bank.cpp -- test interfejsu klasy Queue
// kompilować z plikiem queue.cpp
#include <iostream>
#include <cstdlib>             // funkcje rand() i srand()
#include <ctime>               // funkcja time()
#include "queue.h"
#include <queue>


const int MIN_PER_HR = 60;
bool newcustomer(double x);    // czy dotarł już następny klient?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    // przygotowanie symulacji
    std::srand(std::time(0));  // inicjalizacja generatora liczb losowych

    cout << "Studium przypadku: bankomat Banku Stu Kas\n";
    cout << "Podaj maksymalną długość kolejki: ";
    int qs;
    cin >> qs;
    std::queue<Item>line;

    cout << "Podaj symulowany czas (w godzinach): ";
    int hours;                 // liczba godzin symulacji
    cin >> hours;
    // symulacja z jednominutową rozdzielczością
    long cyclelimit = MIN_PER_HR * hours;       // liczba cykli

    cout << "Podaj średnią liczbę klientów na godzinę: ";
    double perhour;            // średnia liczba nowych klientów na godzinę
    cin >> perhour;
    double min_per_cust;       // średni odstęp czasowy pomiędzy klientami
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;                 // dane nowego klienta
    long turnaways = 0;        // liczba klientów odesłanych z kolejki
    long customers = 0;        // liczba klientów przyjętych do kolejki
    long served = 0;           // liczba klientów obsłużonych w symulacji
    long sum_line = 0;         // łączna liczba oczekujących
    int wait_time = 0;         // czas do zwolnienia bankomatu
    long line_wait = 0;        // łączny czas oczekiwania

    // rozpoczęcie symulacji
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))  // mamy nowego chętnego
        {
            if (line.size()>=qs)
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);        // czas przybycia = nr cyklu
                line.push(temp);     // dołączenie klienta do kolejki
            }
        }
        if (wait_time <= 0 && !line.empty())
        {
            temp = line.front();
            line.pop();        // następny do obsłużenia
            wait_time = temp.ptime();   // czas obsługi = wait_time
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.size();
    }

    // zestawienie wyników
    if (customers > 0)
    {
        cout << " liczba klientów przyjętych: " << customers << endl;
        cout << "liczba klientów obsłużonych: " << served << endl;
        cout << " liczba klientów odesłanych: " << turnaways << endl;
        cout << "    średnia długość kolejki: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout.setf(ios_base::showpoint);
            cout << (double) sum_line / cyclelimit << endl;
        cout << "    średni czas oczekiwania: "
            << (double) line_wait / served << " minut\n";
    }
    else
        cout << "Brak klientów!\n";

    cout << "Gotowe!\n";

    return 0;
}

// x = średni odstęp czasowy (w minutach) pomiędzy potencjalnymi klientami
// jeśli wartość zwracana to true, w danej minucie pojawił się klient
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
