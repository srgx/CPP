#ifndef CD__H__
#define CD__H__

class Cd{
private:
  char * performers;
  char * label;
  int selections;
  double playtime;
public:
  Cd(const char * s1, const char * s2, int n, double x);
  Cd(const Cd & d);
  Cd();
  virtual ~Cd();
  virtual void ModifyObject();
  virtual void Report() const;
  Cd & operator=(const Cd & d);
};

#endif
