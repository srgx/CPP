#include <iostream>
#include <cstring>
#include "golf.h"


void setgolf(golf & g, const char * name, int hc){
  strcpy(g.fullname,name);
  handicap(g,hc);
}

int setgolf(golf & g){
  using std::cout; using std::cin;
  cout << "Podaj imię: "; char temp [Len];
  cin.get(temp,Len); if(!cin) { return 0; }
  char next; cin.get(next); while(next!='\n'){ cin.get(next); }
  strcpy(g.fullname,temp);
  cout << "Podaj handicap: "; int hc;
  while(!(cin >> hc)){
    cin.clear();
    while(cin.get()!='\n'){ continue; }
    cout << "Podaj liczbę: ";
  }
  while(cin.get()!='\n'){ continue; }
  setgolf(g,temp,hc);
  return 1;
}

void handicap(golf & g,int hc){ g.handicap = hc; }

void showgolf(const golf & g){
  using std::cout; using std::endl;
  cout << "Imię: " << g.fullname << endl;
  cout << "Handicap: " << g.handicap << endl;
}
