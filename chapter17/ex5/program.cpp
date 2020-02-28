#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>


int main(){
  using namespace std;

  const char * plikBolek = "bolek.dat";
  const char * plikLolek = "lolek.dat";
  const char * plikBolilol = "bolilol.dat";

  ifstream bolek(plikBolek);
  if(!bolek.is_open()){
    cerr << "Nie można otworzyć pliku " << plikBolek << " do odczytu.\n";
    exit(EXIT_FAILURE);
  }

  ifstream lolek(plikLolek);
  if(!lolek.is_open()){
    cerr << "Nie można otworzyć pliku " << plikLolek << " do odczytu.\n";
    exit(EXIT_FAILURE);
  }

  ofstream bolilol(plikBolilol);
  if(!bolilol.is_open()){
    cerr << "Nie można otworzyć pliku " << plikBolilol << " do zapisu.\n";
    exit(EXIT_FAILURE);
  }

  vector<string> przyjacieleBolka;
  vector<string> przyjacieleLolka;
  string temp;

  // odczytaj dane bolka
  while(getline(bolek,temp)){
    przyjacieleBolka.push_back(temp);
  }

  // odczytaj dane lolka
  while(getline(lolek,temp)){
    przyjacieleLolka.push_back(temp);
  }

  bolek.close(); lolek.close();

  sort(przyjacieleBolka.begin(),przyjacieleBolka.end());
  sort(przyjacieleLolka.begin(),przyjacieleLolka.end());


  // wszyscy goście
  vector<string>goscie;
  set_union(przyjacieleBolka.begin(),przyjacieleBolka.end(),
            przyjacieleLolka.begin(),przyjacieleLolka.end(),
            back_inserter(goscie));

  // zapisz do pliku
  ostream_iterator<string,char> out(bolilol,"\n");
  copy(goscie.begin(),goscie.end(),out);

  bolilol.close();

  cout << "***Przyjaciele Bolka***\n";
  for(const auto & f : przyjacieleBolka){
    cout << f << endl;
  }

  cout << "***Przyjaciele Lolka***\n";
  for(const auto & f : przyjacieleLolka){
    cout << f << endl;
  }

}
