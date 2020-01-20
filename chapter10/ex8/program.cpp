#include <iostream>
#include "list.h"


void myFunction(Item & it);

int main(){
  using std::cout; using std::endl;
  List lst;

  cout << "Czy lista jest pusta: " << lst.isEmpty() << endl;
  cout << "Czy lista jest pełna: " << lst.isFull() << endl;
  cout << "Dodawanie elementów\n";

  lst.add("czesc");
  lst.add("kolega");
  lst.add("spoko");
  lst.add("pa");

  cout << "Rozmiar listy: " << lst.size() << endl;

  cout << "Czy lista jest pusta: " << lst.isEmpty() << endl;
  cout << "Czy lista jest pełna: " << lst.isFull() << endl;

  cout << "Ostatni element\n";
  lst.add("hej");
  cout << "Rozmiar listy: " << lst.size() << endl;

  cout << "Czy lista jest pusta: " << lst.isEmpty() << endl;
  cout << "Czy lista jest pełna: " << lst.isFull() << endl;

  cout << "Zawartość listy:\n";
  lst.show();
  cout << "Metoda visit z argumentem myFunction:\n";
  lst.visit(myFunction);
  lst.show();
  cout << "---\n";
  cout << "Koniec\n";
}


void myFunction(Item & it){
  for(int i=0;i<it.size();i++){
    it[i] = toupper(it[i]);
  }
}
