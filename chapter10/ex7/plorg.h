#ifndef PLORG__H__
#define PLORG__H__

const int LIMIT = 20;

class Plorg{
  private:
    char imie[LIMIT];
    int sytosc;
  public:
    Plorg(const char * im = "Plorga", int syt = 50);
    void ustawSytosc(int st);
    void przedstawSie();
};

#endif
