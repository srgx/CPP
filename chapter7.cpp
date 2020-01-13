#include <iostream>

using namespace std;


struct pudlo{
  char producent[40];
  float wysokosc;
  float szerokosc;
  float dlugosc;
  float objetosc;
};

void exercise1(); void exercise2(); void exercise3(); void exercise4();
float sredniaHarmoniczna(float x,float y);
int wprowadzWyniki(float wyniki[],int rozmiar);
void pokazWyniki(const float wyniki[], int rozmiar);
float sredniaWynikow(const float wyniki[], int rozmiar);
void pokazPudlo(pudlo); void ustawPudlo(pudlo*);


int main(){
  exercise4();
}


void exercise1(){
  cout << "Podaj dwie liczby: ";
  int pierwsza,druga; cin >> pierwsza >> druga;
  while(pierwsza!=0&&druga!=0){
    cout << "Średnia harmoniczna: " << sredniaHarmoniczna(pierwsza,druga) << endl;
    cout << "Podaj kolejne dwie liczby: ";
    cin >> pierwsza >> druga;
  }
  cout << "Gotowe.\n";
}

void exercise2(){
  const int MAX_WYNIKI = 10; float wyniki[MAX_WYNIKI];
  int wprowadzono = wprowadzWyniki(wyniki,MAX_WYNIKI);
  pokazWyniki(wyniki,wprowadzono);
  cout << "Średnia wyników: " << sredniaWynikow(wyniki,wprowadzono) << endl;
}

void exercise3(){
  float wysokosc = 10; float szerokosc = 20; float dlugosc = 15;
  pudlo jakiesPudlo = {
    "Best Box",
    wysokosc, szerokosc,
    dlugosc, 0
  };
  cout << "Pudło przed ustawieniem objętości:\n";
  pokazPudlo(jakiesPudlo);
  cout << "Pudło po ustawieniu objętości:.\n";
  ustawPudlo(&jakiesPudlo); pokazPudlo(jakiesPudlo);
  cout << "Gotowe\n";
}

void exercise4(){
  cout << "Hello.\n";
}


float sredniaHarmoniczna(float x,float y){
  return 2.0*x*y/(x+y);
}

int wprowadzWyniki(float ar[],int rozmiar){
  cout << "Podawaj wyniki golfowe.\n";
  cout << "Wynik 1: "; int index = 0;
  while(index<rozmiar && cin >> ar[index]){
    if(++index<rozmiar) { cout << "Wynik " << index+1 << ": "; }
  }
  return index;
}

void pokazWyniki(const float ar[], int rozmiar){
  cout << "Wprowadzone wyniki: ";
  for(int i=0;i<rozmiar;i++){
    cout << ar[i]; if(i<rozmiar-1) { cout << " "; }
  }
  cout << endl;
}

float sredniaWynikow(const float ar[],int rozmiar){
  float suma = 0;
  for(int i=0;i<rozmiar;i++){ suma += ar[i]; }
  return suma / rozmiar;
}

void pokazPudlo(pudlo pud){
  cout << "Producent: " << pud.producent << endl;
  cout << "Wysokość: " << pud.wysokosc << endl;
  cout << "Szerokość: " << pud.szerokosc << endl;
  cout << "Długość: " << pud.dlugosc << endl;
  cout << "Objętość: " << pud.objetosc << endl;
}

void ustawPudlo(pudlo * pt){
  pt->objetosc = pt->wysokosc * pt->szerokosc * pt->dlugosc;
}


