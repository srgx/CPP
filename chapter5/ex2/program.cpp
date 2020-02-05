#include <iostream>
#include <array>

int main(){
  using namespace std;
  const int ArSize = 101; array<long double,ArSize> factorials;
  factorials.at(0) = factorials.at(1) = 1;
  for(int i=2;i<ArSize;i++)
    factorials.at(i) = i * factorials.at(i-1);
  cout << "100! = " << factorials.at(100) << endl;
}
