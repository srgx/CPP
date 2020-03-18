// functor.cpp -- używanie funktorów
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

auto outint = [](int n){ std::cout << n << " "; };

int main()
{
    using std::list;
    using std::cout;
    using std::endl;

    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    list<int> yadayada(vals, vals + 10);
    list<int> etcetera(vals, vals + 10);

    // w C++11 można alternatywnie użyć:
    // list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    // list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    cout << "Oryginalne listy:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;

    yadayada.remove_if([](int t){ return [t](int v){ return v > t; }; }(100));
    etcetera.remove_if([](int t){ return [t](int v){ return v > t; }; }(200));

    cout << "Przycięte listy:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;

    return 0;
}
