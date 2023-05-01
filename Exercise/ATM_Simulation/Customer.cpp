#include <iostream>
#include "Customer.h"
#include "QUEUEMY.h"
#include <cstdlib>
#include <ctime>

void Customers::set(long when)
{
	arrivetime = when;
	servicetime = std::rand() % 3 + 1;
}
long Customers::when() const
{
	return arrivetime;
}
int Customers::stime() const
{
	return servicetime;
}


