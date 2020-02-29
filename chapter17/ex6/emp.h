#ifndef EMP__H__
#define EMP__H__
#include <iostream>
#include <string>
#include <fstream>

using std::string; using std::ostream; using std::ofstream; using std::ifstream;

enum classkind{Employee, Manager, Fink, Highfink};

class abstr_emp{
private:
  string fname;
  string lname;
  string job;
public:
  // constructors
  abstr_emp() : fname("Jan"), lname("Kowalski"), job("Nauczyciel"){}
  abstr_emp(const string & fn, const string & ln, const string & j)
  : fname(fn), lname(ln), job(j){}

  // methods
  virtual void ShowAll()const;
  virtual void WriteAll(ofstream & fout)const;
  virtual void SetAll();
  virtual void GetAll(std::ifstream & fin);
  virtual classkind Type()const;

  friend ostream & operator<<(ostream & os,const abstr_emp & e);
  virtual ~abstr_emp() = 0;
};

class employee : public abstr_emp{
public:
  employee(){}
  employee(const string & fn, const string & ln, const string & j)
  : abstr_emp(fn,ln,j){}
};

class manager : virtual public abstr_emp{
private:
  int inchargeof;
protected:
  int InChargeOf()const{ return inchargeof; }
  int & InChargeOf(){ return inchargeof; }
  void Data()const;
  void WriteData(ofstream & fout)const;
  void Set();
  void Get(ifstream & fin);
public:

  // constructors
  manager() : inchargeof(0) {}
  manager(const string & fn, const string & ln, const string & j, int ico)
  : abstr_emp(fn,ln,j), inchargeof(ico) {}
  manager(const abstr_emp & e, int ico);

  // methods
  virtual void ShowAll()const override;
  virtual void WriteAll(ofstream & fout)const override;
  virtual void SetAll()override;
  virtual void GetAll(ifstream & fin)override;
  virtual classkind Type()const override;
};


class fink : virtual public abstr_emp{
  private:
    string reportsto;
  protected:
    const string ReportsTo()const{ return reportsto; }
    string & ReportsTo() { return reportsto; }
    void Data()const;
    void WriteData(ofstream & fout)const;
    void Set();
    void Get(ifstream & fin);
  public:
    // constructors
    fink() : reportsto("brak"){}
    fink(const string & fn, const string & ln, const string & j, const string & rpo)
    : abstr_emp(fn,ln,j), reportsto(rpo){}
    fink(const abstr_emp & e, const string & rpo);

    // methods
    virtual void ShowAll()const override;
    virtual void WriteAll(ofstream & fout)const override;
    virtual void SetAll()override;
    virtual void GetAll(ifstream & fin)override;
    virtual classkind Type()const override;
};


class highfink : public manager, public fink{
public:
  // constructors
  highfink(){}
  highfink(const string & fn, const string & ln, const string & j, const string & rpo, int ico)
  : abstr_emp(fn,ln,j), manager(fn,ln,j,ico), fink(fn,ln,j,rpo){}
  highfink(const abstr_emp & e, const string & rpo, int ico);
  highfink(const manager & m, const string & rpo);

  // methods
  virtual void ShowAll()const override;
  virtual void WriteAll(ofstream & fout)const override;
  virtual void SetAll()override;
  virtual void GetAll(ifstream & fin)override;
  virtual classkind Type()const override;
};

#endif
