#include <iostream>
#include "sales.h"

int main(){
  const int ArSize=3;
  SALES::Sales pierwszy, drugi;
  double vals[ArSize] = {12,34,55};
  setSales(pierwszy);
  setSales(drugi,vals,ArSize);
  std::cout << "----\n";
  showSales(pierwszy);
  std::cout << "----\n";
  showSales(drugi);
  std::cout << "----\n";
  std::cout << "Koniec\n";
}
