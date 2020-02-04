#include <iostream>

int main(){
  const int sekundy_w_minucie = 60; const int minuty_w_stopniu = 60;
  std::cout << "Stopnie: ";
  float stopnie; std::cin >> stopnie;
  std::cout << "Minuty: ";
  float minuty; std::cin >> minuty;
  std::cout << "Sekundy: ";
  float sekundy; std::cin >> sekundy;
  float reszta_w_minutach = minuty + sekundy / sekundy_w_minucie;
  float reszta_w_stopniach = reszta_w_minutach / minuty_w_stopniu;
  float wynik = stopnie + reszta_w_stopniach;
  std::cout << stopnie << " stopni, "
            << minuty << " minut, "
            << sekundy << " sekund to "
            << wynik << " stopni.\n";
}
