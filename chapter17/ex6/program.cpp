#include <iostream>
#include <fstream>
#include "emp.h"

int main(){
  using namespace std;
  const int MAX = 2;
  abstr_emp * arr[MAX];

  const char * file = "data.txt";
  ifstream fin; fin.open(file);

  if(fin.is_open()){
    // pokaż zawartość pliku jeśli istnieje
    fin.close(); // zamknij plik
  }


  // wczytaj dane używając tablicy wskaźników
  char ch;
  for(int i=0;i<MAX;i++){
    // e m f h
    cout << "Jakiego użytkownika dodać?\n";
    cout << "(e)mployee, (m)anager, (f)ink, (h)ighfink: ";
    cin >> ch;
    switch(ch){
      case 'e':
        arr[i] = new employee;
        break;
      case 'm':
        arr[i] = new manager;
        break;
      case 'f':
        arr[i] = new fink;
        break;
      case 'h':
        arr[i] = new highfink;
        break;
    }
    cin.get();
    arr[i]->SetAll();
  }

  ofstream fout(file);

  for(int i=0;i<MAX;i++){
    // zapisz zawartość tablicy do pliku
    arr[i]->writeall(fout);
  }

  fout.close();


  // odczytaj i pokaż wszystkie dane z pliku

}
