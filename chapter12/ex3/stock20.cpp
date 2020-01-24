// stock20.cpp -- wersja dozbrojona
#include <iostream>
#include <cstring>
#include "stock20.h"

// konstruktory
Stock::Stock()                   // konstruktor domyślny
{
    company = new char[10];
    strcpy(company,"bez nazwy");
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char * co, long n, double pr)
{
    company = new char[strlen(co)+1];
    strcpy(company,co);

    if (n < 0)
    {
        std::cout << "Liczba udziałów nie może być ujemna; "
            << "ustalam liczbę udziałów w " << company << " na 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

// destruktor klasy
Stock::~Stock()               // wersja "dyskretna"
{
  delete [] company;
}

// pozostałe metody
void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Liczba nabywanych udziałów nie może być ujemna. "
            << "Transakcja przerwana.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num > 0)
    {
        cout << "Liczba sprzedawanych udziałów nie może być ujemna. "
            << "Transakcja przerwana.\n";
    }
    else if (num > shares)
    {
        cout << "Nie możesz sprzedać więcej udziałów, niż posiadasz! "
            << "Transakcja przerwana.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}


std::ostream & operator<<(std::ostream & os, const Stock & st){
  using std::ios_base;
  // ustawienie formatu na #.###
  ios_base::fmtflags orig =
      os.setf(ios_base::fixed, ios_base::floatfield);
  std::streamsize prec = os.precision(3);
  os << "Spółka: " << st.company
      << "  Liczba udziałów: " << st.shares << '\n';
  // ustawienie formatu na #.##
  os.precision(2);

  os << "  Cena udziału: " << st.share_val << " zł"
      << "  Łączna wartość udziałów: " << st.total_val << " zł" << '\n';
  // przywrócenie pierwotnego formatu
  os.setf(orig, ios_base::floatfield);
  os.precision(prec);

  return os;
}


const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}
