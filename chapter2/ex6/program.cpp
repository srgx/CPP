#include <iostream>

int main(){
  std::cout << "Podaj liczbę lat świetlnych: ";
  const double au_in_year = 63240;
  double years;
  std::cin >> years;
  std::cout << years << " lat świetlnych to " << years * au_in_year
            << " jednostek astronomicznych\n";
}
