#include <iostream>
#include "port.h"

int main(){
  using std::cout; using std::endl;
  Port pe("Gallo","lekko brązowy",20);
  VintagePort pe2("Philips",10,"Szlachetny",2000);

  VintagePort pe3(pe2);

  pe2.Modify(); pe2-=10;
  cout << pe2 << endl;
  cout << pe3 << endl;
  cout << "------------------------\n";

  VintagePort pe4;
  pe4 = pe3;
  pe3.Modify(); pe3+=5;
  cout << pe3 << endl;
  cout << pe4 << endl;

  cout << "------------------------\n";
  Port * pt = &pe4;
  pt->Show();
  cout << pt->BottleCount() << " butelek\n";
  cout << "------------------------\n";
  cout << "Koniec\n";
}
