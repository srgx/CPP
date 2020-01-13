#include <iostream>

using namespace std;

struct pudlo{
  char producent[40];
  float wysokosc;
  float szerokosc;
  float dlugosc;
  float objetosc;
};

void exercise1(); void exercise2(); void exercise3(); void exercise4();
void exercise5(); void exercise6(); void exercise7(); void exercise8();
float sredniaHarmoniczna(float x,float y);
int wprowadzWyniki(float wyniki[],int rozmiar);
void pokazWyniki(const float wyniki[], int rozmiar);
float sredniaWynikow(const float wyniki[], int rozmiar);
void pokazPudlo(pudlo); void ustawPudlo(pudlo*);
long double probability(unsigned int numbers,unsigned int picks);
long double silnia(int x);
int fillArray(double liczby[],int rozmiar);
void showArray(const double liczby[],int rozmiar);
void reverseArray(double liczby[],int rozmiar);


double * fill_array(double * ar, double * limit);
void show_array(const double * ar, double * limit);
void revalue(double r,double * ar, double * limit);

int main(){
  exercise8();
}


void exercise1(){
  cout << "Podaj dwie liczby: ";
  int pierwsza,druga; cin >> pierwsza >> druga;
  while(pierwsza!=0&&druga!=0){
    cout << "Średnia harmoniczna: " << sredniaHarmoniczna(pierwsza,druga) << endl;
    cout << "Podaj kolejne dwie liczby: ";
    cin >> pierwsza >> druga;
  }
  cout << "Gotowe.\n";
}

void exercise2(){
  const int MAX_WYNIKI = 10; float wyniki[MAX_WYNIKI];
  int wprowadzono = wprowadzWyniki(wyniki,MAX_WYNIKI);
  pokazWyniki(wyniki,wprowadzono);
  cout << "Średnia wyników: " << sredniaWynikow(wyniki,wprowadzono) << endl;
}

void exercise3(){
  float wysokosc = 10; float szerokosc = 20; float dlugosc = 15;
  pudlo jakiesPudlo = {
    "Best Box",
    wysokosc, szerokosc,
    dlugosc, 0
  };
  cout << "Pudło przed ustawieniem objętości:\n";
  pokazPudlo(jakiesPudlo);
  cout << "Pudło po ustawieniu objętości:.\n";
  ustawPudlo(&jakiesPudlo); pokazPudlo(jakiesPudlo);
  cout << "Gotowe\n";
}

void exercise4(){
  double total, choices, powerball;
  cout << "Podaj najwiekszą liczbę jaką można wybrać,\nliczbę skreśleń oraz liczbę powerball: ";
  while((cin >> total >> choices >> powerball)&&(choices<=total)){
    cout << "Szanse wygranej to jeden do ";
    cout << probability(total,choices)*probability(powerball,1) << ".\n";
    cout << "Podaj trzy liczby(q aby zakończyć): ";
  }
  cout << "Do widzenia.\n";
}

void exercise5(){
  cout << "Podaj wartość dla której ma być obliczona silnia: ";
  int wartosc;

  while(cin >> wartosc && wartosc >= 0){
    cout << wartosc << "!: "
         << silnia(wartosc) << endl;
    cout << "Podaj kolejną liczbę(q aby zakończyć): ";
  }
  cout << "Do widzenia.\n";
}

void exercise6(){
  const int ROZMIAR = 5;
  double tablica [ROZMIAR];
  int wprowadzone = fillArray(tablica,ROZMIAR);
  cout << "Zawartość tablicy:\n";
  showArray(tablica,wprowadzone);
  cout << "Tablica po odwróceniu:\n";
  reverseArray(tablica,wprowadzone);
  showArray(tablica,wprowadzone);
}

void exercise7(){
  const int Max = 5;
  double properties[Max];
  double * limit = &properties[Max];
  limit = fill_array(properties,limit);
  show_array(properties,limit);
  if(limit!=&properties[0]){
    cout << "Podaj czynnik zmiany wartości: "; double factor;
    while(!(cin >> factor)){
      cin.clear();
      while(cin.get()!='\n')
        continue;
      cout << "Niepoprawne dane. Podaj liczbę: ";
    }
    revalue(factor,properties,limit);
    show_array(properties,limit);
  }
  cout << "Gotowe\n";
}

void exercise8(){
  cout << "Exercise 8\n";
}


float sredniaHarmoniczna(float x,float y){
  return 2.0*x*y/(x+y);
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

void pokazPudlo(pudlo pud){
  cout << "Producent: " << pud.producent << endl;
  cout << "Wysokość: " << pud.wysokosc << endl;
  cout << "Szerokość: " << pud.szerokosc << endl;
  cout << "Długość: " << pud.dlugosc << endl;
  cout << "Objętość: " << pud.objetosc << endl;
}

void ustawPudlo(pudlo * pt){
  pt->objetosc = pt->wysokosc * pt->szerokosc * pt->dlugosc;
}

long double probability(unsigned int numbers,unsigned int picks){
  long double result = 1.0; long double n; unsigned int p;
  for(n=numbers,p=picks;p>0;n--,p--){ result *= n/p; }
  return result;
}

long double silnia(int x){
  if(x==0){
    return 1;
  }else{
    return x * silnia(x-1);
  }
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

double * fill_array(double * pt, double * limit){
  double temp; int i;
  for(i=0;pt!=limit;i++){
    cout << "Podaj wartość nr " << i+1 << ": "; cin >> temp;
    if(!cin){
      cin.clear();
      while(cin.get()!='\n')
        continue;
      cout << "Błędne dane. Wprowadzanie danych przerwane.\n";
      break;
    }else if(temp < 0){ break; }
    *pt = temp; pt++;
  }
  return pt;
}

void show_array(const double * pt, double * limit){
  for(int i=0;pt!=limit;i++){
    cout << "Nieruchomość nr " << i+1 << ": ";
    cout << *pt << endl; pt++;
  }
}

void revalue(double r, double * pt, double * limit){
  for(int i=0;pt!=limit;i++){
    *pt *= r; pt++;
  }
}




