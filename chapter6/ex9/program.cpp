#include <iostream>
#include <fstream>

using namespace std;

struct donator{
  string nazwisko;
  double kwota;
};

int main(){
  const int GRANICA = 10000;
  const int SIZE = 60;
  const char filename[SIZE] = "ex6-9.txt";
  ifstream inFile; inFile.open(filename);

  if(!inFile.is_open()){
    cout << "Nie udało się otworzyć pliku.\n";
    exit(EXIT_FAILURE);
  }

  int ile; inFile >> ile; inFile.get();
  donator * pt = new donator[ile];

  for(int i = 0;i<ile;i++){
    getline(inFile,pt[i].nazwisko);
    inFile >> pt[i].kwota; inFile.get();
  }

  inFile.close();

  cout << "***NASI WSPANIALI SPONSORZY***\n";
  bool empty = true;
  for(int i = 0;i<ile;i++){
    if(pt[i].kwota>=GRANICA){
      cout << pt[i].nazwisko << endl; empty = false;
    }
  }

  if(empty)
    cout << "brak\n";

  empty = true;
  cout << "**NASI SPONSORZY**\n";
  for(int i = 0;i<ile;i++){
    if(pt[i].kwota<GRANICA){
      cout << pt[i].nazwisko << endl; empty = false;
    }
  }

  if(empty)
    cout << "brak\n";

  delete [] pt;
}
