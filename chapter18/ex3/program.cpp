#include <iostream>

template<typename T>
long double sum_values(const T& value){
  return (long double)value;
}

template<typename T, typename... Args>
long double sum_values(const T& value, const Args&... args){
  return (long double)value + sum_values(args...);
}

int main(){
  std::cout << sum_values(12,18,50.5,10.4,9.1) << std::endl;
}
