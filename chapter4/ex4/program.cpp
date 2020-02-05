#include <iostream>

int main(){
  using namespace std;
  cout << "Podaj imię: ";
  string imie; getline(cin,imie);
  cout << "Podaj nazwisko: ";
  string nazwisko; getline(cin,nazwisko);
  string wynik; wynik = nazwisko + ", " + imie;
  cout << "Oto informacje zestawione w jeden napis: " << wynik << endl;
}
