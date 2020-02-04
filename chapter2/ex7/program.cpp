#include <iostream>

void showTime(int,int);

int main(){
  std::cout << "Podaj liczbę godzin: ";
  int hours;
  std::cin >> hours;
  std::cout << "Podaj liczbę minut: ";
  int minutes;
  std::cin >> minutes;
  showTime(hours,minutes);
}

void showTime(int hours, int minutes){
  const int minutes_in_hour = 60;
  int hours_from_minutes = minutes / minutes_in_hour;
  hours += hours_from_minutes; minutes %= minutes_in_hour;
  std::cout << "Czas: " << hours << (minutes < 10 ? ":0" : ":") << minutes << std::endl;
}
