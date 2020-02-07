#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using std::cout; using std::vector; using std::endl;

vector<int> Lotto(int numbers, int choices);

int main(){
  std::srand(std::time(0)); vector<int>vctr;

  cout << "Podaj liczbę pól i liczbę skreśleń: ";
  int numbers, choices;
  while(std::cin >> numbers >> choices){
    try{
      vctr = Lotto(numbers,choices);
    }
    catch(const char * str){
      cout << str << ". " << "Wyjście z programu.\n";
      return 1;
    }
    cout << "Wylosowane liczby: ";
    for(const auto & ve : vctr){ cout << ve << " "; } cout << endl;
    cout << "Podaj następną parę(q aby zakonczyc): ";
  }
  cout << "Koniec\n";
}

vector<int> Lotto(int numbers, int choices){
  if(choices>numbers){ throw "Niepoprawne argumenty funkcji Lotto"; }
  vector<int>ve;
  for(int i=1;i<=numbers;i++){ ve.push_back(i); }
  std::random_shuffle(ve.begin(),ve.end());
  ve.resize(choices);
  return ve;
}
