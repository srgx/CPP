#ifndef COW__H__
#define COW__H__

class Cow{
  public:
    static const int ArSize = 20;
  private:
    char name[ArSize];
    char * hobby;
    double weight;
  public:
    Cow();
    Cow(const char * nm, const char * ho, double wt);
    Cow(const Cow & c);
    ~Cow();
    Cow & operator=(const Cow & c);
    void SetHobby(const char * nm);
    void ShowCow() const;
};

#endif
