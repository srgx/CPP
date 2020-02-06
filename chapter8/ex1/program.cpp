#include <iostream>

using namespace std;

void pokazLancuch(const char * lancuch,int p = 0);

int main(){
  cout << "Pierwsze wywołanie bez parametru:\n";
  pokazLancuch("Miło mi cię widzieć\n");
  cout << "Drugie wywołanie bez parametru:\n";
  pokazLancuch("Co słychać?\n");
  cout << "Trzecie wywołanie z parametrem:\n";
  pokazLancuch("Jak się masz?\n",5);
}

void pokazLancuch(const char * lancuch, int p){
  static int count = 0; count++;
  if(p==0){
    cout << lancuch;
  } else{
    for(int i=0;i<count;i++){
      cout << lancuch;
    }
  }
}
