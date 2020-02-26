#include <iostream>

int main(){
  using std::cin; using std::cout; using std::endl;
  cout << "Podawaj znaki. Znak $ kończy wprowadzanie:\n";
  int count = 0;
  while(cin.peek()!='$'){
    if(cin.get()!='\n') { count++; }
  }
  cout << "Podano " << count << " znaków. ";
  cout << "Znak ze strumienia: " << (char)cin.get() << endl;
}
