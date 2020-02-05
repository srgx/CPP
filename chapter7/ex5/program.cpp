#include <iostream>

long double silnia(int x);

int main(){
  using namespace std;
  cout << "Podaj wartość dla której ma być obliczona silnia: ";
  int wartosc;

  while(cin >> wartosc && wartosc >= 0){
    cout << wartosc << "!: "
         << silnia(wartosc) << endl;
    cout << "Podaj kolejną liczbę(q aby zakończyć): ";
  }
  cout << "Do widzenia.\n";
}

long double silnia(int x){
  if(x==0){
    return 1;
  }else{
    return x * silnia(x-1);
  }
}
