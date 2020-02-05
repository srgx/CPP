#include <iostream>

int main(){
  using namespace std;
  cout << "Ile zarabiasz('q' aby zakończyć): "; float ile;
  while(cin>>ile&&ile>0){
    cout << "Podatek: ";
      if(ile<=5000){
        cout << 0;
      }else if(ile<=15000){
        cout << 5000*0 + (ile-5000)*0.1;
      }else if(ile<=35000){
        cout << 5000*0 + 10000*0.1 + (ile-15000)*0.15;
      }else{
        cout << 5000*0 + 10000*0.1 + 20000*0.15 + (ile-35000)*0.2;
      }
      cout << endl;
      cout << "Ile zarabiasz('q' aby zakończyć): ";
  }
  cout << "Gotowe\n";
}
