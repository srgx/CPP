#include <iostream>
#include <cstring>

struct chaff{
  char dross[20];
  int slag;
};

const int BUF = 512;
const int ArSize = 2;
int main(){
  using std::cout; using std::endl;
  
  // BUFOR STATYCZNY
  char buffer[BUF];
  chaff * pt = new (buffer) chaff[ArSize];
  
  strcpy(pt[0].dross,"czesc");
  pt[0].slag = 12;
  strcpy(pt[1].dross,"milego dnia");
  pt[1].slag = 7;
  
  cout << "---\n";
  for(int i=0;i<ArSize;i++){
    cout << "Dross: " << pt[i].dross << endl;
    cout << "Slag: " << pt[i].slag << endl;
  }
  
  // BUFOR DYNAMICZNY
  char * bfr = new char[BUF];
  chaff * pr = new (bfr) chaff[ArSize];
  
  strcpy(pr[0].dross,"rozne");
  pr[0].slag = 22;
  strcpy(pr[1].dross,"sposoby");
  pr[1].slag = 15;
  
  
  cout << "---\n";
  for(int i=0;i<ArSize;i++){
    cout << "Dross: " << pr[i].dross << endl;
    cout << "Slag: " << pr[i].slag << endl;
  }
  
  cout << "---\n";
  cout << "Adres bufora: " << (void *)buffer << endl;
  cout << "Adres struktury: " << pt << endl;
  cout << "---\n";
  cout << "Adres bufora dynamicznego: " << (void *)bfr << endl;
  cout << "Adres struktury w buforze: " << pr << endl;
  cout << "---\n";
  cout << "Koniec\n";
  
  delete [] bfr;
}
