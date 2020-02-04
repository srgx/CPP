#include <iostream>

int main(){
  const int metres_in_mile = 1852;
  std::cout << "Podaj odległość w milach morskich: ";
  int miles;
  std::cin >> miles;
  std::cout << miles << " mil morskich to " << miles * metres_in_mile << " metrów.\n";
}
