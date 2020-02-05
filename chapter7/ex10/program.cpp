#include <iostream>

double calculate(double x, double y, double (*fn)(double,double));
double add(double x,double y);
double someFun(double x, double y);
double otherFun(double x, double y);

int main(){
  using namespace std;
  const int arSize = 3;
  const char * descriptions[3] = {
    "x+y", "x*y+15", "x*2+y"
  };
  double (*pf[arSize])(double,double) = { add, someFun, otherFun };
  cout << "Wprowadź parę liczb: "; int a,b;
  while(cin >> a >> b){
    for(int i=0;i<arSize;i++){
      cout << "Funkcja " << i+1 << "(" << descriptions[i] << "): " << calculate(a,b,pf[i]) << endl;
    }
    while(cin.get()!='\n')
      continue;
    cout << "Podaj kolejną parę liczb(q aby zakończyć): ";
  }
  cout << "Do widzenia.\n";
}


double add(double x,double y){
  return x+y;
}

double someFun(double x, double y){
  return x*y+15;
}

double otherFun(double x, double y){
  return x*2+y;
}

double calculate(double x, double y, double (*fn)(double x, double y)){
  return fn(x,y);
}
