#include <iostream>

int main(){
  std::cout << "Podaj swój wiek: ";
  int age_years;
  std::cin >> age_years;
  const int months = 12;
  std::cout << age_years << " lat to " << age_years * months << " miesięcy.\n";
}
