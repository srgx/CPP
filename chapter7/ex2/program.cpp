#include <iostream>

using namespace std;

int wprowadzWyniki(float wyniki[],int rozmiar);
void pokazWyniki(const float wyniki[], int rozmiar);
float sredniaWynikow(const float wyniki[], int rozmiar);

int main(){
  const int MAX_WYNIKI = 10; float wyniki[MAX_WYNIKI];
  int wprowadzono = wprowadzWyniki(wyniki,MAX_WYNIKI);
  pokazWyniki(wyniki,wprowadzono);
  cout << "Średnia wyników: " << sredniaWynikow(wyniki,wprowadzono) << endl;
}

int wprowadzWyniki(float ar[],int rozmiar){
  cout << "Podawaj wyniki golfowe.\n";
  cout << "Wynik 1: "; int index = 0;
  while(index<rozmiar && cin >> ar[index]){
    if(++index<rozmiar) { cout << "Wynik " << index+1 << ": "; }
  }
  return index;
}

void pokazWyniki(const float ar[], int rozmiar){
  cout << "Wprowadzone wyniki: ";
  for(int i=0;i<rozmiar;i++){
    cout << ar[i]; if(i<rozmiar-1) { cout << " "; }
  }
  cout << endl;
}

float sredniaWynikow(const float ar[],int rozmiar){
  float suma = 0;
  for(int i=0;i<rozmiar;i++){ suma += ar[i]; }
  return suma / rozmiar;
}
