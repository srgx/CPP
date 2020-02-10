// vect3.cpp -- użycie funkcji biblioteki STL
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review {
    std::string title;
    int rating;
    float price;
};

bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool worseThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool cheaperThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool FillReview(std::shared_ptr<Review> & rr);
void ShowReview(const std::shared_ptr<Review> & rr);
void ShowMenu();
void ShowTitle();

int main()
{
    using namespace std;

    vector<shared_ptr<Review>>books;

    shared_ptr<Review> temp;
    while (FillReview(temp))
        books.push_back(temp);


    if (books.size() > 0)
    {

        vector<shared_ptr<Review>>byTitle = books;
        vector<shared_ptr<Review>>byPrice = books;
        vector<shared_ptr<Review>>byRating = books;

        sort(byTitle.begin(), byTitle.end());
        sort(byPrice.begin(), byPrice.end(), cheaperThan);
        sort(byRating.begin(), byRating.end(), worseThan);

        cout << "Dziękuję. Podałeś "
            << books.size() << " ocen książek.\n";


        ShowMenu();

        std::string c; getline(std::cin,c);

        while(c!="k"){
          if(c=="w"){
            cout << "Kolejność wprowadzania\n";
            ShowTitle();
            for_each(books.begin(), books.end(), ShowReview);
          }else if(c=="a"){
            cout << "Alfabetycznie\n";
            ShowTitle();
            for_each(byTitle.begin(), byTitle.end(), ShowReview);
          }else if(c=="o"){
            cout << "Ocena rosnąco\n";
            ShowTitle();
            for_each(byRating.begin(), byRating.end(), ShowReview);
          }else if(c=="m"){
            cout << "Ocena malejąco\n";
            ShowTitle();
            for_each(byRating.rbegin(), byRating.rend(), ShowReview);
          }else if(c=="c"){
            cout << "Cena rosnąco\n";
            ShowTitle();
            for_each(byPrice.begin(), byPrice.end(), ShowReview);
          }else if(c=="z"){
            cout << "Cena malejąco\n";
            ShowTitle();
            for_each(byPrice.rbegin(), byPrice.rend(), ShowReview);
          }else{
            cout << "Nieprawidłowa opcja. Do widzenia.\n";
            break;
          }
          cout << "------------------------------\n";
          getline(std::cin,c);
        }
    }
    else
        cout << "Brak danych. ";
    cout << "Koniec.\n";


    return 0;
}

bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worseThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
    if (r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool cheaperThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2){
  if(r1->price < r2->price)
    return true;
  else
    return false;
}

bool FillReview(std::shared_ptr<Review> & rr)
{
    rr = (std::shared_ptr<Review>)new Review;
    std::cout << " Wpisz tytuł książki (koniec, aby zakończyć): ";
    std::getline(std::cin, rr->title);
    if (rr->title == "koniec")
        return false;
    std::cout << "Wpisz ocenę: ";
    std::cin >> rr->rating;
    if (!std::cin)
        return false;

    while (std::cin.get() != '\n')
        continue;

    std::cout << "Wpisz cenę: ";
    std::cin >> rr->price;

    if (!std::cin)
        return false;

    while (std::cin.get() != '\n')
        continue;

    return true;
}

void ShowReview(const std::shared_ptr<Review> & rr)
{
    std::cout << rr->rating << "\t"
              << rr->title << "\t"
              << rr->price << std::endl;
}

void ShowMenu(){
  using std::cout;
  cout << "W jakiej kolejności wyświetlić dane?\n";
  cout << "w) wprowadzanie\t";
  cout << "a) alfabet\n";
  cout << "o) ocena ros.\t";
  cout << "m) ocena mal.\n";
  cout << "c) cena ros.\t";
  cout << "z) cena mal.\n";
  cout << "k) koniec\n";
}

void ShowTitle(){
  std::cout << "Ocena\tTytuł\tCena\n";
}
