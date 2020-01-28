#include <iostream>
#include "wine.h"

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
: label(l), years(y), data(ArrayInt(y),ArrayInt(y)){
  for(int i=0;i<y;i++){
    data.first()[i] = yr[i];
    data.second()[i] = bot[i];
  }
}

Wine::Wine(const char * l, int y)
: label(l), years(y), data(ArrayInt(y),ArrayInt(y)){
}

void Wine::GetBottles(){
  using std::cout; using std::cin;
  cout << "Podaj dane o winie " << label
       << " dla " << years << " roczników:\n";
  for(int i=0;i<years;i++){
    cout << "Podaj rocznik: ";
    cin >> data.first()[i];
    cout << "Podaj liczbę butelek: ";
    cin >> data.second()[i];
  }
}

void Wine::Show()const{
  using std::cout; using std::endl;
  cout << "Wino: " << label << endl;
  cout << "\tRocznik\tButelki" << endl;
  for(int i=0;i<years;i++){
    cout << "\t" << data.first()[i] << "\t"
         << data.second()[i] << endl;
  }
}

const std::string & Wine::Label() const{
  return label;
}

int Wine::sum()const{
  int sum = 0;
  for(int i=0;i<years;i++){
    sum += data.second()[i];
  }
  return sum;
}
