#include <iostream>
#include <cstring>

int main(){
  using namespace std;
  const int ArSize = 30;
  cout << "Podaj imię: ";
  char imie [ArSize]; cin.getline(imie,ArSize);
  cout << "Podaj nazwisko: ";
  char nazwisko [ArSize]; cin.getline(nazwisko,ArSize);
  char wynik [ArSize*2];
  strcpy(wynik, nazwisko); strcat(wynik, ", "); strcat(wynik,imie);
  cout << "Oto informacje zestawione w jeden napis: " << wynik << endl;
}
