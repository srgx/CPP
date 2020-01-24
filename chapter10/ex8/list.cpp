#include <iostream>
#include "list.h"

List::List(){
  top = {"Sentinel",nullptr};
}

List::~List(){
  while(top.next){
    Cell * to_delete = top.next;
    top.next = top.next->next;
    std::cout << "Delete " << to_delete->value << std::endl;
    delete to_delete;
  }
}

void List::add(const Item str){
  if(size()>=MAX){ return; }
  Cell * pt = &top;
  while(pt->next){ pt = pt->next; }
  Cell * n = new Cell;
  n->value = str; n->next = NULL;
  pt->next = n;
}

void List::visit(void(*pf)(Item &)){
  Cell * pt = &top;
  while(pt->next){
    pf(pt->next->value);
    pt = pt->next;
  }
}

void List::show()const{
  const Cell * pt = &top;
  while(pt->next){
    std::cout << pt->next->value << std::endl;
    pt = pt->next;
  }
}

int List::size()const{
  const Cell * pt = &top;
  int sz = 0;
  while(pt->next){
    sz++; pt = pt->next;
  }
  return sz;
}

bool List::isEmpty()const{
  return !top.next;
}
bool List::isFull()const{
  return size() >= MAX;
}
