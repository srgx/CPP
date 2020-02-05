#include <iostream>

int main(){
  using namespace std;
  cout << "Podawaj słowa(q kończy):\n"; string slowo; cin >> slowo;
  int spol, samo, inne; spol = samo = inne;
  while(slowo.length()!=1||slowo[0]!='q'){
    char l = tolower(slowo[0]);
    if(isalpha(l)){
      if(l=='a'||l=='e'||l=='o'||l=='u'||l=='i'||l=='y') { samo++; }
      else { spol++; }
    }else { inne++; }
    cin >> slowo;
  }

  cout << "Spółgłoski: " << spol << endl;
  cout << "Samogłoski: " << samo << endl;
  cout << "Inne: " << inne << endl;
}
