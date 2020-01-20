#include <iostream>
#include "rachunek.h"

Rachunek::Rachunek(const std::string & str, const std::string & nr, float sld){
  nazwisko = str;
  numer = nr;
  saldo = sld;
}

Rachunek::Rachunek(){
  nazwisko = "";
  numer = "0000";
  saldo = 0;
}

void Rachunek::Pokaz() const{
  std::cout << "Nazwisko: " << nazwisko << std::endl;
  std::cout << "Numer: " << numer << std::endl;
  std::cout << "Saldo: " << saldo << std::endl;
}

void Rachunek::Przyjmij(float ile){
  saldo+=ile;
}

void Rachunek::Wydaj(float ile){
  if(ile>saldo){
    std::cout << "Za mało środków.\n";
  }else{
    saldo-=ile;
  }
}
