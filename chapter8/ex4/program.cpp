#include <iostream>
#include <cstring>

using namespace std;

struct stringy{
  char * str;
  int ct;
};

void set(stringy & str,const char ar[]);
void show(const stringy & str,int ile = 1);
void show(const char ar[], int ile = 1);


int main(){
  stringy beany;
  char testing[] = "Rzeczywistość to już nie to, co kiedyś.";
  set(beany,testing);
  show(beany); cout << "--\n";
  show(beany,2); cout << "--\n";

  delete [] beany.str;

  testing[0] = 'D'; testing[1] = 'u';
  show(testing); cout << "--\n";
  show(testing,3); cout << "--\n";
  show("Gotowe!");
}

void set(stringy & str,const char ar[]){
  str.ct = strlen(ar); str.str = new char[str.ct+1];
  strcpy(str.str,ar);
}

void show(const stringy & str,int ile){
  for(int i=0;i<ile;i++){
    cout << str.str << endl;
  }
}

void show(const char ar[], int ile){
  for(int i=0;i<ile;i++){
    cout << ar << endl;
  }
}
