#include <iostream>
#include <fstream>

int main(int argc,char * argv[]){
  using namespace std;
  if(argc!=3){
    cerr << "Składnia: " << argv[0] << " plik1 plik2\n";
    exit(EXIT_FAILURE);
  }

  ifstream fin(argv[1]);
  if(!fin.is_open()){
    cerr << "Nie można otworzyć pliku " << argv[1] << " do odczytu.\n";
    exit(EXIT_FAILURE);
  }

  ofstream fout(argv[2]);
  if(!fout.is_open()){
    cerr << "Nie można otworzyć pliku " << argv[2] << " do zapisu.\n";
    exit(EXIT_FAILURE);
  }

  char ch;
  while((ch=fin.get())!=EOF){ fout << ch; }

  fin.close(); fout.close();
}
