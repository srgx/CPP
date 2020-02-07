#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using std::cout; using std::vector; using std::endl;

vector<int> Lotto(int numbers, int choices);

int main(){
  std::srand(std::time(0)); vector<int>vctr;

  try{
    vctr = Lotto(51,6);
  }
  catch(const char * msg){
    cout << msg << endl;
    return 1;
  }

  for(const auto & ve : vctr){ cout << ve << " "; } cout << endl;
}

vector<int> Lotto(int numbers, int choices){
  if(choices>numbers){ throw "Niepoprawne argumenty funkcji Lotto()"; }
  vector<int>ve;
  for(int i=1;i<=numbers;i++){ ve.push_back(i); }
  std::random_shuffle(ve.begin(),ve.end());
  ve.resize(choices);
  return ve;
}
