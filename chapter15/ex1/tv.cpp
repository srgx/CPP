// tv.cpp -- metody klasy Tv (metody klasy Remote są inline)
#include <iostream>
#include "tvfm.h"

bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}

bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "Telewizor jest " << (state == Off ? "Wyłączony" : "Włączony") << endl;
    if (state == On)
    {
        cout << "Głośność = " << volume << endl;
        cout << "Program = " << channel << endl;
        cout << "Tryb = "
            << (mode == Antenna ? "antena" : "kabel") << endl;
        cout << "Wejście = "
            << (input == TV ? "TV" : "DVD") << endl;
    }
}

void Tv::change_remote_modetype(Remote & r){
  if(state){ r.modeType ^= 1; }
}

void Remote::show_mode_type(){
  std::cout << "Tryb "
  << (modeType==Normal ? "Normalny" : "Interaktywny") << std::endl;
}
