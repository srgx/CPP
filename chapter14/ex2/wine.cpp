#include <iostream>
#include "wine.h"

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
: std::string(l), years(y), PairArray(ArrayInt(y),ArrayInt(y)){
  for(int i=0;i<years;i++){
    PairArray::first()[i] = yr[i];
    PairArray::second()[i] = bot[i];
  }
}

Wine::Wine(const char * l, int y)
: std::string(l), years(y), PairArray(ArrayInt(y),ArrayInt(y)){
}

void Wine::GetBottles(){
  using std::cout; using std::cin;
  cout << "Podaj dane o winie " << (const std::string &)*this
       << " dla " << years << " roczników:\n";
  for(int i=0;i<years;i++){
    cout << "Podaj rocznik: ";
    cin >> PairArray::first()[i];
    cout << "Podaj liczbę butelek: ";
    cin >> PairArray::second()[i];
  }
}

void Wine::Show()const{
  using std::cout; using std::endl;
  cout << "Wino: " << (const std::string &)*this << endl;
  cout << "\tRocznik\tButelki" << endl;
  for(int i=0;i<years;i++){
    cout << "\t" << PairArray::first()[i] << "\t"
         << PairArray::second()[i] << endl;
  }
}

const std::string & Wine::Label() const{
  return (const std::string &)*this;
}

int Wine::sum()const{
  int sum = 0;
  for(int i=0;i<years;i++){
    sum += PairArray::second()[i];
  }
  return sum;
}
