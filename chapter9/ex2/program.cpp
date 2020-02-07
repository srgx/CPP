#include <iostream>

const int ArSize = 10;

void strcount(std::string & str);

int main(){
  using namespace std;
  string input;
  
  cout << "Wprowadź wiersz:\n";
  getline(cin,input);
  while(input!=""){
    strcount(input);
    cout << "Wprowadź następny wiersz (wiersz pusty kończy wprowadzanie):\n";
    getline(cin,input);
  }
  cout << "Koniec\n";
}

void strcount(std::string & str){
  using namespace std;
  static int total = 0;
  cout << "\"" << str << "\"" << " zawiera ";
  int count = str.length();
  total += count;
  cout << count << " znaków.\n";
  cout << "Łącznie " << total << " znaków\n";
}

