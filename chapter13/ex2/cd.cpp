#include <iostream>
#include <cstring>
#include "cd.h"

Cd::Cd(const char * s1, const char * s2, int n, double x){
  performers = new char[strlen(s1)+1];
  label = new char[strlen(s2)+1];
  strcpy(performers,s1);
  strcpy(label,s2);
  selections = n;
  playtime = x;
}

Cd::Cd(){
  performers = new char[5];
  label = new char[5];
  strcpy(performers,"brak");
  strcpy(label,"brak");
  selections = 0;
  playtime = 0;
}


Cd::~Cd(){
  delete [] performers;
  delete [] label;
}

void Cd::Report() const{
  using std::cout; using std::endl;
  cout << "Performers: " << performers << endl;
  cout << "Label: " << label << endl;
  cout << "Selections: " << selections << endl;
  cout << "Playtime: " << playtime << endl;
}

void Cd::ModifyObject(){
  selections = 999;
  playtime = 999;
  performers[1] = 'X';
  label[1] = 'X';
}


Cd::Cd(const Cd & d){
  performers = new char[strlen(d.performers)+1];
  label = new char[strlen(d.label)+1];
  strcpy(performers,d.performers);
  strcpy(label,d.label);
  selections = d.selections;
  playtime = d.playtime;
}


Cd & Cd::operator=(const Cd & d){
  if(this==&d){ return *this; }
  delete [] performers;
  delete [] label;
  performers = new char[strlen(d.performers)+1];
  label = new char[strlen(d.label)+1];
  strcpy(performers,d.performers);
  strcpy(label,d.label);
  selections = d.selections;
  playtime = d.playtime;
  return *this;
}
