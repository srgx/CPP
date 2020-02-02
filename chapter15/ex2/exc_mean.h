// exc_mean.h -- klasy wyjątków dla funkcji hmean() i gmean()
#include <iostream>
#include <stdexcept>

class bad_hmean : public std::logic_error
{
    public:
        bad_hmean() : logic_error(""){}
        const char * what(){ return "a nie może być równe -b"; }
};


class bad_gmean : public std::logic_error
{
    public:
        bad_gmean() : logic_error("") {}
        const char * what(){ return "Liczby powinny być większe lub równe 0"; }

};
