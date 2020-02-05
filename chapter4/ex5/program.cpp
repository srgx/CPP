#include <iostream>

struct Batonik{
  char marka [30];
  float waga;
  int kalorie;
};

int main(){
  using namespace std;
  Batonik snack = {"Mocha Munch",2.3,350};
  cout << "Marka: " << snack.marka << endl;
  cout << "Waga: " << snack.waga << endl;
  cout << "Kalorie: " << snack.kalorie << endl;
}
