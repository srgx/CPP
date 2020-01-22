#ifndef STONEWT__H__
#define STONEWT__H__

class Stonewt{
  public:
    enum Mode {KAM,FUNB,FUNZ};
  private:
    enum {Lbs_per_stn = 14};
    int stone;
    double pds_left;
    double pounds;
    Mode mode;
  public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void SetMode(Mode m);
    Stonewt operator+(const Stonewt & s)const;
    Stonewt operator-(const Stonewt & s)const;
    Stonewt operator*(double mult)const;


    bool operator>(const Stonewt & s)const;
    bool operator>=(const Stonewt & s)const;
    bool operator<(const Stonewt & s)const;
    bool operator<=(const Stonewt & s)const;
    bool operator!=(const Stonewt & s)const;
    bool operator==(const Stonewt & s)const;


    friend  Stonewt operator*(double mult,const Stonewt & s){ return s * mult; }
    friend std::ostream & operator<<(std::ostream & os, const Stonewt & s);
};

#endif
