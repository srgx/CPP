#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
T max5(T const ar[]);

template <typename T>
T maxn(T const ar[],int ile);

template <> const char * maxn(const char * const ar[], int ile);

template <typename T>
void ShowArray(T const arr[],int n);

template <typename T>
void ShowArray(T * const arr[], int n);

template <typename T>
T SumArray(T const arr[],int n);

template <typename T>
T SumArray(T * const arr[], int n);

const int ArSize = 40;

struct debts{
  char name[50];
  double amount;
};

struct Batonik{
  char marka[ArSize];
  double waga;
  int kalorie;
};

struct stringy{
  char * str;
  int ct;
};

void exercise1(); void exercise2(); void exercise3(); void exercise4();
void exercise5(); void exercise6(); void exercise7();

void pokazLancuch(const char * lancuch,int p = 0);
void ustawBatonik(Batonik & bat,
                  const char * marka = "Millenium Munch",
                  double waga = 2.85,
                  int kalorie = 350);
void pokazBatonik(const Batonik & bat);
void naWielkie(string & napis);

void set(stringy & str,const char ar[]);
void show(const stringy & str,int ile = 1);
void show(const char ar[], int ile = 1);


int main(){
  exercise1();
}

void exercise1(){
  cout << "Pierwsze wywołanie bez parametru:\n";
  pokazLancuch("Miło mi cię widzieć\n");
  cout << "Drugie wywołanie bez parametru:\n";
  pokazLancuch("Co słychać?\n");
  cout << "Trzecie wywołanie z parametrem:\n";
  pokazLancuch("Jak się masz?\n",5);
}

void exercise2(){
  Batonik b;
  cout << "Batonik z wartościami domyślnymi:\n";
  ustawBatonik(b); pokazBatonik(b);
  cout << "Batonik z przekazanymi wartościami:\n";
  ustawBatonik(b,"Snickers",3.14,450); pokazBatonik(b);
}

void exercise3(){
  cout << "Podawaj łańcuchy: ";
  string napis; getline(cin,napis);
  while(napis!="q"){
    naWielkie(napis); cout << napis << endl;
    cout << "Następny łańcuch(q aby zakończyć): "; getline(cin,napis);
  }
  cout << "Do widzenia.\n";
}

void exercise4(){
  stringy beany;
  char testing[] = "Rzeczywistość to już nie to, co kiedyś.";
  set(beany,testing);
  show(beany); cout << "--\n";
  show(beany,2); cout << "--\n";
  
  delete [] beany.str;
  
  testing[0] = 'D'; testing[1] = 'u';
  show(testing); cout << "--\n";
  show(testing,3); cout << "--\n";
  show("Gotowe!");
}

void exercise5(){
  int tablicaInt[5] = {12,34,66,21,7};
  double tablicaDouble[5] = {7.2,14.5,9,88.8,1};
  cout << "Maksymalna wartość z tablicy int: ";
  cout << max5(tablicaInt) << endl;
  cout << "Maksymalna wartość z tablicy double: ";
  cout << max5(tablicaDouble) << endl;
}

void exercise6(){
  const int IntSize = 5; const int DoubleSize = 4; const int IleNapisow = 5;
  int tablicaInt[IntSize] = {49,17,33,5,2};
  double tablicaDouble[DoubleSize] = {87.1,13,19,76.2};
  const char * napisy[IleNapisow] = {
    "Czesc",
    "Jak sie masz kochanie.",
    "Napisz szablon funkcji",
    "Przetestuj program",
    "New Retro Wave"
  };
  cout << "Maksymalna wartość z tablicy int: ";
  cout << maxn(tablicaInt,IntSize) << endl;
  cout << "Maksymalna wartość z tablicy double: ";
  cout << maxn(tablicaDouble,DoubleSize) << endl;
  cout << "Najdłuższy napis z tablicy: ";
  cout << maxn(napisy,IleNapisow) << endl;
}

void exercise7(){
  const int IleRzeczy = 6; const int IleDlugow = 3;
  int things[IleRzeczy] = {13,31,103,301,310,130};
  
  debts mr_E[IleDlugow] = {
    {"Ima Wolfe", 2400.0},
    {"Ura Foxe", 1300.0},
    {"Iby Stout", 1800.0}
  };
  
  double * pd[IleDlugow];
  for(int i=0;i<IleDlugow;i++){
    pd[i] = &mr_E[i].amount;
  }
  
  cout << "Wyliczanie rzeczy pana E.:\n";
  ShowArray(things,IleRzeczy);
  cout << "Wyliczanie długów pana E.:\n";
  ShowArray(pd,IleDlugow);
  cout << "Suma rzeczy pana E.:\n";
  cout << SumArray(things,IleRzeczy) << endl;
  cout << "Suma długów pana E.:\n";
  cout << SumArray(pd,IleDlugow) << endl;
  
}

void pokazLancuch(const char * lancuch, int p){
  static int count = 0; count++;
  if(p==0){
    cout << lancuch;
  } else{
    for(int i=0;i<count;i++){
      cout << lancuch;
    }
  }
}

void ustawBatonik(Batonik & bat,const char * marka, double waga,int kalorie){
  strcpy(bat.marka,marka);
  bat.waga = waga;
  bat.kalorie = kalorie;
}

void pokazBatonik(const Batonik & bat){
  cout << "Marka: " << bat.marka << endl;
  cout << "Waga: " << bat.waga << endl;
  cout << "Kalorie: " << bat.kalorie << endl;
}

// bez polskich znaków
void naWielkie(string & napis){
  int rozmiar = napis.length();
  for(int i=0;i<rozmiar;i++){ napis[i] = toupper(napis[i]); }
}

void set(stringy & str,const char ar[]){
  str.ct = strlen(ar); str.str = new char[str.ct+1];
  strcpy(str.str,ar);
}

void show(const stringy & str,int ile){
  for(int i=0;i<ile;i++){
    cout << str.str << endl;
  }
}

void show(const char ar[], int ile){
  for(int i=0;i<ile;i++){
    cout << ar << endl;
  }
}

template <typename T>
T max5(T const ar[]){
  const int ArSize = 5; T max = ar[0];
  for(int i=1;i<ArSize;i++){
    if(ar[i]>max) { max = ar[i]; }
  }
  return max;
}

template <typename T>
T maxn(T const ar[],int ile){
  T max = ar[0];
  for(int i=1;i<ile;i++){
    if(ar[i]>max) { max = ar[i]; }
  }
  return max;
}

template <> const char * maxn(const char * const ar[], int ile){
  const char * max = ar[0];
  int max_dlugosc = strlen(ar[0]);
  for(int i=1;i<ile;i++){
    int nowa_dlugosc = strlen(ar[i]);
    if(nowa_dlugosc>max_dlugosc){
      max = ar[i]; max_dlugosc = nowa_dlugosc;
    }
  }
  return max;
}

template <typename T>
void ShowArray(T const arr[],int n){
  for(int i=0;i<n;i++){
    cout << arr[i] << ' ';
  }
  cout << endl;
}

template <typename T>
void ShowArray(T * const arr[],int n){
  for(int i=0;i<n;i++){
    cout << *arr[i] << ' ';
  }
  cout << endl;
}

template <typename T>
T SumArray(T const arr[],int n){
  T suma = 0;
  for(int i=0;i<n;i++){
    suma += arr[i];
  }
  return suma;
}

template <typename T>
T SumArray(T * const arr[], int n){
  T suma = 0;
  for(int i=0;i<n;i++){
    suma += *arr[i];
  }
  return suma;
}


