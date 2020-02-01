//use_tv.cpp -- używa klas Tv oraz Remote
#include <iostream>
#include "tvfm.h"

int main()
{
    using std::cout;
    Tv s42;
    cout << "Początkowe ustawienia telewizora 42\":\n";
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout << "\nNowe ustawienia telewizora 42\":\n";
    s42.settings();

    Remote grey;

    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    cout << "\nUstawienia telewizora 42\" po użyciu pilota:\n";
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    cout << "\nUstawienia telewizora 58\"\n";
    s58.settings();
    cout << "---------------------------------\n";
    cout << "Tryb pilota: ";
    grey.show_mode_type(); // Normalny
    Tv s66; s66.settings();
    s66.change_remote_modetype(grey);
    cout << "Tryb pilota: ";
    grey.show_mode_type(); // Normalny

    cout << "Włączenie telewizora\n";
    grey.onoff(s66);
    s66.change_remote_modetype(grey);
    cout << "Tryb pilota: ";
    grey.show_mode_type(); // Interaktywny
    s66.change_remote_modetype(grey);
    cout << "Tryb pilota: ";
    grey.show_mode_type(); // Normalny

    cout << "Koniec\n";
}
