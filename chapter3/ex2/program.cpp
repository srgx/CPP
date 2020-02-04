#include <iostream>

int main(){
  const int cale_w_stopie = 12; const float metry_w_calu = 0.0254;
  const float funty_w_kg = 2.2;
  std::cout << "Ile stóp: ";
  float stopy; std::cin >> stopy;
  std::cout << "Ile cali: ";
  float cale; std::cin >> cale;
  std::cout << "Waga w funtach: ";
  float funty; std::cin >> funty;
  float wzrost_cale = cale + stopy * cale_w_stopie;
  float wzrost_metry = wzrost_cale * metry_w_calu;
  float masa_kg = funty / funty_w_kg;
  float bmi = masa_kg / (wzrost_metry*wzrost_metry);
  std::cout << "Twoje BMI to " << bmi << std::endl;
}
