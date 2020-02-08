#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>
#include <algorithm>

const int SIZE = 500000;
const int LIMIT = SIZE*10;

int main(){
  using std::vector; using std::list; using std::cout; using std::endl;
  std::srand(std::time(0));
  vector<int>vi0;

  // vector losowych liczb
  for(int i=0;i<SIZE;i++){ vi0.push_back(rand() % LIMIT); }

  vector<int>vi(vi0);
  list<int>li(vi0.begin(),vi0.end());


  // czas sortowania vectora
  clock_t start = clock();
  std::sort(vi.begin(),vi.end());
  clock_t end = clock();
  cout << "Sortowanie vectora: ";
  cout << (double)(end-start)/CLOCKS_PER_SEC << endl;


  // czas sortowania listy
  start = clock();
  li.sort();
  end = clock();
  cout << "Sortowanie listy: ";
  cout << (double)(end-start)/CLOCKS_PER_SEC << endl;

  // resetowanie listy
  li.assign(vi0.begin(),vi0.end());

  // Sortowanie listy z pomocą vectora
  start = clock();
  vi.assign(li.begin(),li.end());
  sort(vi.begin(),vi.end());
  li.assign(vi.begin(),vi.end());
  end = clock();

  cout << "Sortowanie listy z użyciem vectora: ";
  cout << (double)(end-start)/CLOCKS_PER_SEC << endl;


}
