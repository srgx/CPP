#include <iostream>

int main(){
  using namespace std;
  cout << "Podaj pierwszą liczbę: ";
  int pierwsza; cin >> pierwsza;
  cout << "Podaj drugą liczbę: ";
  int druga; cin >> druga;
  int suma = 0;
  for(int i=pierwsza;i<=druga;i++)
    suma += i;

  cout << "Suma liczb od " << pierwsza << " do " << druga << " to " << suma << endl;
}
