// #ifdef CH07_H
#define CH07_H

#include <iostream>
#include <string>

using namespace std;
class Sales_Data
{
public:
    Sales_Data() = default; // 默认构造函数
    explicit Sales_Data(const string &s): bookNo(s) {};
    explicit Sales_Data(const string &s, unsigned int u, double p) : bookNo(s), units_sold(u), revenue(p) {};
    double avg_price() const
    {
        return units_sold ? revenue / units_sold : 0;
    }

    Sales_Data &combine(const Sales_Data &rhs)
    {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }

    string isbn() const
    {
        return bookNo;
    }

private:
    string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

// #endif