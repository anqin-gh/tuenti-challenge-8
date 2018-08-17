#include "P.h"

P::P() : x(-1), y(-1){};
P::P(int a, int b) : x(a), y(b) {};

std::ostream& operator<<(std::ostream& os, P p){
	os << '{' << p.x << ", " << p.y << '}';
	return os;
}

P operator+(P a, P b){
	return {a.x+b.x, a.y+b.y};
}