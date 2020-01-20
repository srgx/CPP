#ifndef STACK__H__
#define STACK__H__
#include "customer.h"

typedef customer Item;

class Stack{
  private:
    enum { MAX = 10 };
    Item items[MAX];
    int top;
  public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
};

#endif
