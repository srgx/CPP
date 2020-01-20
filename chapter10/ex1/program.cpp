#include <iostream>
#include "rachunek.h"

int main(){
  Rachunek ra;
  std::cout << "Rachunek z wartościami domyślnymi:\n";
  ra.Pokaz();
  std::cout << "----\n";
  std::cout << "Ustawienie wartości konstruktorem:\n";
  ra = Rachunek("Jan","6678",45000.5);
  ra.Pokaz();
  std::cout << "----\n";
  std::cout << "Po wpłacie 999.5:\n";
  ra.Przyjmij(999.5);
  ra.Pokaz();
  std::cout << "----\n";
  std::cout << "Wydawanie 999999\n";
  ra.Wydaj(999999);
  std::cout << "----\n";
  std::cout << "Wydawanie 15000\n";
  ra.Wydaj(15000);
  ra.Pokaz();
  std::cout << "----\n";
  std::cout << "Koniec\n";
}
