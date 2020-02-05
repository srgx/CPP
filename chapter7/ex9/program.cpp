#include <iostream>
#include <cstring>

using namespace std;

const int SLEN = 30;

struct student{
  char fullname[SLEN];
  char hobby[SLEN];
  int ooplevel;
};

int getinfo(student pa[],int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[],int n);

int main(){
  cout << "Podaj wielkość grupy: "; int class_size; cin >> class_size;
  while(cin.get()!='\n')
    continue;
  student * ptr_stu = new student[class_size];
  int entered = getinfo(ptr_stu,class_size);
  cout << "--------------------------------\n";
  cout << "***WPROWADZONE DANE***\n";
  for(int i=0;i<entered;i++){
    display1(ptr_stu[i]);
    display2(&ptr_stu[i]);
  }
  cout << "--------------------------------\n";
  display3(ptr_stu,entered);
  delete [] ptr_stu;
  cout << "Gotowe\n";
}

int getinfo(student pa[],int n){
  cout << "Wprowadź dane o studentach.\n";
  int index = 0; char temp[SLEN];
  cout << "Student 1\nImię: "; cin.getline(temp,SLEN);
  while(index<n && temp[0]!='\0'){
    strcpy(pa[index].fullname,temp);
    cout << "Hobby: "; cin.getline(pa[index].hobby,SLEN);
    cout << "OOP Level: "; cin >> pa[index].ooplevel; cin.get();
    if(++index<n){
      cout << "Student " << index+1 << endl;
      cout << "Imię: ";
      cin.getline(temp,SLEN);
    }
  }
  return index;
}

void display1(student st){
  cout << "Imię: " << st.fullname << endl;
  cout << "Hobby: " << st.hobby << endl;
  cout << "OOP Level: " << st.ooplevel << endl;
  cout << endl;
}

void display2(const student * ps){
  cout << "Imię: " << ps->fullname << endl;
  cout << "Hobby: " << ps->hobby << endl;
  cout << "OOP Level: " << ps->ooplevel << endl;
  cout << endl;
}

void display3(const student pa[],int n){
  for(int i=0;i<n;i++){
    display2(&pa[i]);
  }
}
