#include <iostream>
#include <cstring>
#include "cow.h"

Cow::Cow(){
  strcpy(name,"C++ow");
  hobby = new char[5];
  strcpy(hobby,"brak");
  weight = 0;
}

Cow::~Cow(){
  delete [] hobby;
}

Cow::Cow(const char * nm, const char * ho, double wt){
  hobby = new char[strlen(ho)+1];
  strcpy(hobby,ho);
  strcpy(name,nm);
  weight = wt;
}

Cow::Cow(const Cow & c){
  hobby = new char[strlen(c.hobby)+1];
  strcpy(hobby,c.hobby);
  strcpy(name,c.name);
  weight = c.weight;
}

Cow & Cow::operator=(const Cow & c){
  if(this==&c){ return *this; }
  delete [] hobby;
  hobby = new char[strlen(c.hobby)+1];
  strcpy(hobby,c.hobby);
  strcpy(name,c.name);
  weight = c.weight;
  return *this;
}

void Cow::SetHobby(const char * hb){
  delete [] hobby;
  hobby = new char[strlen(hb)+1];
  strcpy(hobby,hb);
}

void Cow::ShowCow() const{
  using std::cout; using std::endl;
  cout << "Imię: " << name << endl;
  cout << "Hobby: " << hobby << endl;
  cout << "Waga: " << weight << endl;
  cout << "----------\n";
}
