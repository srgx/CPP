#include <iostream>
#include "sales.h"

namespace SALES{

  Sales::Sales(){
    m_average = 0;
    m_max = 0;
    m_min = 0;
    for(int i=0;i<QUARTERS;i++){
      m_sales[i] = 0;
    }
  }

  Sales::Sales(const double ar[],int n){
    int toCopy = n < QUARTERS ? n : QUARTERS;
    
    for(int i=0;i<QUARTERS;i++){
      m_sales[i] = i<toCopy ? ar[i] : 0;
    }
    
    double min,max,sum;
    min = max = sum = m_sales[0];
    for(int i=1;i<QUARTERS;i++){
      if(m_sales[i]<min){ min = m_sales[i]; }
      if(m_sales[i]>max){ max = m_sales[i]; }
      sum+=m_sales[i];
    }
    
    m_max = max;
    m_min = min;
    m_average = sum / QUARTERS;
  }

  void Sales::Set(){
    double sls[QUARTERS]; 
    for(int i=0;i<QUARTERS;i++){
      std::cout << "Podaj wartość za kwartał " << i+1 << ": ";
      std::cin >> sls[i];
    }
    
    *this = Sales(sls,QUARTERS);
  }
  
  void Sales::Show()const{
    for(int i=0;i<QUARTERS;i++){
      std::cout << "Kwartał " << i+1 << ": " << m_sales[i] << std::endl;
    }
    std::cout << "Max: " << m_max << std::endl;
    std::cout << "Min: " << m_min << std::endl;
    std::cout << "Avg: " << m_average << std::endl;
  }
}


