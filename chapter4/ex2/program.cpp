#include <iostream>

int main(){
  using namespace std;
  cout << "Podaj swoje imię: ";
  string name; getline(cin,name);
  cout << "Podaj swój ulubiony deser: ";
  string dessert; getline(cin,dessert);
  cout << "Mam dla Ciebie " << dessert << ", " << name << endl;
}
