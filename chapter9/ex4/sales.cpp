#include <iostream>
#include "sales.h"

namespace SALES{

  void setSales(Sales & s, const double ar[],int n){
    int toCopy = n < QUARTERS ? n : QUARTERS;
    
    for(int i=0;i<QUARTERS;i++){
      s.sales[i] = i<toCopy ? ar[i] : 0;
    }
    
    double min,max,sum;
    min = max = sum = s.sales[0];
    for(int i=1;i<QUARTERS;i++){
      if(s.sales[i]<min){ min = s.sales[i]; }
      if(s.sales[i]>max){ max = s.sales[i]; }
      sum+=s.sales[i];
    }
    
    s.max = max;
    s.min = min;
    s.average = sum / QUARTERS;
  }

  void setSales(Sales & s){
    for(int i=0;i<QUARTERS;i++){
      std::cout << "Podaj wartość za kwartał " << i+1 << ": ";
      std::cin >> s.sales[i];
    }
    
    double min, max, sum;
    min = max = sum = s.sales[0];
    for(int i=1;i<QUARTERS;i++){
      if(s.sales[i]<min){ min = s.sales[i]; }
      if(s.sales[i]>max){ max = s.sales[i]; }
      sum += s.sales[i];
    }
    
    s.max = max;
    s.min = min;
    s.average = sum / QUARTERS;
  }
  
  void showSales(const Sales & s){
    for(int i=0;i<QUARTERS;i++){
      std::cout << "Kwartał " << i+1 << ": " << s.sales[i] << std::endl;
    }
    std::cout << "Max: " << s.max << std::endl;
    std::cout << "Min: " << s.min << std::endl;
    std::cout << "Avg: " << s.average << std::endl;
  }
}


