#include <iostream>

using namespace std;

double * fill_array(double * ar, double * limit);
void show_array(const double * ar, double * limit);
void revalue(double r,double * ar, double * limit);

int main(){
  const int Max = 5;
  double properties[Max];
  double * limit = &properties[Max];
  limit = fill_array(properties,limit);
  show_array(properties,limit);
  if(limit!=&properties[0]){
    cout << "Podaj czynnik zmiany wartości: "; double factor;
    while(!(cin >> factor)){
      cin.clear();
      while(cin.get()!='\n')
        continue;
      cout << "Niepoprawne dane. Podaj liczbę: ";
    }
    revalue(factor,properties,limit);
    show_array(properties,limit);
  }
  cout << "Gotowe\n";
}

double * fill_array(double * pt, double * limit){
  double temp; int i;
  for(i=0;pt!=limit;i++){
    cout << "Podaj wartość nr " << i+1 << ": "; cin >> temp;
    if(!cin){
      cin.clear();
      while(cin.get()!='\n')
        continue;
      cout << "Błędne dane. Wprowadzanie danych przerwane.\n";
      break;
    }else if(temp < 0){ break; }
    *pt = temp; pt++;
  }
  return pt;
}

void show_array(const double * pt, double * limit){
  for(int i=0;pt!=limit;i++){
    cout << "Nieruchomość nr " << i+1 << ": ";
    cout << *pt << endl; pt++;
  }
}

void revalue(double r, double * pt, double * limit){
  for(int i=0;pt!=limit;i++){
    *pt *= r; pt++;
  }
}
