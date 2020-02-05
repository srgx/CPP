#include <iostream>

int main(){
  using namespace std;
  cout << "Podawaj słowa (kiedy skończysz napisz \"gotowe\")\n";
  string slowo; cin >> slowo; int ile{0};
  while("gotowe"!=slowo) { ile++; cin >> slowo; }
  cout << "Podano " << ile << " słów.\n";
}
