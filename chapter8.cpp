#include <iostream>
#include <cstring>

using namespace std;

const int ArSize = 40;

struct Batonik{
  char marka[ArSize];
  double waga;
  int kalorie;
};

void exercise1(); void exercise2(); void exercise3(); void exercise4();

void pokazLancuch(const char * lancuch,int p = 0);
void ustawBatonik(Batonik & bat,
                  const char * marka = "Millenium Munch",
                  double waga = 2.85,
                  int kalorie = 350);
void pokazBatonik(const Batonik & bat);
void naWielkie(string & napis);


int main(){
  exercise4();
}

void exercise1(){
  cout << "Pierwsze wywołanie bez parametru:\n";
  pokazLancuch("Miło mi cię widzieć\n");
  cout << "Drugie wywołanie bez parametru:\n";
  pokazLancuch("Co słychać?\n");
  cout << "Trzecie wywołanie z parametrem:\n";
  pokazLancuch("Jak się masz?\n",5);
}

void exercise2(){
  Batonik b;
  cout << "Batonik z wartościami domyślnymi:\n";
  ustawBatonik(b); pokazBatonik(b);
  cout << "Batonik z przekazanymi wartościami:\n";
  ustawBatonik(b,"Snickers",3.14,450); pokazBatonik(b);
}

void exercise3(){
  cout << "Podawaj łańcuchy: ";
  string napis; getline(cin,napis);
  while(napis.length()!=1||napis[0]!='q'){
    naWielkie(napis); cout << napis << endl;
    cout << "Następny łańcuch(q aby zakończyć): "; getline(cin,napis);
  }
}

void exercise4(){
  cout << "Czesc\n";
}

void pokazLancuch(const char * lancuch, int p){
  static int count = 0; count++;
  if(p==0){
    cout << lancuch;
  } else{
    for(int i=0;i<count;i++){
      cout << lancuch;
    }
  }
}

void ustawBatonik(Batonik & bat,const char * marka, double waga,int kalorie){
  strcpy(bat.marka,marka);
  bat.waga = waga;
  bat.kalorie = kalorie;
}

void pokazBatonik(const Batonik & bat){
  cout << "Marka: " << bat.marka << endl;
  cout << "Waga: " << bat.waga << endl;
  cout << "Kalorie: " << bat.kalorie << endl;
}

// bez polskich znaków
void naWielkie(string & napis){
  int rozmiar = napis.length();
  for(int i=0;i<rozmiar;i++){ napis[i] = toupper(napis[i]); }
}

