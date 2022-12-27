#include <iostream>
#include <string>

using namespace std;

class Date
{
    int day, month, year;

public:
    Date() {}
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
};

class Record
{
    int id;
    Date date;

public:
    Record(int id, Date date)
    {
        this->id = id;
        this->date = date;
    }
};

int main()
{
    return 0;
}