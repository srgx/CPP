#ifndef WINE__H__
#define WINE__H__
#include <valarray>


template<class T1, class T2>
class Pair{
private:
  T1 a;
  T2 b;
public:
  T1 & first();
  T2 & second();
  T1 first() const { return a; }
  T2 second() const { return b; }
  Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
  Pair(){}
};

template<class T1, class T2>
T1 & Pair<T1,T2>::first(){
  return a;
}

template<class T1, class T2>
T2 & Pair<T1,T2>::second(){
  return b;
}

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine{
private:
  std::string label;
  PairArray data;
  int years;
public:
  Wine(const char * l, int y, const int yr[], const int bot[]);
  Wine(const char * l = "brak", int y = 0);
  void GetBottles();
  void Show()const;
  int sum()const;
  const std::string & Label() const;
};


#endif
