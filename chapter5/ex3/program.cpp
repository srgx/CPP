#include <iostream>

int main(){
  using namespace std;
  cout << "Podawaj liczby, 0 kończy wprowadzanie: ";
  int liczba; cin >> liczba;
  int suma = 0;
  while(liczba!=0){
    suma += liczba;
    cout << "Suma podanych liczb: " << suma << endl;
    cin >> liczba;
  }
  cout << "Gotowe\n";
}
