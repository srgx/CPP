#include <iostream>
using namespace std;
#include "string1.h"

int main(){

  String s1(" i ucze sie C++.");
  String s2 = "Podaj swoje imię: ";
  String s3;
  cout << s2;
  cin >> s3;
  s2 = "Mam na imie " + s3;
  cout << s2 << ".\n";
  s2 = s2 + s1;
  s2.stringup();
  cout << "Ciąg\n" << s2 << "\nzawiera " << s2.has('A') << " 'A'.\n";
  s1 = "czerwona";
  String rgb[3] = {String(s1), String("zielona"), String("niebieska")};
  cout << "Podaj nazwę barwy podstawowej: ";
  String ans;
  bool success = false;
  while(cin >> ans){
    ans.stringlow();
    for(int i=0;i<3;i++){
      if(ans==rgb[i]){
        cout << "Prawidłowo!\n";
        success = true;
        break;
      }
    }
    if(success){ break; } else { cout << "Spróbuj ponownie!\n"; }
  }
  cout << "Żegnam\n";

}
