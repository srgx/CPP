#include <iostream>
#include "golf.h"

int main(){
  using std::cout; using std::endl;
  const int ILE = 3; golf wyniki[ILE];
  cout << "Podawaj wyniki.\n"; int wprowadzono = 0;
  for(int i=0;i<ILE;i++){
    cout << "Podaj dane zawodnika " << i+1 << ": " << endl;
    if(setgolf(wyniki[i])) { wprowadzono++; } else { break; }
  }
  
  cout << "**WPROWADZONE WYNIKI**\n";
  if(wprowadzono==0){
    cout << "Brak Wyników\n";
  }else{
    for(int i=0;i<wprowadzono;i++){
      showgolf(wyniki[i]);
    }
  }
  return 0;
}
