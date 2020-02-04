#include <iostream>

int celsiusToFahrenheit(int);

int main(){
  std::cout << "Podaj temperaturę w stopniach celsjusza: ";
  int celsius;
  std::cin >> celsius;
  int fahrenheit = celsiusToFahrenheit(celsius);
  std::cout << celsius << " stopni celsjusza to " << fahrenheit << " stopni fahrenheita.\n";
}

int celsiusToFahrenheit(int celsius){
  return celsius * 1.8 + 32.0;
}
