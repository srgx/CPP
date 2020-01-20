#include <iostream>
#include <cctype>
#include "stack.h"


int main(){
  using std::cout; using std::endl;
  Stack st;
  cout << "Czy stos jest pusty: " << st.isempty() << endl;
  cout << "Czy stos jest pełny: " << st.isfull() << endl;

  const int SIZE = 4;
  Item it[SIZE] = {
    {"Jan", 52.5},
    {"Maria",22.15},
    {"Mariusz", 99.31},
    {"Zuza", 17.34},
  };

  std::cout << "Dodaję wartości\n";
  st.push(it[0]);
  st.push(it[1]);
  st.push(it[2]);
  st.push(it[3]);

  double suma = 0;
  cout << "Czy stos jest pusty: " << st.isempty() << endl;
  cout << "Czy stos jest pełny: " << st.isfull() << endl;

  Item val;
  for(int i=0;i<SIZE;i++){
    st.pop(val);
    cout << val.fullname << ", " << val.payment << endl;
    suma += val.payment;
    cout << "Suma należności: " << suma << endl;
  }

  cout << "Koniec\n";

}
