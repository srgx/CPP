#include <iostream>
using namespace std;
#include "emp.h"

int main(void){

  employee em("Tadeusz", "Hubert", "Sprzedawca");
  cout << em << endl;
  em.ShowAll();

  manager ma("Amorfiusz","Smoczewski", "Malarz",5);
  cout << ma << endl;
  ma.ShowAll();

  fink fi("Maurycy", "Olkuski", "Hydraulik", "Julian Bar");
  cout << fi << endl;
  fi.ShowAll();

  highfink hf(ma, "Jan Kudłaty");
  hf.ShowAll();

  cout << "Wciśnij dowolny przycisk, aby przejść do następnego etapu:\n";
  cin.get();
  highfink hf2;
  hf2.SetAll();
  cout << "Używa wskaźnika abstr_emp *:\n";
  abstr_emp * tri[4] = { &em, &fi, &hf, &hf2};
  for(int i=0;i<4;i++){
    tri[i]->ShowAll();
  }

  return 0;
}
