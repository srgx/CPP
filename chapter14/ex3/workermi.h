// workermi.h -- hierarchia klas z użyciem dziedziczenia wielokrotnego
#ifndef WORKERMI_H_
#define WORKERMI_H_

#include <string>

template<class T>
class QueueTp{
private:
  struct Node { T item; Node * next; };
  static const int Q_SIZE = 10;
  Node * front;
  Node * rear;
  int items;
  const int qsize;
  QueueTp(const QueueTp & q) : qsize(0) {}
  QueueTp & operator=(const QueueTp & q) { return *this; }
public:
  QueueTp(int qs = Q_SIZE);
  ~QueueTp();
  bool isempty()const;
  bool isfull()const;
  int queuecount()const;
  bool enqueue(const T & item);
  bool dequeue(T & item);

};


template<class T>
QueueTp<T>::QueueTp(int qs){
  front = rear = nullptr;
  items = 0;
}

template<class T>
QueueTp<T>::~QueueTp(){
  Node * temp;
  while (front != nullptr)
  {
      temp = front;
      front = front->next;
      delete temp;
  }
}

template<class T>
bool QueueTp<T>::isempty() const
{
    return items == 0;
}

template<class T>
bool QueueTp<T>::isfull() const
{
    return items == qsize;
}

template<class T>
int QueueTp<T>::queuecount() const
{
    return items;
}

template<class T>
bool QueueTp<T>::enqueue(const T & item)
{
    if (isfull())
        return false;
    Node * add = new Node;

    add->item = item;
    add->next = nullptr;
    items++;
    if (front == nullptr)
        front = add;
    else
        rear->next = add;
    rear = add;
    return true;
}

template<class T>
bool QueueTp<T>::dequeue(T & item)
{
    if (front == nullptr)
        return false;
    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if (items == 0)
        rear = nullptr;
    return true;
}



class Worker // abstrakcyjna klasa bazowa
{
    private:
        std::string fullname;
        long id;
    protected:
        virtual void Data() const;
        virtual void Get();
    public:
        Worker() : fullname("brak"), id(0L) {}
        Worker(const std::string & s, long n)
            : fullname(s), id(n) {}
        virtual ~Worker() = 0; // funkcja czysto wirtualna
        virtual void Set() = 0;
        virtual void Show() const = 0;
};

class Waiter : virtual public Worker
{
    private:
        int panache;
    protected:
        void Data() const;
        void Get();
    public:
        Waiter() : Worker(), panache(0) {}
        Waiter(const std::string & s, long n, int p = 0)
            : Worker(s, n), panache(p) {}
        Waiter(const Worker & wk, int p = 0)
            : Worker(wk), panache(p) {}
        void Set();
        void Show() const;
};

class Singer : virtual public Worker
{
    protected:
        enum {inna, alt, kontralt, sopran,
            bas, baryton, tenor};
        enum {Vtypes = 7};
        void Data() const;
        void Get();
    private:
        static const char *pv[Vtypes]; // odpowiednik skali głosu w postaci ciągu znaków
        int voice;
    public:
        Singer() : Worker(), voice(inna) {}
        Singer(const std::string & s, long n, int v = inna)
            : Worker(s, n), voice(v) {}
        Singer(const Worker & wk, int v = inna)
            : Worker(wk), voice(v) {}
        void Set();
        void Show() const;
};

// dziedziczenie wielokrotne
class SingingWaiter : public Singer, public Waiter
{
    protected:
        void Data() const;
        void Get();
    public:
        SingingWaiter() {}
        SingingWaiter(const std::string & s, long n, int p = 0,
                int v = inna)
            : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
        SingingWaiter(const Worker & wk, int p = 0, int v = inna)
            : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
        SingingWaiter(const Waiter & wt, int v = inna)
            : Worker(wt), Waiter(wt), Singer(wt, v) {}
        SingingWaiter(const Singer & wt, int p = 0)
            : Worker(wt), Waiter(wt, p), Singer(wt) {}
        void Set();
        void Show() const;
};

#endif
