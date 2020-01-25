#include <iostream>
#include <cstring>
#include "classic.h"

Classic::Classic(const char * s1, const char * s2, const char * s3, int n, double x) : Cd(s2,s3,n,x){
  main = new char[strlen(s1)+1];
  strcpy(main,s1);
}

Classic::Classic(){
  main = new char[5];
  strcpy(main,"brak");
}

Classic::~Classic(){
  delete [] main;
}

void Classic::Report() const{
  Cd::Report();
  std::cout << "Main Song: " << main << std::endl;
}


void Classic::ModifyObject(){
  Cd::ModifyObject();
  main[1] = 'X';
}


Classic & Classic::operator=(const Classic & d){
  if(this==&d){ return *this; }
  Cd::operator=(d);
  delete [] main;
  main = new char[strlen(d.main)+1];
  strcpy(main,d.main);
  return *this;
}

Classic::Classic(const Classic & c) : Cd(c) {
  main = new char[strlen(c.main)+1];
  strcpy(main,c.main);
}
