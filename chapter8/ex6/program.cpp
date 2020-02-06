#include <iostream>
#include <cstring>

template <typename T>
T maxn(T const ar[],int ile);

template <> const char * maxn(const char * const ar[], int ile);


int main(){
  using namespace std;
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
