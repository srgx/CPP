#include <iostream>
#include <array>

int main(){
  using namespace std;
  const int rozmiar = 3;
  array<float,rozmiar> czasy;
  cout << "Podaj pierwszy czas: "; cin >> czasy.at(0);
  cout << "Podaj drugi czas: "; cin >> czasy.at(1);
  cout << "Podaj trzeci czas: "; cin >> czasy.at(2);
  float suma = czasy.at(0) + czasy.at(1) + czasy.at(2);
  float srednia = suma / rozmiar;
  cout << "Srednia: " << srednia << endl;
}
