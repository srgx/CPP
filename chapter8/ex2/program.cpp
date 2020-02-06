#include <iostream>
#include <cstring>

const int ArSize = 40;

struct Batonik{
  char marka[ArSize];
  double waga;
  int kalorie;
};

void ustawBatonik(Batonik & bat,
                  const char * marka = "Millenium Munch",
                  double waga = 2.85,
                  int kalorie = 350);
void pokazBatonik(const Batonik & bat);

int main(){
  using std::cout;
  Batonik b;
  cout << "Batonik z wartościami domyślnymi:\n";
  ustawBatonik(b); pokazBatonik(b);
  cout << "Batonik z przekazanymi wartościami:\n";
  ustawBatonik(b,"Snickers",3.14,450); pokazBatonik(b);
}

void ustawBatonik(Batonik & bat,const char * marka, double waga,int kalorie){
  strcpy(bat.marka,marka);
  bat.waga = waga;
  bat.kalorie = kalorie;
}

void pokazBatonik(const Batonik & bat){
  using std::cout; using std::endl;
  cout << "Marka: " << bat.marka << endl;
  cout << "Waga: " << bat.waga << endl;
  cout << "Kalorie: " << bat.kalorie << endl;
}
