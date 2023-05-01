#pragma once
#ifndef _CUSTOMER_H_

class Customers
{
    static int timer;
private:
    int servicetime;
    long arrivetime;
public:
    Customers() :servicetime(0), arrivetime(0) {};
    void set(long when);
    long when() const;
    int stime() const;
}; 

#endif // !_CUSTOMER_H_