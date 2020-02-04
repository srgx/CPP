#include <iostream>

int main(){
  const float cm_w_stopie = 30.48; const float cm_w_calu = 2.54;
  std::cout << "Podaj wzrost w centymetrach: ";
  float cm; std::cin >> cm;
  int stopy = cm / cm_w_stopie;
  float reszta_cm = cm - stopy * cm_w_stopie;
  float cale = reszta_cm / cm_w_calu;
  std::cout << "Masz " << stopy << " stóp i " << cale << " cali\n";
}
