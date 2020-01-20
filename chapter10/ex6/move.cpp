#include <iostream>
#include "move.h"

Move::Move(double a, double b){
  x = a; y = b;
}

void Move::showmove() const{
  std::cout << "X: " << x << std::endl;
  std::cout << "Y: " << y << std::endl;
}

Move Move::add(const Move & m) const{
  double new_x = x + m.x;
  double new_y = y + m.y;
  return Move(new_x,new_y);
}

void Move::reset(double a, double b){
  *this = Move(a,b);
}
