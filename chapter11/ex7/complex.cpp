#include "complex0.h"

Complex::Complex(){
  real = 0;
  imag = 0;
}

Complex::Complex(float r, float i){
  real = r;
  imag = i;
}

Complex Complex::operator+(const Complex & c)const{
  return Complex(real+c.real,imag+c.imag);
}

Complex Complex::operator-(const Complex & c)const{
  return Complex(real-c.real,imag-c.imag);
}

Complex Complex::operator*(const Complex & c)const{
  float r = real*c.real-imag*c.imag;
  float i = real*c.imag+imag*c.real;
  return Complex(r,i);
}

Complex Complex::operator*(float n)const{
  return Complex(n*real,n*imag);
}

Complex operator*(float n,const Complex & c){
  return c * n;
}


Complex Complex::operator~(){
  return Complex(real,-imag);
}


std::istream & operator>>(std::istream & is, Complex & c){
  std::cout << "Składowa rzeczywista: ";
  float r; is >> r; if(!is){ return is; }
  std::cout << "Składowa urojona: ";
  float i; is >> i; if(!is){ return is; }
  c.real = r;
  c.imag = i;
  return is;
}

std::ostream & operator<<(std::ostream & os, const Complex & c){
  os << "(" << c.real << ", " << c.imag << "i)";
  return os;
}
