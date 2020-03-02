#include <fstream>
#include "store.h"


Store::Store(std::ofstream & os){
  of = &os;
}

void Store::operator()(const std::string & str){
  int len = str.size();
  of->write((char*)&len,sizeof(std::size_t));
  of->write(str.data(),len);
}
