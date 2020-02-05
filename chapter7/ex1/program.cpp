#include <iostream>

float sredniaHarmoniczna(float x,float y);

int main(){
  using namespace std;
  int pierwsza,druga;
  while(true){
    cout << "Podaj dwie liczby(koniec jeśli jedna z liczb to 0): ";
    while(!(cin >> pierwsza >> druga)){
      cin.clear();
      while(cin.get()!='\n'){ continue; }
      cout << "Podaj prawidłowe liczby: ";
    }
    if(pierwsza==0||druga==0) { break; }
    cout << "Średnia harmoniczna: "
         << sredniaHarmoniczna(pierwsza,druga) << endl;
  }
  cout << "Gotowe.\n";
}

float sredniaHarmoniczna(float x,float y){
  return 2.0*x*y/(x+y);
}
