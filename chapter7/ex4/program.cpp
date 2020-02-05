#include <iostream>

long double probability(unsigned int numbers,unsigned int picks);

int main(){
  using namespace std;
  double total, choices, powerball;
  cout << "Podaj najwiekszą liczbę jaką można wybrać,\nliczbę skreśleń oraz liczbę powerball: ";
  while((cin >> total >> choices >> powerball)&&(choices<=total)){
    cout << "Szanse wygranej to jeden do ";
    cout << probability(total,choices)*probability(powerball,1) << ".\n";
    cout << "Podaj trzy liczby(q aby zakończyć): ";
  }
  cout << "Do widzenia.\n";
}

long double probability(unsigned int numbers,unsigned int picks){
  long double result = 1.0; long double n; unsigned int p;
  for(n=numbers,p=picks;p>0;n--,p--){ result *= n/p; }
  return result;
}
