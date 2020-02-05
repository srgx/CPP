#include <iostream>

int main(){
  using namespace std;
  int cleo, dafne; dafne = cleo = 100; int rok = 1;
  while(cleo<=dafne){
    dafne += 0.1 * 100;
    cleo += (0.05 * cleo);
    cout << "Po " << rok << " latach: " << endl;
    cout << "Dafne: " << dafne << endl;
    cout << "Cleo: " << cleo << endl;
    rok++;
  }
}
