#ifndef P_H_
#define P_H_

#include <iostream>

struct P {
	int x, y;
	P();
	P(int, int);
};

std::ostream& operator<<(std::ostream& os, P p);
P operator+(P a, P b);


#endif // P_H_