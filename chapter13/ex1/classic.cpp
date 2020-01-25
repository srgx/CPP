#include <iostream>
#include <cstring>
#include "classic.h"

Classic::Classic(const char * s1, const char * s2, const char * s3, int n, double x) : Cd(s2,s3,n,x){
  strcpy(main,s1);
}

Classic::Classic(){
  strcpy(main,"brak");
}

void Classic::Report() const{
  Cd::Report();
  std::cout << "Main Song: " << main << std::endl;
}

void Classic::ChangeLetter(){
  main[1] = 'X';
}
