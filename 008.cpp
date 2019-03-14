#include<iostream>
#include<vector>
#include<set>
#include<string>

using namespace std;
#define inf 0x3f3f3f3f
#define ll long long

int n = 0;

void print(vector<vector<int>> &board){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void safeFill(vector<vector<int>> &board, int x, int y, int tf){
	if(x >= 0 && x < n && y >= 0 && y < n && board[x][y] != tf && board[x][y] != 2)
		board[x][y] = tf;
}

void filler(vector<vector<int>> &board, int x, int y, int tf){
	safeFill(board, x, y, 2);
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

int whatsOnThisLine(vector<vector<int>> &board, int l){
	int openSlots = 0;
	for(int i = 0; i < n; i++){
		if(board[l][i] == 2)
			return 2;
		if(board[l][i] == 1)
			openSlots = 1;
	}
	return openSlots;
}

set<string> sol;

void queens(vector<vector<int>> &board, int q){
	//print(board);
	if(q == n){
		string solu = "";
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(board[i][j] == 2){
					solu += to_string(j+1) + " ";
					break;
				}
			}
		}
		sol.insert(solu);
		return;
	}
	for(int i = 0; i < n; i++){
		if(whatsOnThisLine(board, i) == 1){//there are open slots and no queen
			for(int j = 0; j < n; j++){
				if(board[i][j]){
					vector<vector<int>> newBoard;
					newBoard = board;
					filler(newBoard, i, j, 0);
					queens(newBoard, q+1);
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int x0 = 0, y0 = 0;
	while(cin >> n){
		cin >> x0 >> y0;
		x0--; y0--;
		vector<vector<int>> board(n, vector<int>(n, 1));
		filler(board, x0, y0, 0);
		queens(board, 1);
		cout << "Solution" << endl;
		for(auto i : sol){
			cout << i << endl;
		}
		sol.clear();
	}
	return 0;
}
