#ifndef LIST__H__
#define LIST__H__
#include "cell.h"

class List{
  private:
    static const int MAX = 5;
    Cell top;
  public:
    List();
    ~List();
    void add(const Item str);
    void show()const;
    void visit(void(*pf)(Item &));
    bool isEmpty()const;
    bool isFull()const;
    int size()const;
};

#endif
