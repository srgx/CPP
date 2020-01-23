#include <iostream>
#include "cow.h"

int main(){
  using std::cout; using std::endl;
  Cow klara;
  Cow milka("Milka","Czekolada",50);
  Cow wedel("Wedel","Batony",70);
  Cow milkaKopia(milka);
  klara = Cow("Klara","Cukierki",20);
  klara.ShowCow();
  milka.ShowCow();
  wedel.ShowCow();
  milkaKopia.ShowCow();

  klara.SetHobby("Filmy");
  milka.SetHobby("Gry");
  wedel.SetHobby("Zdjęcia");
  milkaKopia.SetHobby("Muzyka");
  cout << "*****Nowe Hobby*****\n";
  klara.ShowCow();
  milka.ShowCow();
  wedel.ShowCow();
  milkaKopia.ShowCow();
  cout << "Koniec\n";
}
