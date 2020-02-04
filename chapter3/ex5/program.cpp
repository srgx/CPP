#include <iostream>

int main(){
  std::cout << "Podaj liczbę ludności świata: ";
  long long swiat; std::cin >> swiat;
  std::cout << "Podaj liczbę ludności Polski: ";
  long long polska; std::cin >> polska;
  float wynik = (polska / float(swiat)) * 100;
  std::cout << "Populacja Polski stanowi " << wynik << "% populacji świata.\n";
}
