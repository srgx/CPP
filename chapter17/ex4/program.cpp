#include <iostream>
#include <fstream>

int main(){
  using namespace std;
  string file1 = "one.txt";
  string file2 = "two.txt";
  string file3 = "three.txt";

  ifstream fin1(file1);
  if(!fin1.is_open()){
    cerr << "Nie można otworzyć pliku " << file1 << " do odczytu.\n";
    exit(EXIT_FAILURE);
  }

  ifstream fin2(file2);
  if(!fin2.is_open()){
    cerr << "Nie można otworzyć pliku " << file2 << " do odczytu.\n";
    exit(EXIT_FAILURE);
  }

  ofstream fout(file3);
  if(!fout.is_open()){
    cerr << "Nie można otworzyć pliku " << file3 << " do zapisu.\n";
    exit(EXIT_FAILURE);
  }

  string temp;
  while(fin1.peek()!=EOF||fin2.peek()!=EOF){
    if(getline(fin1,temp)){ fout << temp; }
    if(getline(fin2,temp)){ fout << " "; fout << temp; }
    fout << "\n";
  }

  fin1.close(); fin2.close(); fout.close();
}
