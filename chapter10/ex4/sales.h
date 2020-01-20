#ifndef SALES__H__
#define SALES__H__

namespace SALES{
  const int QUARTERS = 4;
  class Sales{
    private:
      double m_sales[QUARTERS];
      double m_average;
      double m_max;
      double m_min;
    public:
      Sales();
      Sales(const double ar[],int n);
      void Set();
      void Show()const;
  };
}

#endif
