#include <iostream>
#include <algorithm>

int reduce(long ar[], int n);

int main(){
  using std::cout; using std::endl;
  const int SIZE = 7;
  long arr[SIZE] = {99,15,7,1,15,1,15};

  cout << "Oryginalna tablica: ";
  for(int i=0;i<SIZE;i++){
    cout << arr[i] << " ";
  }
  cout << endl;

  int newSize = reduce(arr,SIZE);

  cout << "Posortowana tablica bez duplikatów: ";
  for(int i=0;i<newSize;i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  cout << "Koniec.\n";
}

int reduce(long ar[], int n){
  std::sort(ar,ar+n); long * end = std::unique(ar,ar+n);
  return end - ar;
}
