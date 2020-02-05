#include <iostream>

using namespace std;

struct car{
  string marka;
  int rok;
};

int main(){
  cout << "Ile samochodów chcesz skatalogować: ";
  int ile; cin >> ile; cin.get();
  car * pt = new car[ile];
  for(int i=0;i<ile;i++){
    cout << "Samochód #" << i+1 << ":\n";
    cout << "Proszę podać markę: ";
    getline(cin,pt[i].marka);
    cout << "Rok produkcji: ";
    cin >> pt[i].rok; cin.get();
  }

  for(int i=0;i<ile;i++){
    cout << pt[i].rok << " " << pt[i].marka << endl;
  }

  delete [] pt;
}
