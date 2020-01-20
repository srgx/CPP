#include <iostream>
#include <cstring>
#include "plorg.h"


Plorg::Plorg(const char * im, int syt){
  strcpy(imie,im); ustawSytosc(syt);
}
void Plorg::ustawSytosc(int syt){
  sytosc = syt;
}

void Plorg::przedstawSie(){
  using std::cout; using std::endl;
  cout << "Mam na imię " << imie << endl;
  cout << "Współczynnik sytości " << sytosc << endl;
}
