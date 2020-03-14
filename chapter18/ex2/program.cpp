#include <iostream>
#include "cpmv.h"

int main(){
  Cpmv test;
  test.Display();

  Cpmv test2("metoda", "funkcja");
  test2.Display();

  Cpmv test3(test2);
  test3.Display();

  Cpmv test4(std::move(test3));
  test4.Display();

  Cpmv test5;
  test5 = test4;
  test5.Display();

  Cpmv test6;
  test6 = (test4 + test5);
  test6.Display();

}
