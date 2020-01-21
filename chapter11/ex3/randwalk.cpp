#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.h"

int main(){
  using namespace std;
  using VECTOR::Vector;
  srand(time(0));
  double direction;
  Vector step;
  Vector result(0.0,0.0);
  unsigned long steps = 0;
  double target;
  double dstep;
  int tests;
  cout << "Podaj dystans do przejścia(k, aby zakończyć): ";
  while(cin >> target){
    cout << "Podaj długość kroku: ";
    if(!(cin>>dstep)){ break; }

    cout << "Podaj ilość prób: ";
    if(!(cin>>tests)){ break; }
    unsigned long * pt = new unsigned long[tests];


    for(int i=0;i<tests;i++){
      while(result.magval()<target){
        direction = rand()%360;
        step.reset(dstep,direction,Vector::POL);
        result = result + step;
        steps++;
      }
      pt[i]=steps;
      steps = 0;
      result.reset(0.0,0.0);
    }

    unsigned long min, max, sum;
    min = max = pt[0]; sum = 0;
    for(int i=0;i<tests;i++){
      sum+=pt[i];
      if(pt[i]>max){ max = pt[i]; }
      if(pt[i]<min){ min = pt[i]; }
    }
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    cout << "Avg: " << sum/tests << endl;

    delete [] pt;

    cout << "Podaj dystans do przejścia(k, aby zakończyć): ";
  }
  cout << "Koniec!\n";
  cin.clear();
  while(cin.get()!='\n'){ continue; }
}
