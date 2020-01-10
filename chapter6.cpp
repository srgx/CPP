#include <iostream>
#include <cctype>
#include <array>

using namespace std;

void exercise1(); void exercise2(); void exercise3(); void exercise4();


void showmenu();

int main(){
  exercise3();
}

void exercise1(){
  char dane [100];
  cout << "Podawaj dane(@ kończy wprowadzanie):\n";
  char ch; cin.get(ch); int c=0;
  while(ch!='@'){
    if(isalpha(ch))
      ch = isupper(ch) ? tolower(ch) : toupper(ch);
    dane[c] = ch; c++;
    cin.get(ch);
  }
  cout << "Wprowadzone dane:\n";
  for(int i=0;i<c;i++)
    if(!isdigit(dane[i])) { cout << dane[i]; }
}

void exercise2(){
  const int MAX_DATKI = 5;
  array<double,MAX_DATKI>datki;
  cout << "Podawaj wartości maksymalnie 10 datków('q' kończy wprowadzanie):\n";
  cout << "Datek 1: "; double datek; int index = 0;
  while(index < MAX_DATKI && cin >> datki.at(index)){
    if(++index<MAX_DATKI)
      cout << "Datek " << index+1 << ": "; 
  }
  cout << "Otrzymano " << index << " datków.\n";
  double suma = 0;
  for(double x : datki)
    suma += x;
  cout << "Suma datków: " << suma << endl;
  double srednia = suma / index;
  cout << "Średnia wysokość datku: " << srednia << endl;
  cout << "Datki powyżej średniej: ";
  for(double x : datki)
    if(x>srednia) { cout << x << " "; }
  cout << endl;
}

void exercise3(){
  showmenu(); char ch;
  
  do{
    cout << "Proszę podać literę r p d lub g: "; ch = cin.get(); cin.get();
  }while(ch!='r'&&ch!='p'&&ch!='d'&&ch!='g');
  
  switch(ch){
    case 'r': cout << "Roślinożercy jedzą rośliny."; break;
    case 'p': cout << "Chopin był wielkim pianistą."; break;
    case 'd': cout << "Drzewo to orzech."; break;
    case 'g': cout << "Gram w Tomb Raider."; break;
  }
  
  cout << "\nGotowe.\n";
}

void exercise4(){
  // ...
}

void showmenu(){
  cout << "r) roślinożerca\tp) pianista\n";
  cout << "d) drzewo\tg) gra\n";
}


