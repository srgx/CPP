#include <iostream>
#include <algorithm>
#include <set>


bool isPalindrome(const std::string & str);
char toLower(char ch);

int main(){
  using namespace std;

  cout << "Podaj ciąg znaków(pusty wiersz kończy wprowadzanie): ";
  string napis; getline(cin,napis);

  while(napis!=""){
    cout << "Ciąg \"" << napis << "\"";
    if(isPalindrome(napis)){
      cout << " jest palindromem.\n";
    }else{
      cout << " nie jest palindromem.\n";
    }
    cout << "Podaj następny ciąg: ";
    getline(cin,napis);
  }

  cout << "Koniec\n";
}

bool isPalindrome(const std::string & str){
  using std::string; string orig = str;
  orig.erase(std::remove_if(orig.begin(), orig.end(), isspace), orig.end());
  transform(orig.begin(),orig.end(),orig.begin(),toLower);
  string rv = orig;
  reverse(rv.begin(),rv.end());
  return (rv == orig);
}

char toLower(char ch){
  return tolower(ch);
}
