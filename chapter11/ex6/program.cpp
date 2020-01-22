#include <iostream>
#include "stonewt.h"

int main(){
  const int ArSize = 6;
  using std::cout; using std::cin; using std::endl;


  Stonewt stones[ArSize] = {
    {12,4},
    {15,7},
    {2,8}
  };

  Stonewt limit(11,0);

  for(int i=3;i<ArSize;i++){
    cout << "Kamieni i funtów: ";
    int kamienie; double funty;
    cin >> kamienie >> funty;
    stones[i] = Stonewt(kamienie,funty);
  }

  cout << "Tablica:\n";

  int min, max, count;
  min = max = count = 0;
  for(int i=0;i<ArSize;i++){
    cout << i << ": " << stones[i] << endl;
    if(stones[i]>stones[max]){ max = i; }
    if(stones[i]<stones[min]){ min = i; }
    if(stones[i]>limit){ count++; }
  }

  cout << "Min pod indeksem " << min << " = "
       << stones[min];
  stones[min].SetMode(Stonewt::FUNZ);
  cout << "(" << stones[min] << ")\n";

  cout << "Max pod indeksem " << max << " = "
       << stones[max];
  stones[max].SetMode(Stonewt::FUNZ);
  cout << "(" << stones[max] << ")\n";

  cout << count << " elementów większych niż "
       << limit << endl;


  cout << "Koniec\n";
}
