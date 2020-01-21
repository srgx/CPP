#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "vect.h"

int main(){
  using namespace std;
  using VECTOR::Vector;

  ofstream outFile;
  outFile.open("plik.txt");


  srand(time(0));
  double direction;
  Vector step;
  Vector result(0.0,0.0);
  unsigned long steps = 0;
  double target;
  double dstep;
  cout << "Podaj dystans do przejścia(k, aby zakończyć): ";
  while(cin >> target){
    cout << "Podaj długość kroku: ";
    if(!(cin>>dstep)){ break; }
    outFile << "Dystans do przejścia: " << target
            << ", długość kroku: " << dstep << endl;
    while(result.magval()<target){
      outFile << steps << ": " << result << endl;
      direction = rand()%360;
      step.reset(dstep,direction,Vector::POL);
      result = result + step;
      steps++;
    }
    outFile << steps << ": " << result << endl;
    outFile << "Po " << steps << " krokach delikwent "
    "osiągnął położenie:\n";
    outFile << result << endl;
    result.polar_mode();
    outFile << " czyli\n" << result << endl;
    outFile << "Średnia długość kroku pozornego = "
         << result.magval()/steps << endl
         << "----------------------------------------------" << endl;
    steps = 0;
    result.reset(0.0,0.0);
    cout << "Podaj dystans do przejścia(k, aby zakończyć): ";
  }
  cout << "Koniec!\n";
  outFile.close();
  cin.clear();
  while(cin.get()!='\n'){ continue; }

}
