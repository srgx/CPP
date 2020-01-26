// dma.h -- dziedziczenie i dynamiczny przydział pamięci
#ifndef DMA_H_
#define DMA_H_
#include <iostream>


class abstractBaseDMA{
  public:
    virtual void View() = 0;
    virtual ~abstractBaseDMA();
};

// klasa bazowa korzystająca z dynamicznego przydziału pamięci
class baseDMA : public abstractBaseDMA
{
    private:
        char * label;
        int rating;

    public:
        baseDMA(const char * l = "brak", int r = 0);
        baseDMA(const baseDMA & rs);
        virtual ~baseDMA();
        baseDMA & operator=(const baseDMA & rs);

        virtual void View();

        friend std::ostream & operator<<(std::ostream & os,
                const baseDMA & rs);
};

// klasa pochodna bez dynamicznego przydziału pamięci
// nie jest potrzebny destruktor
// używa niejawnego konstruktora kopiującego
// używa niejawnego operatora przypisania
class lacksDMA : public baseDMA
{
    private:
        enum { COL_LEN = 40 };
        char color[COL_LEN];
    public:
        lacksDMA(const char * c = "brak", const char * l = "brak",
                int r = 0);

        void View() override;
        lacksDMA(const char * c, const baseDMA & rs);
        friend std::ostream & operator<<(std::ostream & os,
                const lacksDMA & rs);
};

// klasa pochodna z dynamicznym przydziałem pamięci
class hasDMA : public baseDMA
{
    private:
        char * style;
    public:
        hasDMA(const char * s = "brak", const char * l = "brak",
                int r = 0);
        hasDMA(const char * s, const baseDMA & rs);
        hasDMA(const hasDMA & hs);
        ~hasDMA() override;

        void View() override;
        hasDMA & operator=(const hasDMA & rs);
        friend std::ostream & operator<<(std::ostream & os,
                const hasDMA & rs);
};

#endif
