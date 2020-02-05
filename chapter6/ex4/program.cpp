#include <iostream>


const int STRSIZE = 40;

struct zpdw{
  char imie[STRSIZE];
  char stanowisko[STRSIZE];
  char pseudonim[STRSIZE];
  int preferencje;
};


int main(){
  using namespace std;

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
