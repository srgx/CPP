#include <iostream>

template <typename T>
T max5(T const ar[]);

int main(){
  using namespace std;
  int tablicaInt[5] = {12,34,66,21,7};
  double tablicaDouble[5] = {7.2,14.5,9,88.8,1};
  cout << "Maksymalna wartość z tablicy int: ";
  cout << max5(tablicaInt) << endl;
  cout << "Maksymalna wartość z tablicy double: ";
  cout << max5(tablicaDouble) << endl;
}

template <typename T>
T max5(T const ar[]){
  const int ArSize = 5; T max = ar[0];
  for(int i=1;i<ArSize;i++){
    if(ar[i]>max) { max = ar[i]; }
  }
  return max;
}
