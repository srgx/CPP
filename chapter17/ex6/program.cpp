#include <iostream>
#include <fstream>
#include <vector>
#include "emp.h"

using namespace std;


const char * file = "data.txt";

void ShowFile(ifstream & fin);

int main(){

  ifstream fin; fin.open(file);
  if(fin.is_open()){
    cout << "**Dane Z Pliku**\n\n";
    ShowFile(fin); fin.close();
  }

  const int MAX = 2; abstr_emp * arr[MAX];

  // wczytaj dane  od użytkownika do tablicy wskaźników
  char ch;
  for(int i=0;i<MAX;i++){
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

  // dodaj zawartość tablicy na końcu pliku
  ofstream fout(file, ios_base::out | ios_base::app);
  for(int i=0;i<MAX;i++){ arr[i]->WriteAll(fout); delete arr[i]; }
  fout.close();


  // odczytaj i pokaż wszystkie dane z pliku
  fin.open(file);
  if(fin.is_open()){
    cout << "**Dane Z Pliku**\n\n";
    ShowFile(fin); fin.close();
  }

  return 0;
}


void ShowFile(ifstream & fin){
  vector<abstr_emp*>pts;
  int classType; abstr_emp * pt;
  char ch;
  while((fin>>classType).get(ch)){
    switch(classType){
      case Employee :
        pt = new employee; break;
      case Manager :
        pt = new manager; break;
      case Fink :
        pt = new fink; break;
      case Highfink :
        pt = new highfink; break;
    }
    pt->GetAll(fin); pts.push_back(pt);
  }

  for(const auto & pt : pts){ pt->ShowAll(); delete pt; std::cout << "\n"; }
}
