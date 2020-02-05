#include <iostream>

using namespace std;

const int MONTHS = 12;
const string MONTH_NAMES[MONTHS] = {
    "Styczeń", "Luty", "Marzec", "Kwiecień", "Maj", "Czerwiec",
    "Lipiec" ,"Sierpień", "Wrzesień" ,"Październik", "Listopad", "Grudzień"
};

int main(){
  const int years = 3;

  int kwoty [years][MONTHS];
  for(int i=0;i<years;i++){
    cout << "Rok " << i+1 << endl;
    for(int j=0;j<MONTHS;j++){
      cout << "Podaj kwotę za " << MONTH_NAMES[j] << ": "; cin >> kwoty[i][j];
    }
  }

  int suma_lata = 0;
  for(int i=0;i<years;i++){
    int suma_rok = 0;
    for(int j=0;j<MONTHS;j++){
      suma_rok += kwoty[i][j];
    }
    cout << "Sprzedaż za rok " << i+1 << ": " << suma_rok << endl;
    suma_lata += suma_rok;
  }

  cout << "Sprzedaż razem: " << suma_lata << endl;
}
