#ifndef GOLF__H__
#define GOLF__H__

const int Len = 40;
class golf{
  private:
    char m_fullname[Len];
    int m_handicap;
  public:
    golf();
    golf(const char * name, int hc);
    int set();
    void handicap(int hc);
    void show() const;
};






#endif
