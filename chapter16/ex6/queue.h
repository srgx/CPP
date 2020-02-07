// queue.h -- interfejs kolejki
#ifndef QUEUE_H_
#define QUEUE_H_

// ta kolejka będzie przechowywała elementy klasy Customer
class Customer
{
    private:
        long arrive;     // czas dołączenia klienta do kolejki
        int processtime; // czas obsługi klienta
    public:
        Customer() { arrive = processtime = 0; }
        void set(long when);
        long when() const { return arrive; }
        int ptime() const { return processtime; }
};

typedef Customer Item;

#endif
