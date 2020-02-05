#include <iostream>
#include <array>

int main(){
  using namespace std;
  const int MAX_DATKI = 10;
  array<double,MAX_DATKI>datki;
  cout << "Podawaj wartości maksymalnie 10 datków('q' kończy wprowadzanie):\n";
  cout << "Datek 1: "; double datek; int index = 0;
  while(index < MAX_DATKI && cin >> datki.at(index)){
    if(++index<MAX_DATKI)
      cout << "Datek " << index+1 << ": ";
  }
  cout << "Otrzymano " << index << " datków.\n";
  double suma = 0;
  for(double x : datki)
    suma += x;
  cout << "Suma datków: " << suma << endl;
  double srednia = suma / index;
  cout << "Średnia wysokość datku: " << srednia << endl;
  cout << "Datki powyżej średniej: ";
  for(double x : datki)
    if(x>srednia) { cout << x << " "; }
  cout << endl;
}
