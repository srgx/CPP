#include "emp.h"

void abstr_emp::ShowAll()const{
  using std::cout; using std::endl;
  cout << "Imię: " << fname << endl;
  cout << "Nazwisko: " << lname << endl;
  cout << "Zawód: " << job << endl;
}

void abstr_emp::WriteAll(ofstream & fout)const{
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

void abstr_emp::GetAll(ifstream & fin){
  getline(fin,fname);
  getline(fin,lname);
  getline(fin,job);
}


abstr_emp::~abstr_emp(){}


std::ostream & operator<<(ostream & os,const abstr_emp & e){
  os << e.fname << " " << e.lname;
  return os;
}

classkind abstr_emp::Type()const{
  return Employee;
}


// ----MANAGER----

classkind manager::Type()const{
  return Manager;
}


manager::manager(const abstr_emp & e, int ico)
: abstr_emp(e), inchargeof(ico){
}

void manager::Data()const{
  std::cout << "Pracownicy: " << inchargeof << std::endl;
}

void manager::WriteData(ofstream & fout)const{
  fout << inchargeof << std::endl;
}

void manager::ShowAll()const{
  abstr_emp::ShowAll(); Data();
}

void manager::WriteAll(ofstream & fout)const{
  abstr_emp::WriteAll(fout); WriteData(fout);
}

void manager::Set(){
  std::cout << "Podaj liczbę pracowników: ";
  std::cin >> inchargeof; std::cin.get();
}

void manager::Get(ifstream & fin){
  fin >> inchargeof; fin.get();
}

void manager::SetAll(){
  abstr_emp::SetAll(); Set();
}

void manager::GetAll(ifstream & fin){
  abstr_emp::GetAll(fin); Get(fin);
}


// ----FINK----

fink::fink(const abstr_emp & e, const string & rpo)
: abstr_emp(e), reportsto(rpo){
}


void fink::Data()const{
  std::cout << "Wysyła raporty do " << ReportsTo() << std::endl;
}

void fink::WriteData(ofstream & fout)const{
  fout << ReportsTo() << std::endl;
}

void fink::ShowAll()const{
  abstr_emp::ShowAll(); Data();
}

void fink::WriteAll(ofstream & fout)const{
  abstr_emp::WriteAll(fout); WriteData(fout);
}

void fink::Set(){
  std::cout << "Do kogo wysyłać raporty: ";
  getline(std::cin,ReportsTo());
}

void fink::Get(ifstream & fin){
  getline(fin,ReportsTo());
}

void fink::SetAll(){
  abstr_emp::SetAll(); Set();
}

void fink::GetAll(ifstream & fin){
  abstr_emp::GetAll(fin); Get(fin);
}


classkind fink::Type()const{
  return Fink;
}


// ----HIGHFINK----

highfink::highfink(const abstr_emp & e, const string & rpo, int ico)
: abstr_emp(e), fink(e,rpo), manager(e,ico){
}

highfink::highfink(const manager & m, const string & rpo)
: abstr_emp(m),fink(m,rpo), manager(m){
}

void highfink::ShowAll()const{
  abstr_emp::ShowAll(); manager::Data(); fink::Data();
}

void highfink::WriteAll(ofstream & fout)const{
  abstr_emp::WriteAll(fout); manager::WriteData(fout); fink::WriteData(fout);
}

void highfink::SetAll(){
  abstr_emp::SetAll(); manager::Set(); fink::Set();
}

void highfink::GetAll(ifstream & fin){
  abstr_emp::GetAll(fin); manager::Get(fin); fink::Get(fin);
}

classkind highfink::Type()const{
  return Highfink;
}
