#include <iostream>

int main(){
  using namespace std;
  const int ArSize = 30;
  cout << "Jak masz na imię: ";
  char name[ArSize]; cin.getline(name,ArSize);
  cout << "Jak się nazywasz: ";
  char last[ArSize]; cin.getline(last,ArSize);
  cout << "Na jaką ocenę zasługujesz: ";
  int ocena; cin >> ocena;
  cout << "Ile masz lat: ";
  int wiek; cin >> wiek;
  cout << "Nazwisko: " << last << ", " << name << endl;
  cout << "Ocena: " << ocena - 1 << endl;
  cout << "Wiek: " << wiek << endl;
}
