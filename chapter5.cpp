#include <iostream>
#include <array>

using namespace std;

void exercise1(); void exercise2(); void exercise3(); void exercise4();
void exercise5(); void exercise6(); void exercise7(); void exercise8();
void exercise9(); void exercise10();

int main(){
  exercise5();
}


void exercise1(){
  cout << "Podaj pierwszą liczbę: ";
  int pierwsza; std::cin >> pierwsza;
  cout << "Podaj drugą liczbę: ";
  int druga; std::cin >> druga;
  int suma = 0;
  for(int i=pierwsza;i<=druga;i++)
    suma += i;
    
  cout << "Suma liczb od " << pierwsza << " do " << druga << " to " << suma << endl;
}

void exercise2(){
  const int ArSize = 101; array<long double,ArSize> factorials;
  factorials[0] = factorials[1] = 1;
  for(int i=2;i<ArSize;i++)
    factorials[i] = i * factorials[i-1];
  cout << "100! = " << factorials[100] << endl;
}

void exercise3(){
  cout << "Podawaj liczby, 0 kończy wprowadzanie: ";
  int liczba; cin >> liczba;
  int suma = 0;
  while(liczba!=0){
    suma += liczba;
    cout << "Suma podanych liczb: " << suma << endl;
    cin >> liczba;
  }
  cout << "Gotowe\n";
}

void exercise4(){
  int cleo, dafne; dafne = cleo = 100; int rok = 1;
  while(cleo<=dafne){
    dafne += 0.1 * 100;
    cleo += (0.05 * cleo);
    cout << "Po " << rok << " latach: " << endl;
    cout << "Dafne: " << dafne << endl;
    cout << "Cleo: " << cleo << endl;
    rok++;
  }
}

void exercise5(){
  // ...
}
