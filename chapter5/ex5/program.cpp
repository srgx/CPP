#include <iostream>

using namespace std;

const int MONTHS = 12;
const string MONTH_NAMES[MONTHS] = {
    "Styczeń", "Luty", "Marzec", "Kwiecień", "Maj", "Czerwiec",
    "Lipiec" ,"Sierpień", "Wrzesień" ,"Październik", "Listopad", "Grudzień"
};

int main(){
  int kwoty[MONTHS];
  for(int i=0;i<MONTHS;i++){
    cout << "Podaj kwotę za " << MONTH_NAMES[i] << ": "; cin >> kwoty[i];
  }
  int suma = 0;
  for(int i=0;i<MONTHS;i++)
    suma += kwoty[i];

  cout << "Łączna sprzedaż: " << suma << endl;
}
