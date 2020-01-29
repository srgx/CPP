#ifndef PERSON__H__
#define PERSON__H__

class Person{
private:
  std::string fname;
  std::string lname;
public:
  Person() : fname("brak"), lname("brak") {}
  Person(const char * first, const char * last) : fname(first), lname(last) {}
  virtual void Show()const;
  virtual void Set();
  virtual ~Person(){};
};

class Gunslinger : virtual public Person{
private:
  float time;
  int scores;
public:
  Gunslinger() : Person(), time(0), scores(0) {}
  Gunslinger(const char * first, const char * , float t, int sc);
  void Show()const override;
  void Set() override;
  float Draw()const;
};

class Card{
public:
  enum Suit{ HEARTS, CLUBS, SPADES, DIAMONDS };
private:
  int number;
  Suit suit;
public:
  Card(int num = 1,Suit st = CLUBS);
  void Show()const;
};

class PokerPlayer : virtual public Person{
  public:
    PokerPlayer() : Person(){}
    PokerPlayer(const char * first, const char * last);
    Card Draw()const;
};

class BadDude : public Gunslinger, public PokerPlayer{
public:
  BadDude(){}
  BadDude(const char * first, const char * last, float t, float sc);
  float GDraw()const;
  Card CDraw()const;
  void Show()const override;
};

#endif
