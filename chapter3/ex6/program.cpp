#include <iostream>

int main(){
  std::cout << "Ile kilometrów przejechano: ";
  float kilometry; std::cin >> kilometry;
  std::cout << "Ile litrów benzyny zużyto: ";
  float litry; std::cin >> litry;
  float na_sto = (litry / kilometry) * 100;
  std::cout << "Zużycie wynosi " << na_sto << " litrów na 100 kilometrów.\n";
}
