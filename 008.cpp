#include<iostream>
#include<vector>

using namespace std;
#define inf 0x3f3f3f3f
#define ll long long

int n = 0;

void print(vector<vector<bool>> &board){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void safeFill(vector<vector<bool>> &board, int x, int y, bool tf){
	if(x >= 0 && x < n && y >= 0 && y < n && board[x][y] != tf)
		board[x][y] = tf;
}

void filler(vector<vector<bool>> &board, int x, int y, bool tf){
	safeFill(board, x, y, tf);
	for(int i = 0; i < n; i++){
		safeFill(board, x+i, y+i, tf);//x
		safeFill(board, x+i, y-i, tf);
		safeFill(board, x-i, y+i, tf);
		safeFill(board, x-i, y-i, tf);
		safeFill(board, x  , y+i, tf);//|
		safeFill(board, x  , y-i, tf);
		safeFill(board, x+i, y  , tf);//-
		safeFill(board, x-i, y  , tf);
	}
}

void queens(vector<vector<bool>> &board, int q, vector<int> &sol){
	if(q == n){
		for(auto i : sol)
			cout << i+1 << " ";
		cout << endl;
	}
	for(int i = 0; i < n; i++){
		if(board[i][q]){
			sol.push_back(i);
			vector<vector<bool>> newBoard;
			newBoard = board;
			filler(newBoard, i, q, 0);
			queens(newBoard, q+1, sol);
			sol.pop_back();
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int x0 = 0, y0 = 0;
	while(cin >> n){
		cin >> x0 >> y0;
		x0--; y0--;
		vector<vector<bool>> board(n, vector<bool>(n, 1));
		vector<int> sol;
		sol.push_back(x0);
		filler(board, x0, y0, 0);
		cout << "Solution" << endl;
		queens(board, 1, sol);
	}
	return 0;
}
