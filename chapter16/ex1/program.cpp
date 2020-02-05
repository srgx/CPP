#include <iostream>
#include <algorithm>


bool isPalindrome(const std::string & str);

int main(){
  using namespace std;
  cout << "Podaj ciąg znaków: ";
  string napis; getline(cin,napis);

  while(napis!=""){
    cout << "Ciąg \"" << napis << "\"";
    if(isPalindrome(napis)){
      cout << " jest palindromem.\n";
    }else{
      cout << " nie jest palindromem.\n";
    }
    cout << "Podaj następny ciąg(pusty wiersz kończy wprowadzanie):\n";
    getline(cin,napis);
  }

  cout << "Koniec\n";
}

bool isPalindrome(const std::string & str){
  std::string rv = str;
  reverse(rv.begin(),rv.end());
  return (rv == str);
}
