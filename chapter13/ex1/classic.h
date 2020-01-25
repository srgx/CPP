#ifndef CLASSIC__H__
#define CLASSIC__H__
#include "cd.h"

class Classic : public Cd{
private:
  char main[50];
public:
  Classic(const char * s1, const char * s2, const char * s3, int n, double x);
  Classic();
  void ChangeLetter();
  void Report() const override;
};

#endif
