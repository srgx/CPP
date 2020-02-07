#ifndef EXCMEAN__H__
#define EXCMEAN__H__

// exc_mean.h -- klasy wyjątków dla funkcji hmean() i gmean()
#include <iostream>
#include <stdexcept>


class bad_mean : public std::logic_error{
private:
  double a;
  double b;
protected:
  double getA(){ return a; }
  double getB(){ return b; }
public:
  bad_mean(double a,double b) : logic_error(""), a(a), b(b){}
  virtual std::string Name(){ return "bad_mean "; }
  virtual void show(){ std::cout << "Niepoprawne argumenty funkcji "
                                 << Name() << ": " << a << ", " << b << std::endl; };
};

class bad_hmean : public bad_mean
{
    public:
        bad_hmean(double a,double b) : bad_mean(a,b){}
        std::string Name(){ return "bad_hmean"; }
};


class bad_gmean : public bad_mean
{
    public:
        bad_gmean(double a,double b) : bad_mean(a,b){}
        std::string Name(){ return "bad_gmean"; }

};

#endif
