#include <iostream>
#include "stonewt.h"

using std::cout;

Stonewt::Stonewt(double lbs){
  stone = int(lbs) / Lbs_per_stn;
  pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
  pounds = lbs;
  mode = KAM;
}

Stonewt::Stonewt(int stn, double lbs){
  stone = stn;
  pds_left = lbs;
  pounds = stn * Lbs_per_stn + lbs;
  mode = KAM;
}

Stonewt::Stonewt(){
  stone = pounds = pds_left = 0;
  mode = KAM;
}

Stonewt::~Stonewt(){
}

Stonewt Stonewt::operator+(const Stonewt & s)const{
  return Stonewt(pounds+s.pounds);
}

Stonewt Stonewt::operator-(const Stonewt & s)const{
  return Stonewt(pounds-s.pounds);
}

Stonewt Stonewt::operator*(double mult)const{
  return Stonewt(pounds*mult);
}


void Stonewt::SetMode(Mode m){
  if(m==KAM||m==FUNZ||m==FUNB){
    mode = m;
  }else{
    cout << "Nieprawidłowy argument SetMode()\n";
  }
}

std::ostream & operator<<(std::ostream & os, const Stonewt & s){
  if(s.mode==Stonewt::KAM){
    os << s.stone << " kamieni, " << s.pds_left << " funtów";
  }else if(s.mode==Stonewt::FUNZ){
    os << s.pounds << " funtów";
  }else if(s.mode==Stonewt::FUNB){
    os << int(s.pounds) << " funtów";
  }else{
    os << "Niepoprawny tryb reprezentacji obiektu\n";
  }
}
