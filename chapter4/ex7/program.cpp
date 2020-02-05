#include <iostream>

struct Pizza{
  char nazwa [30];
  float srednica;
  float waga;
};

int main(){
  using namespace std;
  const int ArSize = 30;
  Pizza pizza;
  cout << "Podaj nazwę firmy: "; cin.getline(pizza.nazwa,ArSize);
  cout << "Podaj średnicę pizzy: "; cin >> pizza.srednica;
  cout << "Podaj wagę pizzy: "; cin >> pizza.waga;
  cout << "Nazwa: " << pizza.nazwa << endl;
  cout << "Średnica: " << pizza.srednica << endl;
  cout << "Waga: " << pizza.waga << endl;
}
