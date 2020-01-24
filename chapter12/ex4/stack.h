#ifndef STACK__H__
#define STACK__H__

typedef unsigned long Item;

class Stack{
private:
  enum {MAX = 3};
  Item * pitems;
  int size;
  int top;
public:
  Stack(int n = MAX);
  Stack(const Stack & st);
  ~Stack();
  bool isempty()const;
  bool isfull()const;
  bool push(const Item & item);
  bool pop(Item & item);
  Stack & operator=(const Stack & s);
  void show()const;
};


#endif
