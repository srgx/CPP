#include <iostream>
#include <cstring>
#include "person.h"


Person::Person(const std::string & ln, const char * fn){
  lname = ln;
  strcpy(fname,fn);
}

void Person::Show() const{
  std::cout << "Imię: " << fname << std::endl;
  std::cout << "Nazwisko: " << lname << std::endl;
}

void Person::FormalShow() const{
  std::cout << "Nazwisko: " << lname << std::endl;
  std::cout << "Imię: " << fname << std::endl;
}


