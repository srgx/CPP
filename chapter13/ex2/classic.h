#ifndef CLASSIC__H__
#define CLASSIC__H__
#include "cd.h"

class Classic : public Cd{
private:
  char * main;
public:
  Classic(const char * s1, const char * s2, const char * s3, int n, double x);
  Classic();
  ~Classic()override;
  Classic(const Classic & c);
  void ModifyObject()override;
  void Report() const override;
  Classic & operator=(const Classic & d);
};

#endif
