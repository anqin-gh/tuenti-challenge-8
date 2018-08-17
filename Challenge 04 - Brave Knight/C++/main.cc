#include <iostream>
#include <string>
#include <vector>

#include "P.h"
#include "Board.h"

template<typename T> using V = std::vector<T>;

int main(){
    int c;
    std::cin >> c;
    for (int i = 1; i <= c; ++i){
        int n, m;
        std::cin >> n >> m;
        Board board(n, m);
        for (int j = 0; j < n; ++j){
        	for (int k = 0; k < m; ++k){
        		char input_char;
        		std::cin >> input_char;
        		P p(j, k);
        		board.InsertIntoGrid(p, input_char);
        		// TODO: Refactor this with an interface
        		if (input_char == 'P') board.SetPrincess(p);
        		if (input_char == 'S') board.SetKnight(p);
        		if (input_char == 'D') board.SetDestination(p);
        	}
        }
        P pr = board.GetPrincess();
        P k = board.GetKnight();
        P d = board.GetDestination();
        int a = board.BFS(k, pr);
        int b = board.BFS(pr, d);
        std::cout << "Case #" << i << ": ";
        if (a < 0 or b < 0) std::cout << "IMPOSSIBLE" << std::endl;
        else std::cout << a+b << std::endl;
    }
    return 0;
}