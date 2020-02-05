#include <iostream>
#include <cstring>

int main(){
  using namespace std;
  cout << "Podawaj słowa (kiedy skończysz napisz \"gotowe\")\n";
  char slowo [40]; cin >> slowo; int ile{0};
  while(strcmp(slowo,"gotowe")) { ile++; cin >> slowo; }
  cout << "Podano " << ile << " słów.\n";
}
