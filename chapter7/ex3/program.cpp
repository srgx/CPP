#include <iostream>

using namespace std;

struct pudlo{
  char producent[40];
  float wysokosc;
  float szerokosc;
  float dlugosc;
  float objetosc;
};

void pokazPudlo(pudlo p); void ustawPudlo(pudlo* pt);

int main(){
  float wysokosc = 10; float szerokosc = 20; float dlugosc = 15;
  pudlo jakiesPudlo = {
    "Best Box", wysokosc, szerokosc, dlugosc
  };
  cout << "Pudło przed ustawieniem objętości:\n";
  pokazPudlo(jakiesPudlo);
  cout << "Pudło po ustawieniu objętości:\n";
  ustawPudlo(&jakiesPudlo); pokazPudlo(jakiesPudlo);
  cout << "Gotowe\n";
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
