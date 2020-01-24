// bank.cpp -- test interfejsu klasy Queue
// kompilować z plikiem queue.cpp
#include <iostream>
#include <cstdlib>             // funkcje rand() i srand()
#include <ctime>               // funkcja time()
#include "queue.h"
const int MIN_PER_HR = 60;
bool newcustomer(double x);    // czy dotarł już następny klient?

struct SimRes{
  long customers;
  long served;
  long turnaways;
  double avg_q;
  double avg_w;
};

SimRes simulate(int,int,double);
void normalMode();
void exerciseMode();

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

int main()
{
    char a;
    do{
      cout << "Tryb (n)ormalny czy tryb (z)adania(k aby zakonczyc): ";
      cin >> a;
      while(cin.get()!='\n')
        continue;
    }while(a!='n'&&a!='z'&&a!='k');

    if(a=='n'){
      normalMode();
    }else if(a=='z'){
      exerciseMode();
    }
    cout << "Gotowe!\n";
    return 0;
}

// x = średni odstęp czasowy (w minutach) pomiędzy potencjalnymi klientami
// jeśli wartość zwracana to true, w danej minucie pojawił się klient
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}

SimRes simulate(int qs, int hours, double perhour){

  Queue line(qs);
  Queue line2(qs);
  long cyclelimit = MIN_PER_HR * hours;

  double min_per_cust;
  min_per_cust = MIN_PER_HR / perhour;

  Item temp;                 // dane nowego klienta
  long turnaways = 0;        // liczba klientów odesłanych z kolejki
  long customers = 0;        // liczba klientów przyjętych do kolejki
  long served = 0;           // liczba klientów obsłużonych w symulacji
  long sum_line = 0;         // łączna liczba oczekujących
  int wait_time = 0;         // czas do zwolnienia bankomatu
  int wait_time2 = 0;
  long line_wait = 0;        // łączny czas oczekiwania

  for (int cycle = 0; cycle < cyclelimit; cycle++)
  {
      if (newcustomer(min_per_cust))  // mamy nowego chętnego
      {
          if (line.isfull()&&line2.isfull()){
            turnaways++;
          }
          else{
            customers++;
            temp.set(cycle);
            if(line.queuecount()<line2.queuecount()){
              line.enqueue(temp);
            }else{
              line2.enqueue(temp);
            }
          }
      }

      if (wait_time <= 0 && !line.isempty())
      {
          line.dequeue (temp);
          wait_time = temp.ptime();
          line_wait += cycle - temp.when();
          served++;
      }

      if (wait_time2 <= 0 && !line2.isempty())
      {
          line2.dequeue (temp);
          wait_time2 = temp.ptime();
          line_wait += cycle - temp.when();
          served++;
      }

      if (wait_time > 0)
          wait_time--;

      if (wait_time2 > 0)
          wait_time2--;

      // ile osób czeka w tym cyklu
      sum_line += line.queuecount() + line2.queuecount();
  }

  return SimRes{
    customers,
    served,
    turnaways,
    (double) sum_line / cyclelimit / 2, // średnia długość kolejki
    (double) line_wait / served // średni czas oczekiwania
  };
}

void normalMode(){
  // przygotowanie symulacji
  std::srand(std::time(0));  // inicjalizacja generatora liczb losowych

  cout << "Studium przypadku: bankomat Banku Stu Kas\n";
  cout << "Podaj maksymalną długość kolejki: ";
  int qs;
  cin >> qs;

  cout << "Podaj symulowany czas (w godzinach): ";
  int hours;                 // liczba godzin symulacji
  cin >> hours;

  cout << "Podaj średnią liczbę klientów na godzinę: ";
  double perhour;            // średnia liczba nowych klientów na godzinę
  cin >> perhour;

  SimRes re = simulate(qs,hours,perhour);

  // zestawienie wyników
  if (re.customers > 0)
  {
      cout << " liczba klientów przyjętych: " << re.customers << endl;
      cout << "liczba klientów obsłużonych: " << re.served << endl;
      cout << " liczba klientów odesłanych: " << re.turnaways << endl;
      cout << "    średnia długość kolejki: ";
      cout.precision(2);
      cout.setf(ios_base::fixed, ios_base::floatfield);
      cout.setf(ios_base::showpoint);
          cout << re.avg_q << endl;
      cout << "    średni czas oczekiwania: "
          << re.avg_w << " minut\n";
  }
  else
      cout << "Brak klientów!\n";
}


void exerciseMode(){
  std::srand(std::time(0));
  double i = 1;
  const int maxQ = 20;
  const int simTimeHours = 200;
  SimRes res = simulate(maxQ,simTimeHours,i);
  while(res.avg_w<1.0){
    i+=0.01;
    res = simulate(maxQ,simTimeHours,i);
  }
  cout << "Dla " << i << " klientów na godzinę "
  "czas oczekiwania wynosi "
  << res.avg_w << " minut." << endl;
  cout << "Maksymalna długość kolejki: "
  << maxQ << ", czas: " << simTimeHours << " godzin.\n";
}
