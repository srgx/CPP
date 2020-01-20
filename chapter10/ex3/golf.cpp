#include <iostream>
#include <cstring>
#include "golf.h"

golf::golf(){
  m_fullname[0] = '\n';
  m_handicap = 0;
}

golf::golf(const char * name, int hc){
  strcpy(m_fullname,name);
  handicap(hc);
}

int golf::set(){
  using std::cout; using std::cin;
  cout << "Podaj imię: "; char temp [Len];
  cin.get(temp,Len); if(!cin) { return 0; }
  char next; cin.get(next); while(next!='\n'){ cin.get(next); }
  cout << "Podaj handicap: "; int hc;
  while(!(cin >> hc)){
    cin.clear();
    while(cin.get()!='\n'){ continue; }
    cout << "Podaj liczbę: ";
  }
  while(cin.get()!='\n'){ continue; }
  *this = golf(temp,hc);
  return 1;
}

void golf::handicap(int hc){ m_handicap = hc; }

void golf::show()const{
  using std::cout; using std::endl;
  cout << "Imię: " << m_fullname << endl;
  cout << "Handicap: " << m_handicap << endl;
}
