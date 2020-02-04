#include <iostream>

int main(){
  const int godziny_w_dniu = 24; const int minuty_w_godzinie = 60; const int sekundy_w_minucie = 60;
  const int sekundy_w_dniu = godziny_w_dniu*minuty_w_godzinie * sekundy_w_minucie;
  const int sekundy_w_godzinie = minuty_w_godzinie * sekundy_w_minucie;
  std::cout << "Podaj liczbę sekund: ";
  long sekundy; std::cin >> sekundy;
  int dni = sekundy / sekundy_w_dniu;
  int reszta = sekundy % sekundy_w_dniu;
  int godziny = reszta / sekundy_w_godzinie;
  reszta %= sekundy_w_godzinie;
  int minuty = reszta / sekundy_w_minucie;
  reszta %= sekundy_w_minucie;
  std::cout << sekundy << " sekund = "
            << dni << " dni, "
            << godziny << " godzin, "
            << minuty << " minut, "
            << reszta << " sekund.\n";
}
