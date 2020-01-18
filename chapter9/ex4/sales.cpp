#include <iostream>
#include "sales.h"

namespace SALES{

  void setSales(Sales & s, const double ar[],int n){
    int toCopy = n < QUARTERS ? n : QUARTERS;
    double min,max,sum;
    sum = 0;
    for(int i=0;i<QUARTERS;i++){
      s.sales[i] = i<toCopy ? ar[i] : 0;
      sum+=s.sales[i];
    }
    
    min = max = s.sales[0];
    for(int i=1;i<QUARTERS;i++){
      if(s.sales[i]<min){ min = s.sales[i]; }
      if(s.sales[i]>max){ max = s.sales[i]; }
    }
    
    s.max = max;
    s.min = min;
    s.average = sum / toCopy;
  }

  void setSales(Sales & s){
    for(int i=0;i<QUARTERS;i++){
      std::cout << "Podaj wartość za kwartał " << i+1 << ": ";
      std::cin >> s.sales[i];
    }
  }
  
  void showSales(const Sales & s){
    // ...
  }
}


