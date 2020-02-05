#include <iostream>

using namespace std;

int fillArray(double liczby[],int rozmiar);
void showArray(const double liczby[],int rozmiar);
void reverseArray(double liczby[],int rozmiar);

int main(){
  const int ROZMIAR = 5;
  double tablica [ROZMIAR];
  int wprowadzone = fillArray(tablica,ROZMIAR);
  cout << "Zawartość tablicy:\n";
  showArray(tablica,wprowadzone);
  cout << "Tablica po odwróceniu:\n";
  reverseArray(tablica,wprowadzone);
  showArray(tablica,wprowadzone);
}

int fillArray(double liczby[],int rozmiar){
  cout << "Podaj do " << rozmiar << " wartości.\n";
  cout << "Wartość 1: "; int index = 0;
  while(index<rozmiar && cin >> liczby[index]){
    if(++index<rozmiar) { cout << "Wartość " << index+1 << ": "; }
  }
  return index;
}

void showArray(const double liczby[],int rozmiar){
  for(int i=0;i<rozmiar;i++){
    cout << liczby[i]; if(i<rozmiar-1) { cout << " "; }
  }
  cout << endl;
}

void reverseArray(double liczby[],int rozmiar){
  int start,end;
  for(start=0,end=rozmiar-1;start<end;start++,end--){
    double temp = liczby[start];
    liczby[start] = liczby[end];
    liczby[end] = temp;
  }
}
