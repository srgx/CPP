#include <iostream>

using namespace std;

const int Seasons = 4;
const char * Snames[Seasons] = {
  "Wiosna","Lato","Jesień","Zima"
};

struct tablica{
  double wydatki[Seasons];
};


void fill(double pa[]);
void show(const double pa[]);
void fill2(tablica * pa);
void show2(const tablica * da);


int main(){
  double expenses[Seasons];
  fill(expenses);
  show(expenses);

  tablica tab;
  fill2(&tab);
  show2(&tab);
}

void fill(double pa[]){
  for(int i=0;i<Seasons;i++){
    cout << "Podaj wyniki za okres " << Snames[i] << ": ";
    cin >> pa[i];
  }
}


void show(const double da[]){
  double total = 0.0; cout << "WYDATKI\n";
  for(int i=0;i<Seasons;i++){
    cout << Snames[i] << ": " << da[i] << " zł\n"; total += da[i];
  }
  cout << "Łącznie wydatki roczne: " << total << " zł\n";
}


void fill2(tablica * pa){
  for(int i=0;i<Seasons;i++){
    cout << "Podaj wyniki za okres " << Snames[i] << ": ";
    cin >> pa->wydatki[i];
  }
}

void show2(const tablica * da){
  double total = 0.0; cout << "WYDATKI\n";
  for(int i=0;i<Seasons;i++){
    cout << Snames[i] << ": " << da->wydatki[i] << " zł\n"; total += da->wydatki[i];
  }
  cout << "Łącznie wydatki roczne: " << total << " zł\n";
}
