// dma.cpp -- metody klas

#include "dma.h"
#include <cstring>


// metody klasy baseDMA
baseDMA::baseDMA(const char * l, int r)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA & rs)
{
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

baseDMA::~baseDMA()
{
    delete [] label;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if (this == &rs)
        return *this;
    delete [] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
    os << "Etykietka: " << rs.label << std::endl;
    os << "Klasa: " << rs.rating << std::endl;
    return os;
}

// metody klasy lacksDMA
lacksDMA::lacksDMA(const char * c, const char * l, int r)
: baseDMA(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs)
: baseDMA(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
    os << (const baseDMA &) ls;
    os << "Kolor: " << ls.color << std::endl;
    return os;
}

// metody klasy hasDMA
hasDMA::hasDMA(const char * s, const char * l, int r)
: baseDMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const baseDMA & rs)
: baseDMA(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs)
: baseDMA(hs) // wywołuje konstruktor kopiujący klasy bazowej
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return *this;
    baseDMA::operator=(hs); // kopiuje dane klasy bazowej
    delete [] style; // przygotowanie do nowego stylu
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
    os << (const baseDMA &) hs;
    os << "Styl: " << hs.style << std::endl;
    return os;
}

abstractBaseDMA::~abstractBaseDMA(){
}

void baseDMA::View(){
  std::cout << "Etykietka: " << label << std::endl;
  std::cout << "Klasa: " << rating << std::endl;
}

void lacksDMA::View(){
  std::cout << (const baseDMA &)*this;
  std::cout << "Kolor: " << color << std::endl;
}

void hasDMA::View(){
  std::cout << (const baseDMA &)*this;
  std::cout << "Styl: " << style << std::endl;
}
