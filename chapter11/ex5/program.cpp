#include <iostream>
#include "stonewt.h"

int main(){
  using std::cout; using std::endl;
  Stonewt a = Stonewt(24.5);
  Stonewt b = Stonewt(10);

  cout << "Tryb kamieni:\n";
  cout << a << endl;

  cout << "Tryb funtów z częścią ułamkową:\n";
  a.SetMode(Stonewt::FUNZ);
  cout << a << endl;

  cout << "Tryb funtów bez części ułamkowej:\n";
  a.SetMode(Stonewt::FUNB);
  cout << a << endl;

  cout << "Suma:\n";
  Stonewt sum = a + b;
  cout << sum << endl;

  cout << "Różnica:\n";
  Stonewt diff = a - b;
  cout << diff << endl;

  cout << "Różnica * 2:\n";
  cout << diff * 2 << endl;

  cout << "3 * Suma:\n";
  cout << 3 * sum << endl;

  cout << "Koniec\n";
}
