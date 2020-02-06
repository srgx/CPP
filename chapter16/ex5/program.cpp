#include <iostream>
#include <algorithm>

template <class T>
int reduce(T ar[], int n);

template <class T>
void show(T a);

int main(){

  using std::cout; using std::endl;
  const int SIZE = 7;
  long arr[SIZE] = {99,15,7,1,15,1,15};

  cout << "Oryginalna tablica: ";
  for(int i=0;i<SIZE;i++){ show(arr[i]); } cout << endl;

  cout << "Posortowana tablica bez duplikatów: ";
  int newSize = reduce(arr,SIZE);
  for(int i=0;i<newSize;i++){ show(arr[i]); } cout << endl;

  std::string stringArr[SIZE] = {
    "zebra", "aligator", "kanarek",
    "lis", "aligator", "lis", "aligator"
  };

  cout << "Oryginalna tablica: ";
  for(int i=0;i<SIZE;i++){ show(stringArr[i]); } cout << endl;

  cout << "Posortowana tablica bez duplikatów: ";
  newSize = reduce(stringArr,SIZE);
  for(int i=0;i<newSize;i++){ show(stringArr[i]); }

  cout << "\nKoniec.\n";
}

template <class T>
int reduce(T ar[], int n){
  std::sort(ar,ar+n); T * end = std::unique(ar,ar+n);
  return end - ar;
}

template <class T>
void show(T a){ std::cout << a << " "; }
