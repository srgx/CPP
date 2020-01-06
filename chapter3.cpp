#include <iostream>

void exercise1(); void exercise2(); void exercise3();
void exercise4(); void exercise5(); void exercise6();

int main(){
  exercise6();
  return 0;
}

void exercise1(){
  const float cm_w_stopie = 30.48; const float cm_w_calu = 2.54;
  std::cout << "Podaj wzrost w centymetrach: ";
  float cm; std::cin >> cm;
  int stopy = cm / cm_w_stopie;
  float reszta_cm = cm - stopy * cm_w_stopie;
  float cale = reszta_cm / cm_w_calu;
  std::cout << "Masz " << stopy << " stóp i " << cale << " cali\n";
}

void exercise2(){
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

void exercise3(){
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

void exercise4(){
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

void exercise5(){
  std::cout << "Podaj liczbę ludności świata: ";
  long long swiat; std::cin >> swiat;
  std::cout << "Podaj liczbę ludności Polski: ";
  long long polska; std::cin >> polska;
  float wynik = (polska / float(swiat)) * 100;
  std::cout << "Populacja Polski stanowi " << wynik << "% populacji świata.\n";
}

void exercise6(){
  
}



