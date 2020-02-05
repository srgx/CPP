#include <iostream>

using namespace std;

void showmenu();

int main(){
  showmenu(); char ch;

  do{
    cout << "Proszę podać literę r p d lub g: "; cin.get(ch);
    while(cin.get()!='\n')
      continue;
  }while(ch!='r'&&ch!='p'&&ch!='d'&&ch!='g');

  switch(ch){
    case 'r': cout << "Roślinożercy jedzą rośliny."; break;
    case 'p': cout << "Chopin wielkim pianistą był."; break;
    case 'd': cout << "Drzewo to orzech."; break;
    case 'g': cout << "Gram w Tomb Raider."; break;
  }

  cout << "\nGotowe.\n";
}

void showmenu(){
  cout << "r) roślinożerca\tp) pianista\n";
  cout << "d) drzewo\tg) gra\n";
}
