// stack.cpp -- metody klasy stosu
#include "stack.h"
#include <iostream>

Stack::Stack(int n)            // tworzy pusty stos
{
    pitems = new Item[n];
    top = 0;
    size = n; // rozmiar stosu
}

Stack::Stack(const Stack & s){
  size = s.size;
  top = s.top;
  pitems = new Item[size];
  for(int i=0;i<top;i++){
    pitems[i] = s.pitems[i];
  }
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == size;
}

bool Stack::push(const Item & item)
{
    if (top < size)
    {
        pitems[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = pitems[--top];
        return true;
    }
    else
        return false;
}

Stack::~Stack(){
  delete [] pitems;
}

void Stack::show()const{
  std::cout << top << " elementów" << "(max "
            << size << "): ";
  for(int i=0;i<top;i++){
    std::cout << pitems[i] << " ";
  }
  std::cout << "\n";
}

Stack & Stack::operator=(const Stack & s){
  if (this == &s)
      return *this;
  delete [] pitems;
  size = s.size;
  top = s.top;
  pitems = new Item[size];
  for(int i=0;i<top;i++){
    pitems[i] = s.pitems[i];
  }
  return *this;
}
