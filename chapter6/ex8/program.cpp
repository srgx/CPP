#include <iostream>
#include <fstream>

int main(){
  using namespace std;
  const int SIZE = 60;
  const char filename[SIZE] = "ex6-8.txt";
  ifstream inFile; inFile.open(filename);

  if(!inFile.is_open()){
    cout << "Nie udało się otworzyć pliku.\n";
    exit(EXIT_FAILURE);
  }

  int count = 0; inFile.get();
  while(inFile.good()){ count++; inFile.get(); }

  if(inFile.eof())
    cout << "Koniec pliku.\n";
  else if(inFile.fail())
    cout << "Przerwano wczytywanie danych - błąd\n";
  else
    cout << "Przerwano wczytywanie danych - przyczyna nieznana\n";

  if(0==count)
    cout << "Nie wczytano żadnych danych.\n";
  else
    cout << "Wczytano " << count << " znaków.\n";

  inFile.close();
}
