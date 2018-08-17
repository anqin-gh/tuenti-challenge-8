#ifndef BOARD_H_
#define BOARD_H_

#include "P.h"
#include <iostream>
#include <vector>
#include <queue>

template<typename T> using V = std::vector<T>;

const V<P> kDirs = {
	{1, 2},
	{1, -2},
	{-1, 2},
	{-1, -2},
	{2, 1},
	{2, -1},
	{-2, 1},
	{-2, -1}
};

class Board {
	private:
		int n_, m_;
		V<V<char>> grid_;
		P pr_, k_, d_;
	public:
		Board();
		Board(int, int);
		void InsertIntoGrid(P, char);
		P GetPrincess();
		void SetPrincess(P);
		P GetKnight();
		void SetKnight(P);
		P GetDestination();
		void SetDestination(P);
		bool Valid(P p);
		int BFS(P, P);
};

#endif // BOARD_H_