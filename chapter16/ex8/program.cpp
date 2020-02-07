#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>

struct Person{
  std::string imie;
  std::set<std::string>przyjaciele;
};

void wprowadzImiona(Person & p);

int main(){
  using namespace std;

  Person bolek, lolek;
  bolek.imie = "Bolek"; lolek.imie = "Lolek";

  wprowadzImiona(bolek); wprowadzImiona(lolek);

  cout << "***Przyjaciele Bolka***\n";
  for(const auto & p : bolek.przyjaciele){ cout << p << endl; }

  cout << "***Przyjaciele Lolka***\n";
  for(const auto & p : lolek.przyjaciele){ cout << p << endl; }

  set<string>goscie;

  set_union(bolek.przyjaciele.begin(),bolek.przyjaciele.end(),
            lolek.przyjaciele.begin(),lolek.przyjaciele.end(),
            insert_iterator<set<string>>(goscie,goscie.begin()));


  cout << "***Urodzinowi Goście***\n";
  ostream_iterator<string,char> out(cout,"\n");
  copy(goscie.begin(),goscie.end(),out);

  cout << "--------------\n";
}

void wprowadzImiona(Person & p){
  using std::cout; using std::endl; using std::cin;
  cout << "Wpisuj imiona przyjaciół użytkownika " << p.imie << ". ";
  cout << "Pusty wiersz kończy wprowadzanie:\n";
  cout << "Podaj imię: "; std::string imie; getline(cin,imie);
  while(imie!=""){
    p.przyjaciele.insert(imie); cout << "Następne imię: "; getline(cin,imie);
  }
}
