#include <iostream>
#include "move.h"

int main(){
  using std::cout;
  Move one, two;
  one = Move(5,7);
  two = Move(6,13);

  cout << "Pierwszy obiekt:\n";
  one.showmove();
  cout << "Drugi obiekt:\n";
  two.showmove();

  cout << "Suma obiektów:\n";
  Move sum = one.add(two);
  sum.showmove();

  cout << "Obiekty po zresetowaniu:\n";
  one.reset(); two.reset(); sum.reset();
  one.showmove(); two.showmove(); sum.showmove();
  cout << "Koniec\n";
}
