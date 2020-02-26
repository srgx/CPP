#include <iostream>
#include <fstream>

int main(int argc,char * argv[]){
  using namespace std;

  if(argc==1){
    cerr << "Składnia: " << argv[0] << " plik\n";
    exit(EXIT_FAILURE);
  }

  string file = argv[1];
  ofstream fout(file);

  if(!fout.is_open()){
    cerr << "Nie można otworzyć pliku " << file << " do zapisu.\n";
    exit(EXIT_FAILURE);
  }

  cout << "Podawaj znaki. EOF kończy wprowadzanie:\n";
  char ch;
  while((ch=cin.get())!=EOF){ fout << ch; }

  fout.close();

  cout << "Koniec\n";
}
