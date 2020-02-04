#include <iostream>

int main(){
  const float litry_na_galon = 3.875; const float mile_na_sto_km = 62.14;
  std::cout << "Zużycie benzyny na 100 km: ";
  float litry; std::cin >> litry;
  float galony = litry / litry_na_galon;
  std::cout << "Galony " << galony << std::endl;
  float mile_na_galon = mile_na_sto_km / galony;
  std::cout << litry << " litrów na 100 km to " << mile_na_galon << " mili na galon.\n";
}
