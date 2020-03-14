#include "cpmv.h"

Cpmv::Cpmv(){
  std::cout << "Konstruktor domyślny\n";
  pi = new Info; pi->qcode = "0000"; pi->zcode = "0000";
}

Cpmv::Cpmv(std::string q, std::string z){
  std::cout << "Konstruktor z parametrami string\n";
  pi = new Info; pi->qcode = q; pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv & cp){
  std::cout << "Konstruktor kopiujący\n";
  pi = new Info; *pi = *cp.pi;
}

Cpmv::Cpmv(Cpmv && mv){
  std::cout << "Konstruktor przenoszący\n";
  pi = mv.pi; mv.pi = nullptr;
}

Cpmv & Cpmv::operator=(const Cpmv & cp){
  std::cout << "Operator przypisania\n";
  if(this != &cp){ delete pi; pi = new Info; *pi = *cp.pi; }
  return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv){
  std::cout << "Przenoszący operator przypisania\n";
  if(this != &mv){ delete pi; pi = mv.pi; mv.pi = nullptr; }
  return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const{
  std::cout << "Operator dodawania\n";
  return Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
}

Cpmv::~Cpmv(){ delete pi; }

void Cpmv::Display() const{
  using std::cout; using std::endl;
  cout << "Qcode: " << pi->qcode << endl;
  cout << "Zcode: " << pi->zcode << endl;
}
