#include <iostream>
#include <array>
#include <string>

using namespace std;

void exercise1(); void exercise2(); void exercise3(); void exercise4();
void exercise5(); void exercise6(); void exercise7(); void exercise8();
void exercise9(); void exercise10();


const int MONTHS = 12;
const string MONTH_NAMES[MONTHS] = {
    "Styczeń", "Luty", "Marzec", "Kwiecień", "Maj", "Czerwiec",
    "Lipiec" ,"Sierpień", "Wrzesień" ,"Październik", "Listopad", "Grudzień"
  };

int main(){
  exercise7();
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
  factorials.at(0) = factorials.at(1) = 1;
  for(int i=2;i<ArSize;i++)
    factorials.at(i) = i * factorials.at(i-1);
  cout << "100! = " << factorials.at(100) << endl;
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
  int kwoty[MONTHS];
  for(int i=0;i<MONTHS;i++){
    cout << "Podaj kwotę za " << MONTH_NAMES[i] << ": "; cin >> kwoty[i];
  }
  int suma = 0;
  for(int i=0;i<MONTHS;i++)
    suma += kwoty[i];
  
  cout << "Łączna sprzedaż: " << suma << endl;
   
}

void exercise6(){
  const int years = 3;
  
  int kwoty [years][MONTHS];
  for(int i=0;i<years;i++){
    cout << "Rok " << i+1 << endl;
    for(int j=0;j<MONTHS;j++){
      cout << "Podaj kwotę za " << MONTH_NAMES[j] << ": "; cin >> kwoty[i][j];
    }
  }
  
  int suma_lata = 0;
  for(int i=0;i<years;i++){
    int suma_rok = 0;
    for(int j=0;j<MONTHS;j++){
      suma_rok += kwoty[i][j];
    }
    cout << "Sprzedaż za rok " << i+1 << ": " << suma_rok << endl;
    suma_lata += suma_rok;
  }
  
  cout << "Sprzedaż razem: " << suma_lata << endl;
}

void exercise7(){
  // ...
}


