#include <iostream>

using namespace std;

void naWielkie(string & napis);

int main(){
  cout << "Podawaj łańcuchy: ";
  string napis; getline(cin,napis);
  while(napis!="q"){
    naWielkie(napis); cout << napis << endl;
    cout << "Następny łańcuch(q aby zakończyć): "; getline(cin,napis);
  }
  cout << "Do widzenia.\n";
}

// bez polskich znaków
void naWielkie(string & napis){
  int rozmiar = napis.length();
  for(int i=0;i<rozmiar;i++){ napis[i] = toupper(napis[i]); }
}
