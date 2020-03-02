#ifndef STORE__H__
#define STORE__H__

class Store{
private:
  std::ofstream * of;
public:
  Store(std::ofstream & os);
  void operator()(const std::string & str);
};

#endif
