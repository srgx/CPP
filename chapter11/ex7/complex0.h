#ifndef COMPLEX__H__
#define COMPLEX__H__
#include <iostream>

class Complex{
  private:
    float real;
    float imag;
  public:
    Complex();
    Complex(float r, float i);

    Complex operator+(const Complex & c)const;
    Complex operator-(const Complex & c)const;

    Complex operator*(const Complex & c)const;
    Complex operator*(float n)const;
    friend Complex operator*(float n,const Complex & c);

    Complex operator~()const;

    friend std::ostream & operator<<(std::ostream & os, const Complex & c);
    friend std::istream & operator>>(std::istream & is, Complex & c);
};

#endif
