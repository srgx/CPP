#include <iostream>
#include <cstring>


struct Batonik{
  char marka [30];
  float waga;
  int kalorie;
};

int main(){
  using namespace std;
  Batonik bats [3];
  strcpy(bats[0].marka,"Snickers"); strcpy(bats[1].marka,"Mars"); strcpy(bats[2].marka,"Lion");
  bats[0].waga = 12.2; bats[1].waga = 6.8; bats[2].waga = 9.5;
  bats[0].kalorie = 88; bats[1].kalorie = 62; bats[2].kalorie = 33;

  cout << bats[0].marka << ", " << bats[0].waga << ", " << bats[0].kalorie << endl;
  cout << bats[1].marka << ", " << bats[1].waga << ", " << bats[1].kalorie << endl;
  cout << bats[2].marka << ", " << bats[2].waga << ", " << bats[2].kalorie << endl;
}
