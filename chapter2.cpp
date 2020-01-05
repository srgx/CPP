#include <iostream>

void exercise1(); void exercise2(); void exercise3();
void exercise4(); void exercise5(); void exercise6();
void exercise7(); void entliczek(); void stoliczek();
int celsiusToFahrenheit(int); void showTime(int,int);

int main(){
  exercise1();
  return 0;
}

void exercise1(){
  std::cout << "Jan Kowalski\n";
}

void exercise2(){
  const int metres_in_mile = 1852;
  std::cout << "Podaj odległość w milach morskich: ";
  int miles;
  std::cin >> miles;
  std::cout << miles << " mil morskich to " << miles * metres_in_mile << " metrów.\n";
}

void exercise3(){
  entliczek(); entliczek();
  stoliczek(); stoliczek();
}

void exercise4(){
  std::cout << "Podaj swój wiek: ";
  int age_years;
  std::cin >> age_years;
  const int months = 12;
  std::cout << age_years << " lat to " << age_years * months << " miesięcy.\n";
}

void exercise5(){
  std::cout << "Podaj temperaturę w stopniach celsjusza: ";
  int celsius;
  std::cin >> celsius;
  int fahrenheit = celsiusToFahrenheit(celsius);
  std::cout << celsius << " stopni celsjusza to " << fahrenheit << " stopni fahrenheita.\n";
}

void exercise6(){
  std::cout << "Podaj liczbę lat świetlnych: ";
  const double au_in_year = 63240;
  double years;
  std::cin >> years;
  std::cout << years << " lat świetlnych to " << years * au_in_year 
            << " jednostek astronomicznych\n";
  
}

void exercise7(){
  std::cout << "Podaj liczbę godzin: ";
  int hours;
  std::cin >> hours;
  std::cout << "Podaj liczbę minut: ";
  int minutes;
  std::cin >> minutes;
  showTime(hours,minutes);
}

void entliczek(){
  std::cout << "Entliczek pentliczek\n";
}

void stoliczek(){
  std::cout << "Czerwony stoliczek\n";
}

int celsiusToFahrenheit(int celsius){
  return celsius * 1.8 + 32.0;
}

void showTime(int hours, int minutes){
  const int minutes_in_hour = 60;
  int hours_from_minutes = minutes / minutes_in_hour;
  hours += hours_from_minutes; minutes %= minutes_in_hour;
  std::cout << "Czas: " << hours << (minutes < 10 ? ":0" : ":") << minutes << std::endl;
}


