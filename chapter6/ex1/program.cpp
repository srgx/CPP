#include <iostream>

int main(){
  using namespace std;
  char dane [100];
  cout << "Podawaj dane(@ kończy wprowadzanie):\n";
  char ch; cin.get(ch); int c=0;
  while(ch!='@'){
    if(isalpha(ch))
      ch = isupper(ch) ? tolower(ch) : toupper(ch);
    dane[c] = ch; c++;
    cin.get(ch);
  }
  cout << "Wprowadzone dane:\n";
  for(int i=0;i<c;i++){
    if(!isdigit(dane[i])) { cout << dane[i]; }
  }
}
