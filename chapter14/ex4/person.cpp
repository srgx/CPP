#include <iostream>
#include <cstdlib>
#include <ctime>
#include "person.h"

void Person::Set(){
  std::cout << "Podaj imię: ";
  getline(std::cin,fname);
  std::cout << "Podaj nazwisko: ";
  getline(std::cin,lname);
}

void Person::Show()const{
  std::cout << "Imię: " << fname << std::endl;
  std::cout << "Nazwisko: " << lname << std::endl;
}

Card::Card(int num,Suit st)
: number(num), suit(st) {
}

void Card::Show()const{
  using std::cout; using std::endl;
  cout << "Numer Karty: " << number << endl;
  cout << "Kolor: ";
  switch(suit){
    case 0: cout << "Hearts"; break;
    case 1: cout << "Clubs"; break;
    case 2: cout << "Spades"; break;
    case 3: cout << "Diamonds"; break;
  }
  cout << endl;
}

Gunslinger::Gunslinger(const char * first, const char * last, float t,int sc)
: Person(first,last), time(t), scores(sc){
}

void Gunslinger::Set(){
  Person::Set();
  std::cout << "Podaj czas wyciągnięcia rewolweru: ";
  std::cin >> time;
  std::cout << "Podaj liczbę nacieć na rewolwerze: ";
  std::cin >> scores;
}

float Gunslinger::Draw()const{
  return time;
}

void Gunslinger::Show()const{
  using std::cout; using std::endl;
  Person::Show();
  std::cout << "Czas wyciągania rewolweru: " << Draw() << std::endl;
  std::cout << "Liczba nacięć: "
            << scores << std::endl;
}

PokerPlayer::PokerPlayer(const char * first, const char * last)
: Person(first,last){
}

Card PokerPlayer::Draw()const{
  std::srand(std::time(0));
  int n = rand() % 52 + 1;
  int c = rand() % 4;
  return Card(n,(Card::Suit)c);
}

BadDude::BadDude(const char * first, const char * last,float t, float sc)
: Person(first,last), Gunslinger(first,last,t,sc), PokerPlayer(first,last){
}

float BadDude::GDraw()const{
  return Gunslinger::Draw();
}

Card BadDude::CDraw()const{
  return PokerPlayer::Draw();
}

void BadDude::Show()const{
  Gunslinger::Show();
}
