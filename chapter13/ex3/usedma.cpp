// usebrass3.cpp -- polimorficzny przykład stosowania abstrakcyjnej klasy bazowej
// kompilować łącznie z acctacb.cpp
#include <iostream>
#include <string>
#include "dma.h"
const int CLIENTS = 4;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    abstractBaseDMA * p_clients[CLIENTS];
    std::string temp;
    int tempnum;
    char kind;
    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "Podaj etykietkę: ";
        getline(cin,temp);
        cout << "Podaj ocenę: ";
        cin >> tempnum;
        cout << "Wpisz 1 dla normalnego, "
            << "2 dla kolorowego lub 3 dla stylowego: ";
        while (cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
            cout <<"Wpisz 1, 2 lub 3: ";
        cin.get();
        if (kind == '1')
          p_clients[i] = new baseDMA(temp.c_str(), tempnum);
        else if(kind == '2'){
          std::string tempcolor;
          cout << "Podaj kolor: ";
          getline(cin,tempcolor);
          p_clients[i] = new lacksDMA(tempcolor.c_str(),temp.c_str(),tempnum);
        }
        else{
          std::string tempstyle;
          cout << "Podaj styl: ";
          getline(cin,tempstyle);
          p_clients[i] = new hasDMA(tempstyle.c_str(),temp.c_str(),tempnum);
        }
    }
    cout << endl;
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->View();
        cout << endl;
    }
    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i]; // zwolnienie pamięci
    }
    cout << "Gotowe.\n";
    return 0;
}
