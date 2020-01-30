#include "emp.h"

void abstr_emp::ShowAll()const{
  ShowData();
}

void abstr_emp::SetAll(){
  std::cout << "Podaj imię: ";
  getline(std::cin,fname);
  std::cout << "Podaj nazwisko: ";
  getline(std::cin,lname);
  std::cout << "Podaj zawód: ";
  getline(std::cin,job);
}

void abstr_emp::ShowData()const{
  using std::cout; using std::endl;
  cout << "Imię: " << fname << endl;
  cout << "Nazwisko: " << lname << endl;
  cout << "Zawód: " << job << endl;
}

abstr_emp::~abstr_emp(){}

std::ostream & operator<<(std::ostream & os,const abstr_emp & e){
  os << e.fname << " " << e.lname;
  return os;
}

manager::manager(const abstr_emp & e, int ico)
: abstr_emp(e), inchargeof(ico){
}

manager::manager(const manager & m)
: abstr_emp(m), inchargeof(m.inchargeof){
}

void manager::ShowAll()const{
  abstr_emp::ShowAll();
  std::cout << "Pracownicy: " << inchargeof << std::endl;
}

void manager::SetAll(){
  abstr_emp::SetAll();
  std::cout << "Podaj liczbę pracowników: ";
  std::cin >> inchargeof; std::cin.get();
}


fink::fink(const abstr_emp & e, const std::string & rpo)
: abstr_emp(e), reportsto(rpo){
}

fink::fink(const fink & e)
: abstr_emp(e), reportsto(e.reportsto){
}

void fink::ShowAll()const{
  abstr_emp::ShowData();
  std::cout << "Wysyła raporty do " << ReportsTo() << std::endl;
}

void fink::SetAll(){
  abstr_emp::SetAll();
  std::cout << "Do kogo wysyłać raporty: ";
  getline(std::cin,ReportsTo());
}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico)
: abstr_emp(e),fink(e,rpo),manager(e,ico){
}

highfink::highfink(const manager & m, const std::string & rpo)
: abstr_emp(m),fink(m,rpo), manager(m){

}

highfink::highfink(const highfink & h)
: abstr_emp(h), fink(h), manager(h){
}

void highfink::ShowAll()const{
  abstr_emp::ShowData();
  std::cout << "Pracownicy: " << InChargeOf() << std::endl;
  std::cout << "Wysyła raporty do " << ReportsTo() << std::endl;
}

void highfink::SetAll(){
  abstr_emp::SetAll();
  std::cout << "Podaj liczbę pracowników: ";
  std::cin >> InChargeOf(); std::cin.get();
  std::cout << "Do kogo wysyłać raporty: ";
  getline(std::cin,ReportsTo());
}
