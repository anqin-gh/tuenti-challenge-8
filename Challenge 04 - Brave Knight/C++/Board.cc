#include "Board.h"

Board::Board()
	:	n_(), 
		m_(), 
		grid_(),
		pr_(),
		k_(),
		d_()
{}

Board::Board(int n, int m)
	:	n_(n), 
		m_(m), 
		grid_(n_, V<char>(m_)),
		pr_(),
		k_(),
		d_()
{}

void Board::InsertIntoGrid(P position, char c){
	grid_[position.x][position.y] = c;
}

P Board::GetPrincess(){
	return pr_;
}

void Board::SetPrincess(P position){
	pr_ = position;
}

P Board::GetKnight(){
	return k_;
}

void Board::SetKnight(P position){
	k_ = position;
}

P Board::GetDestination(){
	return d_;
}

void Board::SetDestination(P position){
	d_ = position;
}

bool Board::Valid(P p){
	return (p.x >= 0) and (p.x < n_) and (p.y >= 0) and (p.y < m_) and (grid_[p.x][p.y] != '#');
}

int Board::BFS(P start, P end){
	V<V<int>> dist(n_, V<int>(m_, -1));
	dist[start.x][start.y] = 0;
	std::queue<P> que;
	que.push(start);
	while (!que.empty()){
		P p = que.front();
		que.pop();
		if (p.x == end.x and p.y == end.y){
			return dist[end.x][end.y];
		}
		for (P dir : kDirs){
			if (grid_[p.x][p.y] == '*') dir = dir + dir;
			P q = p + dir;
			if (Valid(q)){
				if (dist[q.x][q.y] == -1){
					dist[q.x][q.y] = dist[p.x][p.y] + 1;
					que.push(q);
				}
			}
		}
	}
	return -1;
}