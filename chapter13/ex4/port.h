#ifndef PORT__H__
#define PORT__H__

#include <iostream>
using namespace std;

class Port{
public:
  static const int SIZE = 20;
private:
  char * brand;
  char style[SIZE];
  int bottles;
public:
  Port(const char * br = "Brak", const char * st = "Brak", int b = 0);
  Port(const Port & p);
  virtual ~Port(){ delete [] brand; }
  virtual void Modify();
  Port & operator=(const Port & p);
  Port & operator+=(int b);
  Port & operator-=(int b);
  int BottleCount()const { return bottles; }
  virtual void Show()const;
  friend ostream & operator<<(ostream & os, const Port & p);
};

class VintagePort : public Port{
private:
  char * nickname;
  int year;
public:
  VintagePort();
  VintagePort(const char * br, int b, const char * nn, int y);
  VintagePort(const VintagePort & vp);
  ~VintagePort() override{ delete [] nickname; }
  void Modify() override;
  VintagePort & operator=(const VintagePort & vp);
  void Show() const override;
  friend ostream & operator<<(ostream & os, const VintagePort & vp);
};

#endif
