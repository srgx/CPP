#include <iostream>
#include <string>
#include <cstring>
#include <array>

using namespace std;

void exercise1(); void exercise2(); void exercise3();
void exercise4(); void exercise5(); void exercise6();
void exercise7(); void exercise8(); void exercise9();
void exercise10();

struct Batonik{
  char marka [30];
  float waga;
  int kalorie;
};

struct Pizza{
  char nazwa [30];
  float srednica;
  float waga;
};

int main(){
  exercise1();
}

void exercise1(){
  const int ArSize = 30;
  cout << "Jak masz na imię: ";
  char name[ArSize]; cin.getline(name,ArSize);
  cout << "Jak się nazywasz: ";
  char last[ArSize]; cin.getline(last,ArSize);
  cout << "Na jaką ocenę zasługujesz: ";
  int ocena; cin >> ocena;
  cout << "Ile masz lat: ";
  int wiek; cin >> wiek;
  cout << "Nazwisko: " << last << ", " << name << endl;
  cout << "Ocena: " << ocena - 1 << endl;
  cout << "Wiek: " << wiek << endl;
}

void exercise2(){
  cout << "Podaj swoje imię: ";
  string name; getline(cin,name);
  cout << "Podaj swój ulubiony deser: ";
  string dessert; getline(cin,dessert);
  cout << "Mam dla Ciebie " << dessert << ", " << name << endl;
}

void exercise3(){
  const int ArSize = 30;
  cout << "Podaj imię: ";
  char imie [ArSize]; cin.getline(imie,ArSize);
  cout << "Podaj nazwisko: ";
  char nazwisko [ArSize]; cin.getline(nazwisko,ArSize);
  char wynik [ArSize*2];
  strcpy(wynik, nazwisko); strcat(wynik, ", "); strcat(wynik,imie);
  cout << "Oto informacje zestawione w jeden napis: " << wynik << endl;
}

void exercise4(){
  cout << "Podaj imię: ";
  string imie; getline(cin,imie);
  cout << "Podaj nazwisko: ";
  string nazwisko; getline(cin,nazwisko);
  string wynik; wynik = nazwisko + ", " + imie;
  cout << "Oto informacje zestawione w jeden napis: " << wynik << endl;
}

void exercise5(){
  Batonik snack = {"Mocha Munch",2.3,350};
  cout << "Marka: " << snack.marka << endl;
  cout << "Waga: " << snack.waga << endl;
  cout << "Kalorie: " << snack.kalorie << endl;
}

void exercise6(){
  Batonik bats [3];
  strcpy(bats[0].marka,"Snickers"); strcpy(bats[1].marka,"Mars"); strcpy(bats[2].marka,"Lion");
  bats[0].waga = 12.2; bats[1].waga = 6.8; bats[2].waga = 9.5;
  bats[0].kalorie = 88; bats[1].kalorie = 62; bats[2].kalorie = 33;
  
  cout << bats[0].marka << ", " << bats[0].waga << ", " << bats[0].kalorie << endl;
  cout << bats[1].marka << ", " << bats[1].waga << ", " << bats[1].kalorie << endl;
  cout << bats[2].marka << ", " << bats[2].waga << ", " << bats[2].kalorie << endl;
}

void exercise7(){
  const int ArSize = 30;
  Pizza pizza;
  cout << "Podaj nazwę firmy: "; cin.getline(pizza.nazwa,ArSize);
  cout << "Podaj średnicę pizzy: "; cin >> pizza.srednica;
  cout << "Podaj wagę pizzy: "; cin >> pizza.waga;
  cout << "Nazwa: " << pizza.nazwa << endl;
  cout << "Średnica: " << pizza.srednica << endl;
  cout << "Waga: " << pizza.waga << endl;
}

void exercise8(){
  const int ArSize = 30;
  Pizza * pizza = new Pizza;
  cout << "Podaj średnicę pizzy: "; cin >> pizza->srednica; cin.get();
  cout << "Podaj nazwę firmy: "; cin.getline(pizza->nazwa,ArSize);
  cout << "Podaj wagę pizzy: "; cin >> pizza->waga;
  cout << "Nazwa: " << pizza->nazwa << endl;
  cout << "Średnica: " << pizza->srednica << endl;
  cout << "Waga: " << pizza->waga << endl;
  delete pizza;
}

void exercise9(){
  Batonik * bats = new Batonik [3];
  strcpy(bats[0].marka,"Snickers"); strcpy(bats[1].marka,"Mars"); strcpy(bats[2].marka,"Lion");
  bats[0].waga = 12.2; bats[1].waga = 6.8; bats[2].waga = 9.5;
  bats[0].kalorie = 88; bats[1].kalorie = 62; bats[2].kalorie = 33;
  
  cout << bats[0].marka << ", " << bats[0].waga << ", " << bats[0].kalorie << endl;
  cout << bats[1].marka << ", " << bats[1].waga << ", " << bats[1].kalorie << endl;
  cout << bats[2].marka << ", " << bats[2].waga << ", " << bats[2].kalorie << endl;
  
  delete [] bats;
}

void exercise10(){
  const int rozmiar = 3;
  array<float,rozmiar> czasy;
  cout << "Podaj pierwszy czas: "; cin >> czasy.at(0);
  cout << "Podaj drugi czas: "; cin >> czasy.at(1);
  cout << "Podaj trzeci czas: "; cin >> czasy.at(2);
  float suma = czasy.at(0) + czasy.at(1) + czasy.at(2);
  float srednia = suma / rozmiar;
  cout << "Srednia: " << srednia << endl;
}

