#include <iostream>

int main(){
  using namespace std;
  cout << "Podaj liczbę wierszy: ";
  int wiersze; cin >> wiersze;
  for(int i=0;i<wiersze;i++){
    for(int j=i;j<wiersze-1;j++) { cout << '.'; }
    for(int j=0;j<i+1;j++) { cout << '*'; }
    cout << endl;
  }
}
