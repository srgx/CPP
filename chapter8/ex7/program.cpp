#include <iostream>

using namespace std;

template <typename T>
void ShowArray(T const arr[],int n);

template <typename T>
void ShowArray(T * const arr[], int n);

template <typename T>
T SumArray(T const arr[],int n);

template <typename T>
T SumArray(T * const arr[], int n);

struct debts{
  char name[50];
  double amount;
};

int main(){
  const int IleRzeczy = 6; const int IleDlugow = 3;
  int things[IleRzeczy] = {13,31,103,301,310,130};

  debts mr_E[IleDlugow] = {
    {"Ima Wolfe", 2400.0},
    {"Ura Foxe", 1300.0},
    {"Iby Stout", 1800.0}
  };

  double * pd[IleDlugow];
  for(int i=0;i<IleDlugow;i++){
    pd[i] = &mr_E[i].amount;
  }

  cout << "Wyliczanie rzeczy pana E.:\n";
  ShowArray(things,IleRzeczy);
  cout << "Wyliczanie długów pana E.:\n";
  ShowArray(pd,IleDlugow);
  cout << "Suma rzeczy pana E.:\n";
  cout << SumArray(things,IleRzeczy) << endl;
  cout << "Suma długów pana E.:\n";
  cout << SumArray(pd,IleDlugow) << endl;
}

template <typename T>
void ShowArray(T const arr[],int n){
  for(int i=0;i<n;i++){
    cout << arr[i] << ' ';
  }
  cout << endl;
}

template <typename T>
void ShowArray(T * const arr[],int n){
  for(int i=0;i<n;i++){
    cout << *arr[i] << ' ';
  }
  cout << endl;
}

template <typename T>
T SumArray(T const arr[],int n){
  T suma = 0;
  for(int i=0;i<n;i++){
    suma += arr[i];
  }
  return suma;
}

template <typename T>
T SumArray(T * const arr[], int n){
  T suma = 0;
  for(int i=0;i<n;i++){
    suma += *arr[i];
  }
  return suma;
}
