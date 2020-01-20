#include <iostream>
#include "sales.h"

int main(){
  const int ArSize=3;
  SALES::Sales pierwszy, drugi;
  double vals[ArSize] = {12,34,55};
  pierwszy.Set();
  drugi = SALES::Sales(vals,ArSize);
  std::cout << "----\n";
  pierwszy.Show();
  std::cout << "----\n";
  drugi.Show();
  std::cout << "----\n";
  std::cout << "Koniec\n";
}
