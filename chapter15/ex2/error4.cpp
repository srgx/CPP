// error4.cpp -- używa klas wyjątków
#include <iostream>
#include <cmath> // lub math.h; użytkownicy systemu UNIX mogą potrzebować opcji -lm
#include "exc_mean.h"
// prototypy funkcji
double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    //logic_error blabla;

    double x, y, z;

    cout << "Podaj dwie liczby: ";
    while (cin >> x >> y)
    {
        try {      // początek bloku try
            z = hmean(x, y);
            cout << "Średnia harmoniczna liczb " << x << " i " << y
                << " wynosi " << z << endl;
            z = gmean(x, y);
            cout << "Średnia geometryczna liczb " << x << " i " << y
                << " wynosi " << z << endl;
            cout << "Podaj kolejną parę liczb <w, aby wyjść>: ";
        }   // koniec bloku try
        catch (bad_hmean & bg)   // początek bloku catch
        {
            cout << bg.what() << endl;
            cout << "Spróbuj ponownie.\n";
            continue;
        }
        catch (bad_gmean & hg)
        {
            cout << hg.what() << endl;

            cout << "Niestety, to koniec zabawy.\n";
            break;
        } // koniec bloku catch
    }
    cout << "Koniec\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean();
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean();
    return std::sqrt(a * b);
}
