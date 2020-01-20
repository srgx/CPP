#ifndef RACHUNEK__H__
#define RACHUNEK__H__

class Rachunek{
  private:
    std::string nazwisko;
    std::string numer;
    float saldo;
  public:
    Rachunek(const std::string & str, const std::string & nr, float sld);
    Rachunek();
    void Pokaz() const;
    void Przyjmij(float ile);
    void Wydaj(float ile);
};


#endif
