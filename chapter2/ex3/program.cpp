#include <iostream>

void entliczek(); void stoliczek();

int main(){
  entliczek(); entliczek();
  stoliczek(); stoliczek();
}

void entliczek(){
  std::cout << "Entliczek pentliczek\n";
}

void stoliczek(){
  std::cout << "Czerwony stoliczek\n";
}
