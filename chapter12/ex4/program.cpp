#include <iostream>
#include "stack.h"

int main(){
  using std::cout; using std::endl;
  Stack one(4), two;
  for(int i=5;i<10;i++){
    if(one.push(i)){
      cout << "Dodano " << i << endl;
    }else{
      cout << "Nie udało się dodać " << i << endl;
    }
  }

  if(one.isfull()){
    cout << "Stos 1 pełny\n";
  }
  
  if(two.isempty()){
    cout << "Stos 2 pusty\n";
  }

  cout << "Stos 1:\n";
  one.show();
  cout << "Stos 2:\n";
  two.show();

  cout << "Przypisanie 1 do 2\n";
  two = one;
  cout << "Stos 1:\n";
  one.show();
  cout << "Stos 2:\n";
  two.show();
  cout << "Usuwanie elementu stosu 1\n";
  Item it;
  one.pop(it);
  cout << "Usunięty element: " << it << endl;
  cout << "Stos 1:\n";
  one.show();
  cout << "Stos 2:\n";
  two.show();

  for(int i=0;i<4;i++){
    if(one.pop(it)){
      cout << "Usunięty element ze stosu 1: " << it << endl;
    }else{
      cout << "Nie udało się usunąć\n";
    }
  }
  cout << "Stos 1:\n";
  one.show();
  cout << "---------------\n";
  cout << "Stos 3 ze stosu 2\n";
  Stack three(two);
  cout << "Stos 2:\n";
  two.show();
  cout << "Stos 3:\n";
  three.show();
  cout << "Usunięcie elementu ze stosu 3\n";
  three.pop(it); cout << it << endl;
  cout << "Stos 2:\n";
  two.show();
  cout << "Stos 3:\n";
  three.show();
  cout << "Koniec\n";
}
