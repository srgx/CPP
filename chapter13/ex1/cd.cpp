#include <iostream>
#include <cstring>
#include "cd.h"

Cd::Cd(const char * s1, const char * s2, int n, double x){
  strncpy(performers,s1,49);
  performers[49] = '\0';
  strncpy(label,s2,19);
  label[19] = '\0';
  selections = n;
  playtime = x;
}

Cd::Cd(){
  strcpy(performers,"brak");
  strcpy(label,"brak");
  selections = 0;
  playtime = 0;
}

/*
Cd::~Cd(){

}*/

void Cd::Report() const{
  using std::cout; using std::endl;
  cout << "Performers: " << performers << endl;
  cout << "Label: " << label << endl;
  cout << "Selections: " << selections << endl;
  cout << "Playtime: " << playtime << endl;
}

void Cd::ChangeSel(){
  selections = 999;
}

/*
Cd::Cd(const Cd & d){
  strcpy(performers,d.performers);
  strcpy(label,d.label);
  selections = d.selections;
  playtime = d.playtime;
}*/


/*
Cd & Cd::operator=(const Cd & d){
  if(this==&d){ return *this; }
  strcpy(performers,d.performers);
  strcpy(label,d.label);
  selections = d.selections;
  playtime = d.playtime;
}*/
