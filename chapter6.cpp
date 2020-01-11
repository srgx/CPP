#include <iostream>
#include <cctype>
#include <array>

using namespace std;

void exercise1(); void exercise2(); void exercise3(); void exercise4();
void exercise5(); void exercise6(); void exercise7(); void exercise8();
void showmenu();

const int STRSIZE = 40;

struct zpdw{
  char imie[STRSIZE];
  char stanowisko[STRSIZE];
  char pseudonim[STRSIZE];
  int preferencje;
};

struct donator{
  string nazwisko;
  double kwota;
};

int main(){
  exercise8();
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
  const int MAX_DATKI = 10;
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
    cout << "Proszę podać literę r p d lub g: "; cin.get(ch);
    while(cin.get()!='\n')
      continue;
  }while(ch!='r'&&ch!='p'&&ch!='d'&&ch!='g');
  
  switch(ch){
    case 'r': cout << "Roślinożercy jedzą rośliny."; break;
    case 'p': cout << "Chopin wielkim pianistą był."; break;
    case 'd': cout << "Drzewo to orzech."; break;
    case 'g': cout << "Gram w Tomb Raider."; break;
  }
  
  cout << "\nGotowe.\n";
}

void exercise4(){
  zpdw czlonkowie [5] = {
    {"Jan","Prezydent","Tiger",0},
    {"Joanna","Sekretarka","Osa",1},
    {"Adrian","Zastępca","Lis",2},
    {"Magdalena","Tester","Hiena",1},
    {"Justyna","Skarbnik","Czarna Wdowa",2},
  };
  cout << "Zakon Programistów Dobrej Woli\n";
  cout << "a. lista wg imion\tb. lista wg stanowisk\n";
  cout << "c. lista wg pseudonimów\td. lista wg preferencji\n";
  cout << "q. koniec\n";
  
  char ch;
  while(true){
    do{
      cout << "Wybierz jedną z opcji: "; cin.get(ch);
      while(cin.get()!='\n') { continue; }
    }while(ch!='a'&&ch!='b'&&ch!='c'&&ch!='d'&&ch!='q');
    
    if(ch=='q')
      break;
    else
      switch(ch){
        case 'a':
          for(zpdw x : czlonkowie) { cout << x.imie << endl; } break;
        case 'b':
          for(zpdw x : czlonkowie) { cout << x.stanowisko << endl; } break;
        case 'c':
          for(zpdw x : czlonkowie) { cout << x.pseudonim << endl; } break;
        case 'd':
          for(zpdw x : czlonkowie)
            switch(x.preferencje){
              case 0: cout << x.imie << endl; break;
              case 1: cout << x.stanowisko << endl; break;
              case 2: cout << x.pseudonim << endl; break;
            } // end switch
          break;
      } // end switch
  } // end while
  cout << "Do zobaczenia!\n";
}

void exercise5(){
  cout << "Ile zarabiasz('q' aby zakończyć): "; float ile;
  while(cin>>ile&&ile>0){
    cout << "Podatek: ";
      if(ile<=5000){
        cout << 0;
      }else if(ile<=15000){
        cout << 5000*0 + (ile-5000)*0.1;
      }else if(ile<=35000){
        cout << 5000*0 + 10000*0.1 + (ile-15000)*0.15;
      }else{
        cout << 5000*0 + 10000*0.1 + 20000*0.15 + (ile-35000)*0.2;
      }
      cout << endl;
      cout << "Ile zarabiasz('q' aby zakończyć): ";
  }
  cout << "Gotowe\n";
}

void exercise6(){
  const int GRANICA = 10000;
  cout << "Podaj liczbę wpłacających: "; int ile; cin >> ile; cin.get();
  donator * pt = new donator[ile];
  
  for(int i = 0;i<ile;i++){
    cout << "Donator " << i+1 << endl;
    cout << "Nazwisko: "; getline(cin,pt[i].nazwisko);
    cout << "Kwota: "; cin >> pt[i].kwota; cin.get();
  }
  
  cout << "***NASI WSPANIALI SPONSORZY***\n";
  bool empty = true;
  for(int i = 0;i<ile;i++){
    if(pt[i].kwota>=GRANICA){
      cout << pt[i].nazwisko << endl; empty = false;
    }
  }
  
  if(empty)
    cout << "brak\n";
  
  empty = true;
  cout << "**NASI SPONSORZY**\n";
  for(int i = 0;i<ile;i++){
    if(pt[i].kwota<GRANICA){
      cout << pt[i].nazwisko << endl; empty = false;
    }
  }
  
  if(empty)
    cout << "brak\n";
  
  delete [] pt;
}

void exercise7(){
  cout << "Podawaj słowa(q kończy):\n"; string slowo; cin >> slowo;
  int spol, samo, inne; spol = samo = inne;
  while(slowo.length()!=1||slowo[0]!='q'){
    char l = tolower(slowo[0]);
    if(isalpha(l)){
      if(l=='a'||l=='e'||l=='o'||l=='u'||l=='i'||l=='y') { samo++; }
      else { spol++; }
    }else { inne++; }
    cin >> slowo;
  }
  
  cout << "Spółgłoski: " << spol << endl;
  cout << "Samogłoski: " << samo << endl;
  cout << "Inne: " << inne << endl;
}

void exercise8(){
  // ...
  cout << "Plik tekstowy.\n";
}

void showmenu(){
  cout << "r) roślinożerca\tp) pianista\n";
  cout << "d) drzewo\tg) gra\n";
}


