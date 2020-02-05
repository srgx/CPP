#include <iostream>

using namespace std;

struct donator{
  string nazwisko;
  double kwota;
};

int main(){
  const int GRANICA = 10000;

  cout << "Podaj liczbę wpłacających: "; int ile; cin >> ile; cin.get();
  donator * pt = new donator[ile];

  for(int i = 0;i<ile;i++){
    cout << "Donator " << i+1 << endl;
    cout << "Nazwisko: "; getline(cin,pt[i].nazwisko);
    cout << "Kwota: "; cin >> pt[i].kwota; cin.get();
  }

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
