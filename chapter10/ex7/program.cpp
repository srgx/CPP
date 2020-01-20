#include <iostream>
#include "plorg.h"

int main(){
  using std::cout;
  Plorg p1;
  p1.przedstawSie();
  cout << "Ustawiam sytość na 300\n";
  p1.ustawSytosc(300);
  p1.przedstawSie();

  Plorg p2 = Plorg("Venus",700);
  p2.przedstawSie();

  cout << "Koniec\n";
}
