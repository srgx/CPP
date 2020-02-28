#include "emp.h"

void abstr_emp::ShowAll()const{
  using std::cout; using std::endl;
  cout << "Imię: " << fname << endl;
  cout << "Nazwisko: " << lname << endl;
  cout << "Zawód: " << job << endl;
}

void abstr_emp::writeall(std::ofstream & fout)const{
  using std::endl;
  fout << Type() << endl;
  fout << fname << endl;
  fout << lname << endl;
  fout << job << endl;
}

void abstr_emp::SetAll(){
  using std::cout; using std::cin;
  cout << "Podaj imię: ";
  getline(cin,fname);
  cout << "Podaj nazwisko: ";
  getline(cin,lname);
  cout << "Podaj zawód: ";
  getline(cin,job);
}


abstr_emp::~abstr_emp(){}


std::ostream & operator<<(std::ostream & os,const abstr_emp & e){
  os << e.fname << " " << e.lname;
  return os;
}

classkind abstr_emp::Type()const{
  return Employee;
}

classkind manager::Type()const{
  return Manager;
}

classkind fink::Type()const{
  return Fink;
}

classkind highfink::Type()const{
  return Highfink;
}

manager::manager(const abstr_emp & e, int ico)
: abstr_emp(e), inchargeof(ico){
}


void manager::Data()const{
  std::cout << "Pracownicy: " << inchargeof << std::endl;
}

void manager::writeData(std::ofstream & fout)const{
  fout << inchargeof << std::endl;
}

void manager::ShowAll()const{
  abstr_emp::ShowAll(); Data();
}

void manager::writeall(std::ofstream & fout)const{
  abstr_emp::writeall(fout); writeData(fout);
}

void manager::Set(){
  std::cout << "Podaj liczbę pracowników: ";
  std::cin >> inchargeof; std::cin.get();
}

void manager::SetAll(){
  abstr_emp::SetAll(); Set();
}


fink::fink(const abstr_emp & e, const std::string & rpo)
: abstr_emp(e), reportsto(rpo){
}


void fink::Data()const{
  std::cout << "Wysyła raporty do " << ReportsTo() << std::endl;
}

void fink::writeData(std::ofstream & fout)const{
  fout << ReportsTo() << std::endl;
}

void fink::ShowAll()const{
  abstr_emp::ShowAll(); Data();
}

void fink::writeall(std::ofstream & fout)const{
  abstr_emp::writeall(fout); writeData(fout);
}

void fink::Set(){
  std::cout << "Do kogo wysyłać raporty: ";
  getline(std::cin,ReportsTo());
}

void fink::SetAll(){
  abstr_emp::SetAll(); Set();
}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico)
: abstr_emp(e), fink(e,rpo), manager(e,ico){
}

highfink::highfink(const manager & m, const std::string & rpo)
: abstr_emp(m),fink(m,rpo), manager(m){
}

void highfink::ShowAll()const{
  abstr_emp::ShowAll(); manager::Data(); fink::Data();
}

void highfink::writeall(std::ofstream & fout)const{
  abstr_emp::writeall(fout); manager::writeData(fout); fink::writeData(fout);
}

void highfink::SetAll(){
  abstr_emp::SetAll(); manager::Set(); fink::Set();
}
