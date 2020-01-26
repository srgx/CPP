#include <cstring>
#include "port.h"


// PORT

Port::Port(const char * br, const char * st, int b){
  brand = new char[strlen(br)+1];
  strcpy(brand,br);
  strncpy(style,st,SIZE-1);
  style[SIZE-1] = '\0';
  bottles = b;
}

Port::Port(const Port & p){
  brand = new char[strlen(p.brand)+1];
  strcpy(brand,p.brand);
  strncpy(style,p.style,SIZE-1);
  style[SIZE-1] = '\0';
  bottles = p.bottles;
}

Port & Port::operator=(const Port & p){
  if(this==&p)
    return *this;
  delete [] brand;
  brand = new char[strlen(p.brand)+1];
  strcpy(brand,p.brand);
  strncpy(style,p.style,SIZE-1);
  style[SIZE-1] = '\0';
  bottles = p.bottles;
  return *this;
}

Port & Port::operator+=(int b){
  bottles+=b;
  return *this;
}

Port & Port::operator-=(int b){
  bottles-=b;
  return *this;
}

void Port::Show()const{
  using std::cout; using std::endl;
  cout << "Marka: " << brand << endl;
  cout << "Rodzaj: " << style << endl;
  cout << "Butelek: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p){
  os << p.brand << ", " << p.style << ", " << p.bottles;
  return os;
}

void Port::Modify(){
  brand[1] = 'X';
}

// VINTAGE PORT

VintagePort::VintagePort() : Port(){
  nickname = new char[5];
  strcpy(nickname,"brak");
  year = 0;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y) : Port(br,"najlepszy rocznik",b){
  nickname = new char[strlen(nn)+1];
  strcpy(nickname,nn);
  year = y;
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp){
  nickname = new char[strlen(vp.nickname)+1];
  strcpy(nickname,vp.nickname);
  year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp){
  if (this == &vp)
    return *this;
  Port::operator=(vp);
  delete [] nickname;
  nickname = new char[strlen(vp.nickname)+1];
  strcpy(nickname,vp.nickname);
  year = vp.year;
  return *this;
}

void VintagePort::Show()const{
  using std::cout; using std::endl;
  Port::Show();
  cout << "Nazwa: " << nickname << endl;
  cout << "Rok: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp){
  os << (const Port &)vp;
  os << ", " << vp.nickname << ", " << vp.year;
}

void VintagePort::Modify(){
  Port::Modify();
  nickname[1] = 'X';
}
