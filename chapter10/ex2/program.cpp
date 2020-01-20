#include <iostream>
#include "person.h"

int main(){
  Person one;
  Person two("Staszek");
  Person three("Jacek","Placek");
  std::cout << "Obiekt 1:\n";
  one.Show(); std::cout << "----\n";
  std::cout << "Obiekt 2:\n";
  two.Show(); std::cout << "----\n";
  std::cout << "Obiekt 2 formalnie:\n";
  two.FormalShow(); std::cout << "----\n";
  std::cout << "Obiekt 3:\n";
  three.Show(); std::cout << "----\n";
  std::cout << "Obiekt 3 formalnie:\n";
  three.FormalShow(); std::cout << "----\n";
  std::cout << "Koniec\n";
}
