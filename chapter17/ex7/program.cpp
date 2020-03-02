#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include "store.h"

void ShowStr(const std::string & str);
void GetStrs(std::ifstream & ifs,std::vector<std::string> & vec);

int main(){
  using namespace std;
  const char * file = "lancuchy.dat";
  vector<string> vostr;
  string temp;

  cout << "Podaj łańcuchy (aby zakończyć, wprowadź pusty wiersz):\n";
  while(getline(cin,temp)&&temp[0]!='\0'){ vostr.push_back(temp); }

  cout << "Oto twoje dane wejściowe.\n";
  for_each(vostr.begin(), vostr.end(), ShowStr);

  // zapisz dane do pliku
  ofstream fout(file, ios_base::out | ios_base::binary);
  for_each(vostr.begin(),vostr.end(),Store(fout));
  fout.close();

  vector<string> vistr;
  ifstream fin(file, ios_base::in | ios_base::binary);
  if(!fin.is_open()){
    cerr << "Nie można otworzyć pliku do odczytu.\n"; exit(EXIT_FAILURE);
  }

  // odczytaj dane z pliku
  GetStrs(fin,vistr);

  cout << "\nOto łańcuchy odczytane z pliku:\n";
  for_each(vistr.begin(),vistr.end(),ShowStr);

  return 0;
}

void ShowStr(const std::string & str){ std::cout << str << std::endl; }

void GetStrs(std::ifstream & fin,std::vector<std::string> & vec){
  int size;
  while(fin.read((char*)&size,sizeof(std::size_t))){
    std::string temp; char ch;
    for(int i=0;i<size;i++){ fin.read((char*)&ch,sizeof(char)); temp += ch; }
    vec.push_back(temp);
  }
}
